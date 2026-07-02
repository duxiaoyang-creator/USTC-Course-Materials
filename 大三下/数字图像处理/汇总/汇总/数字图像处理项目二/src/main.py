import os
import glob
import cv2            
import numpy as np    
import pywt           
import matplotlib.pyplot as plt 

def evaluate_metrics(pred_edges, gt_edges):
    # 1. 强制二值化处理
    pred_bin = (pred_edges > 127).astype(np.uint8)
    gt_bin = (gt_edges > 127).astype(np.uint8)
    
    # 2. 计算混淆矩阵中的关键元素 (TP, FP, FN)
    TP = np.sum((pred_bin == 1) & (gt_bin == 1))
    FP = np.sum((pred_bin == 1) & (gt_bin == 0))
    FN = np.sum((pred_bin == 0) & (gt_bin == 1))
    
    # 3. 计算指标并防止除以 0 的崩溃情况
    precision = TP / (TP + FP) if (TP + FP) > 0 else 0.0
    recall = TP / (TP + FN) if (TP + FN) > 0 else 0.0
    f1_score = (2 * precision * recall) / (precision + recall) if (precision + recall) > 0 else 0.0
    
    return precision, recall, f1_score

def basic_wavelet_edge(img_gray):
    """基础方法：使用 Haar 小波进行单尺度分解 + 大津法二值化"""
    # 1. 2D 离散小波变换 (DWT)
    coeffs = pywt.dwt2(img_gray, 'haar')
    cA, (cH, cV, cD) = coeffs
    
    # 2. 计算梯度幅值 (Gradient Magnitude)
    magnitude = np.sqrt(cH**2 + cV**2 + cD**2)
    
    # 3. 归一化 (Normalization)
    magnitude = cv2.normalize(magnitude, None, 0, 255, cv2.NORM_MINMAX).astype(np.uint8)
    
    # 4. 尺寸还原
    magnitude_resized = cv2.resize(magnitude, (img_gray.shape[1], img_gray.shape[0]))
    
    # 5. Otsu 自适应二值化
    _, edges = cv2.threshold(magnitude_resized, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
    
    return magnitude_resized, edges

def advanced_wavelet_edge(img_gray):
    """改进方法：双边滤波去噪 + Sym4小波双尺度融合提取 + 形态学闭操作"""
    # 1. 保边滤波去噪 (Bilateral Filter)
    blur = cv2.bilateralFilter(img_gray, d=9, sigmaColor=75, sigmaSpace=75)
    
    # 2. 多尺度小波分解 (Multi-level DWT)
    coeffs = pywt.wavedec2(blur, 'sym4', level=2)
    # cA2: 第二层低频; (cH2, cV2, cD2): 第二层高频(深层宏观结构); (cH1, cV1, cD1): 第一层高频(浅层微观细节)
    cA2, (cH2, cV2, cD2), (cH1, cV1, cD1) = coeffs
    
    # 3. 提取 Level 1 (第一层) 细节幅值并上采样到原图尺寸
    mag1 = np.sqrt(cH1**2 + cV1**2 + cD1**2)
    mag1 = cv2.normalize(mag1, None, 0, 255, cv2.NORM_MINMAX).astype(np.uint8)
    mag1_res = cv2.resize(mag1, (img_gray.shape[1], img_gray.shape[0]))
    
    # 4. 提取 Level 2 (第二层) 结构幅值并上采样到原图尺寸
    mag2 = np.sqrt(cH2**2 + cV2**2 + cD2**2)
    mag2 = cv2.normalize(mag2, None, 0, 255, cv2.NORM_MINMAX).astype(np.uint8)
    mag2_res = cv2.resize(mag2, (img_gray.shape[1], img_gray.shape[0]))
    
    # 5. 跨尺度特征加权融合 (Feature Fusion)
    mag_fused = cv2.addWeighted(mag1_res, 0.6, mag2_res, 0.4, 0)
    
    # 6. 自适应二值化 (同基本方法)
    _, edges = cv2.threshold(mag_fused, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
    
    # 7. 形态学闭操作 (Morphological Closing)
    kernel = cv2.getStructuringElement(cv2.MORPH_CROSS, (3, 3))
    edges_refined = cv2.morphologyEx(edges, cv2.MORPH_CLOSE, kernel)
    
    return mag_fused, edges_refined

def main():
    # ---------------- 路径配置模块 ----------------
    base_dir = './samples'
    img_dir = os.path.join(base_dir, 'images')           # 原始图像目录
    gt_dir = os.path.join(base_dir, 'groundTruth')       # 人工标注的真实边缘目录
    out_dir = './output_results'                         # 实验结果图片保存目录
    
    if not os.path.exists(out_dir):
        os.makedirs(out_dir)  # 如果保存目录不存在则自动创建
        
    image_paths = glob.glob(os.path.join(img_dir, '*.jpg')) # 抓取所有的 .jpg 图片
    if not image_paths:
        print("未找到图片，请检查路径。")
        return

    # ---------------- 终端输出表头格式化 ----------------
    print("-" * 80)
    print(f"{'Image ID':<12} | {'Method':<10} | {'Precision':<10} | {'Recall':<10} | {'F1-Score':<10}")
    print("-" * 80)

    # ---------------- 核心批量处理循环 ----------------
    for img_path in image_paths:
        img_name = os.path.basename(img_path)
        base_name = os.path.splitext(img_name)[0]
        
        # 读取原图并转换为灰度图 (边缘检测不需要彩色信息，且小波变换针对单通道进行)
        img = cv2.imread(img_path)
        img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        
        # 分别运行两种算法获取幅值图和最终边缘图
        basic_mag, basic_edges = basic_wavelet_edge(img_gray)
        adv_mag, adv_edges = advanced_wavelet_edge(img_gray)
        
        # --------- 匹配并读取 Ground Truth ---------
        # 使用模糊匹配，防止 Ground Truth 名字有多余的前缀或后缀
        gt_search = glob.glob(os.path.join(gt_dir, f"{base_name}*bin*.png"))
        if not gt_search:
            print(f"[警告] 找不到 {base_name} 的 Ground Truth")
            continue
            
        gt_img = cv2.imread(gt_search[0], cv2.IMREAD_GRAYSCALE)
        
        # 安全机制：如果算法输出的图和 GT 尺寸差了几个像素，强行调整 GT 尺寸进行对齐，防止 numpy 报错
        if gt_img.shape != basic_edges.shape:
            gt_img = cv2.resize(gt_img, (basic_edges.shape[1], basic_edges.shape[0]))
            
        # 计算两种方法的评价指标
        b_p, b_r, b_f1 = evaluate_metrics(basic_edges, gt_img)
        a_p, a_r, a_f1 = evaluate_metrics(adv_edges, gt_img)
        
        # 打印到终端
        print(f"{base_name:<12} | {'Basic':<10} | {b_p:<10.4f} | {b_r:<10.4f} | {b_f1:<10.4f}")
        print(f"{'':<12} | {'Advanced':<10} | {a_p:<10.4f} | {a_r:<10.4f} | {a_f1:<10.4f}")
        print("-" * 80)
        
        # ==========================================
        # 生成学术对比可视化图版并保存
        # ==========================================
        # 设置画布大小：宽16英寸，高8英寸
        plt.figure(figsize=(16, 8))
        
        # subplot(231) 意味着：将画布分成 2 行 3 列，当前画在第 1 个位置
        plt.subplot(231), plt.title('1. Original Image')
        # OpenCV读入是BGR顺序，Matplotlib显示要求RGB顺序，所以要转换一下颜色通道
        plt.imshow(cv2.cvtColor(img, cv2.COLOR_BGR2RGB)), plt.axis('off') # axis('off') 隐藏坐标轴
        
        plt.subplot(232), plt.title('2. Basic: Haar Magnitude')
        plt.imshow(basic_mag, cmap='gray'), plt.axis('off') # cmap='gray' 以纯黑白灰度映射显示
        
        plt.subplot(233), plt.title(f'3. Basic Edges (F1: {b_f1:.2f})')
        plt.imshow(basic_edges, cmap='gray'), plt.axis('off')
        
        plt.subplot(234), plt.title('4. Ground Truth')
        plt.imshow(gt_img, cmap='gray'), plt.axis('off')
        
        plt.subplot(235), plt.title('5. Adv: Multi-scale Fusion')
        plt.imshow(adv_mag, cmap='gray'), plt.axis('off')
        
        plt.subplot(236), plt.title(f'6. Adv Edges (F1: {a_f1:.2f})')
        plt.imshow(adv_edges, cmap='gray'), plt.axis('off')
        
        # 自动调整排版，防止图表标题互相重叠
        plt.tight_layout()
        # 以300DPI(出版级清晰度)保存图片到本地
        plt.savefig(os.path.join(out_dir, f"{base_name}_comparison.png"), dpi=300)
        plt.close() # 释放内存，防止处理大量图片时电脑卡顿

if __name__ == '__main__':
    main()