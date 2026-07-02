# ==========================================
# 准备工作区：导入工具包
# ==========================================
import os
import cv2
import numpy as np
import torch
import lpips
from skimage.metrics import peak_signal_noise_ratio as psnr
from skimage.metrics import structural_similarity as ssim
from skimage.metrics import mean_squared_error as mse

# ================= 1. 初始化深度学习打分模型 =================
print("正在加载 LPIPS 视觉感知评价模型...")
loss_fn_alex = lpips.LPIPS(net='alex')
print("模型加载完成！\n")

# ================= 2. 核心平滑算子库 =================

# 算法A：双边滤波 (Bilateral Filter)
def filter_bilateral(T0, d=15, sigma_r=0.1, sigma_s=50.0):
    # 结合空间高斯权重与值域高斯权重的非线性平滑
    # 局限性：强对比边缘处极易产生梯度反转（光晕伪影）
    T0_32 = T0.astype(np.float32)
    T_bf = cv2.bilateralFilter(T0_32, d, sigma_r, sigma_s)
    return T_bf.astype(np.float64)

# 算法B：自适应引导滤波 (Adaptive Guided Filter) 【核心创新点】
def filter_guided_adaptive(I_guide, p_input, r=15, eps_base=0.01):
    # 1. 局部统计量计算：利用盒式滤波（积分图加速），时间复杂度严格为 O(N)
    mean_I = cv2.boxFilter(I_guide, cv2.CV_64F, (r, r))
    mean_p = cv2.boxFilter(p_input, cv2.CV_64F, (r, r))
    mean_Ip = cv2.boxFilter(I_guide * p_input, cv2.CV_64F, (r, r))
    cov_Ip = mean_Ip - mean_I * mean_p  # 计算局部协方差
    
    mean_II = cv2.boxFilter(I_guide * I_guide, cv2.CV_64F, (r, r))
    var_I = mean_II - mean_I * mean_I   # 计算引导图的局部方差
    
    # 2. 自适应正则化机制 (Adaptive Regularization)
    # 物理意义：边缘处 var_I 大 -> eps 变小 -> 强力保边；平坦处 var_I 小 -> eps 变大 -> 强力平滑
    eps_adaptive = eps_base / (var_I + 1e-4) 
    
    # 3. 求解局部线性回归系数 a 和 b (q_i = a_k * I_i + b_k)
    a = cov_Ip / (var_I + eps_adaptive)
    b = mean_p - a * mean_I
    
    # 4. 聚合窗口重叠区域的系数，防止块效应
    mean_a = cv2.boxFilter(a, cv2.CV_64F, (r, r))
    mean_b = cv2.boxFilter(b, cv2.CV_64F, (r, r))
    
    return mean_a * I_guide + mean_b

# ================= 3. 统一的低光增强框架 =================
def retinex_enhance(img_path, filter_type='guided'):
    img = cv2.imdecode(np.fromfile(img_path, dtype=np.uint8), cv2.IMREAD_COLOR)
    if img is None: return None, None, None
    I = img.astype(np.float64) / 255.0
    
    # 步骤一：初始光照估计 (RGB三通道最大值先验)
    # 假设局部光照强度至少等于最亮颜色通道的值，提供最紧致的光照下界
    T0 = np.max(I, axis=2)
    
    # 步骤二：光照图保边平滑 (剥离纹理，仅保留物理光照大尺度边界)
    if filter_type == 'bilateral':
        T_refined = filter_bilateral(T0)
    elif filter_type == 'guided':
        # 提取原图灰度图作为引导约束
        gray_guide = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY).astype(np.float64) / 255.0
        T_refined = filter_guided_adaptive(gray_guide, T0)
    else:
        T_refined = T0
        
    T_refined = np.clip(T_refined, 0.001, 1.0) # 阈值截断，防止后续除法溢出
    
    # 步骤三：Retinex 恢复与严格控制变量的 Gamma 补偿
    gamma = 0.6  # 恒定Gamma值，确保BF与GF面临完全相同的提亮尺度
    T_gamma = np.power(T_refined, gamma)
    T_gamma_3d = np.repeat(T_gamma[:, :, np.newaxis], 3, axis=2)
    
    # I(x) = R(x) * T(x) -> 恢复物理反射率 R(x)
    enhanced = I / T_gamma_3d
    enhanced = np.clip(enhanced, 0, 1)
    
    # 步骤四：基于照明权重的抗噪融合 (Illumination-aware NLM)
    enhanced_8u = (enhanced * 255).astype(np.uint8)
    denoised = cv2.fastNlMeansDenoisingColored(enhanced_8u, None, 10, 10, 7, 21)
    
    # 动态掩码：提亮幅度越大的极暗区域(T_gamma_3d越小)，分配越高的降噪权重 W_noise
    W_noise = 1 - T_gamma_3d
    final_result = (W_noise * denoised + (1 - W_noise) * enhanced_8u).astype(np.uint8)
    
    return final_result, (T0, T_refined), I

# ================= 4. ★ 高级评价指标计算 ★ =================
def calculate_sam(img1, img2):
    """计算光谱角映射 (SAM)，评估 Retinex 除法带来的色彩偏离。"""
    nom = np.sum(img1 * img2, axis=2)
    denom1 = np.sqrt(np.sum(img1**2, axis=2))
    denom2 = np.sqrt(np.sum(img2**2, axis=2))
    cos_theta = np.clip(nom / (denom1 * denom2 + 1e-8), -1.0, 1.0)
    return np.mean(np.arccos(cos_theta))

def calculate_loe(input_img, enhanced_img):
    """计算亮度顺序误差 (LOE)，评估是否破坏了真实物理环境的相对明暗顺序。"""
    I_ds = cv2.resize(input_img, (50, 50))
    E_ds = cv2.resize(enhanced_img, (50, 50))
    L_I = np.max(I_ds, axis=2).flatten()
    L_E = np.max(E_ds, axis=2).flatten()
    
    U_I = L_I[:, None] >= L_I[None, :]
    U_E = L_E[:, None] >= L_E[None, :]
    return np.sum(U_I ^ U_E) / len(L_I)

def calculate_ncc(img1, img2):
    """计算归一化互相关 (NCC)，评估增强前后图像全局分布的线性相关性。"""
    mean1, mean2 = np.mean(img1), np.mean(img2)
    nom = np.sum((img1 - mean1) * (img2 - mean2))
    denom = np.sqrt(np.sum((img1 - mean1)**2) * np.sum((img2 - mean2)**2)) + 1e-8
    return nom / denom

def calculate_all_metrics(restored, gt, original_input):
    """整合五大基础指标与三大低光专属指标"""
    if restored.shape != gt.shape:
        gt = cv2.resize(gt, (restored.shape[1], restored.shape[0]))
        
    res_f = restored.astype(np.float64) / 255.0
    gt_f = gt.astype(np.float64) / 255.0
    
    psnr_val = psnr(gt, restored)
    ssim_val = ssim(gt, restored, channel_axis=2)
    mse_val = mse(gt, restored)
    mae_val = np.mean(np.abs(res_f - gt_f))
    
    img_t = torch.from_numpy(restored).permute(2, 0, 1).unsqueeze(0).float() / 255.0 * 2 - 1
    gt_t = torch.from_numpy(gt).permute(2, 0, 1).unsqueeze(0).float() / 255.0 * 2 - 1
    with torch.no_grad():
        lpips_val = loss_fn_alex(img_t, gt_t).item()
        
    sam_val = calculate_sam(res_f, gt_f)        
    loe_val = calculate_loe(original_input, res_f) 
    ncc_val = calculate_ncc(res_f, gt_f)        
    
    return [psnr_val, ssim_val, mse_val, mae_val, lpips_val, sam_val, loe_val, ncc_val]

# ================= 5. 主程序与流程控制 =================
def main():
    # ★ 核心改动区域：适配实验要求的目录结构规范 ★
    
    # 假设本脚本存放在 src/ 目录下，获取 script_dir 为 src/
    script_dir = os.path.dirname(os.path.abspath(__file__))
    # 获取项目根目录 (src 的上一级)
    project_root = os.path.dirname(script_dir)
    
    # 【输入路径配置】（假设测试图片存在项目根目录的 data 文件夹下，你可以根据实际存放位置修改）
    # 如果你的图片依然在 src/samples 里，请将 project_root 改回 script_dir 即可。
    input_dir = os.path.join(project_root, 'samples', 'Train', 'Input')
    gt_dir = os.path.join(project_root, 'samples', 'Train', 'GT')
    
    if not os.path.exists(input_dir):
        print(f"错误: 找不到输入文件夹 '{input_dir}'。请检查数据集存放位置。")
        return

    # 【输出路径配置】遵循提交规范
    results_dir = os.path.join(project_root, 'results')
    intermediate_dir = os.path.join(results_dir, 'intermediate')  # 存放光照图、中间结果
    final_dir = os.path.join(results_dir, 'final')                # 存放最终增强图像
    
    # 创建规范目录
    os.makedirs(intermediate_dir, exist_ok=True)
    os.makedirs(final_dir, exist_ok=True)

    metrics_bf, metrics_gf = [], []
    img_names = [f for f in os.listdir(input_dir) if f.lower().endswith(('.png', '.jpg'))]
    
    for filename in img_names:
        print(f"\n--- 正在处理: {filename} ---")
        img_path = os.path.join(input_dir, filename)
        gt_path = os.path.join(gt_dir, filename)
        
        # 运行增强算法
        res_bf, maps_bf, original_I = retinex_enhance(img_path, filter_type='bilateral')
        res_gf, maps_gf, _ = retinex_enhance(img_path, filter_type='guided')
        
        if res_bf is None: continue
        
        # 1. 保存【最终结果】到 results/final/ 
        cv2.imencode('.png', res_bf)[1].tofile(os.path.join(final_dir, f"BF_{filename}"))
        cv2.imencode('.png', res_gf)[1].tofile(os.path.join(final_dir, f"GF_{filename}"))
        
        # 提取光照图用于可视化
        T0_vis = (maps_bf[0] * 255).astype(np.uint8)
        T_bf_vis = (maps_bf[1] * 255).astype(np.uint8)
        T_gf_vis = (maps_gf[1] * 255).astype(np.uint8)
        
        # 2. 保存【中间变量/光照图】到 results/intermediate/
        fname_noext = os.path.splitext(filename)[0]
        cv2.imencode('.png', T0_vis)[1].tofile(os.path.join(intermediate_dir, f"{fname_noext}_T0.png"))
        cv2.imencode('.png', T_bf_vis)[1].tofile(os.path.join(intermediate_dir, f"{fname_noext}_T_bf.png"))
        cv2.imencode('.png', T_gf_vis)[1].tofile(os.path.join(intermediate_dir, f"{fname_noext}_T_gf.png"))
        
        # 计算评价指标
        if os.path.exists(gt_path):
            gt_img = cv2.imdecode(np.fromfile(gt_path, dtype=np.uint8), cv2.IMREAD_COLOR)
            m_bf = calculate_all_metrics(res_bf, gt_img, original_I)
            m_gf = calculate_all_metrics(res_gf, gt_img, original_I)
            metrics_bf.append(m_bf)
            metrics_gf.append(m_gf)
            
            print(f"BF -> PSNR:{m_bf[0]:.2f}, SSIM:{m_bf[1]:.4f}, LOE:{m_bf[6]:.2f}, SAM:{m_bf[5]:.4f}")
            print(f"GF -> PSNR:{m_gf[0]:.2f}, SSIM:{m_gf[1]:.4f}, LOE:{m_gf[6]:.2f}, SAM:{m_gf[5]:.4f}")

    # 打印全局汇总表
    if metrics_bf and metrics_gf:
        avg_bf = np.mean(metrics_bf, axis=0)
        avg_gf = np.mean(metrics_gf, axis=0)
        print("\n" + "="*70)
        print("★ 实验结果总评对比表 (包含高级指标) ★")
        print(f"{'评价指标 (指标倾向)':<18} | {'双边滤波 (BF)':<18} | {'自适应引导滤波 (GF)':<18}")
        print("-" * 70)
        print(f"{'PSNR (↑更高越好)':<18} | {avg_bf[0]:<18.2f} | {avg_gf[0]:<18.2f}")
        print(f"{'SSIM (↑更高越好)':<18} | {avg_bf[1]:<18.4f} | {avg_gf[1]:<18.4f}")
        print(f"{'NCC  (↑接近1最好)':<18} | {avg_bf[7]:<18.4f} | {avg_gf[7]:<18.4f}")
        print(f"{'MSE  (↓更低越好)':<18} | {avg_bf[2]:<18.2f} | {avg_gf[2]:<18.2f}")
        print(f"{'MAE  (↓更低越好)':<18} | {avg_bf[3]:<18.2f} | {avg_gf[3]:<18.2f}")
        print(f"{'LPIPS(↓感知失真越低越好)':<18} | {avg_bf[4]:<18.4f} | {avg_gf[4]:<18.4f}")
        print(f"{'SAM  (↓色彩偏离越小越好)':<18} | {avg_bf[5]:<18.4f} | {avg_gf[5]:<18.4f}")
        print(f"{'LOE  (↓亮度顺序保持越好)':<18} | {avg_bf[6]:<18.2f} | {avg_gf[6]:<18.2f}")
        print("="*70)

if __name__ == "__main__":
    main()