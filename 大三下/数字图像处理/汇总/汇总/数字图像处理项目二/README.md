# 基于小波变换的边缘检测 (Wavelet-based Edge Detection)

## 项目概述

这是一个数字图像处理课程项目，实现了基于**小波变换（Wavelet Transform）** 的图像边缘检测方法。项目包含两种边缘检测算法：
- **基础方法**：单尺度 Haar 小波分解 + Otsu 自适应二值化
- **改进方法**：双边滤波去噪 + Sym4 小波多尺度融合 + 形态学处理

## 项目特点

✨ **核心创新**
- 利用小波变换的多尺度分解能力提取边缘特征
- 双尺度特征加权融合，兼顾微观细节和宏观结构
- 形态学闭操作优化边缘连贯性
- 自动评估指标（Precision、Recall、F1-Score）

## 文件结构

```
.
├── README.md                      # 项目说明文档（本文件）
├── requirements.txt               # 项目依赖包
├── 基于小波变换的边缘检测.pdf    # 详细技术文档
├── src/
│   └── main.py                   # 主程序入口
├── samples/
│   ├── images/                   # 原始测试图像
│   └── groundTruth/              # 人工标注的真值边缘图像
└── result/
    └── final_and_intermediate/   # 中间结果与最终结果输出
```

## 环境要求

- Python 3.6+
- 依赖包（详见 requirements.txt）：
  - OpenCV (>=4.5.0)
  - NumPy (>=1.19.0)
  - PyWavelets (>=1.1.0)
  - Matplotlib (>=3.3.0)

## 快速开始

### 1. 环境安装

```bash
pip install -r requirements.txt
```

### 2. 运行程序

```bash
cd src
python main.py
```

程序将自动处理 `samples/images/` 目录中的所有 `.jpg` 图像，并输出评估指标和可视化结果。

### 3. 查看结果

- **控制台输出**：精确率、召回率、F1-Score 等评估指标
- **图像输出**：保存在 `output_results/` 目录中的边缘检测结果

## 算法详解

### 基础方法 (Basic Wavelet Edge Detection)

```
输入图像 → 2D 离散小波变换 (DWT)
         → 提取高频系数 (cH, cV, cD)
         → 计算梯度幅值
         → 归一化处理
         → 尺寸还原
         → Otsu 自适应二值化
         → 输出边缘图
```

**关键步骤**：
1. 使用 Haar 小波进行单层分解
2. 从水平、竖直、对角线方向的高频系数计算边缘幅值
3. Otsu 方法自动确定二值化阈值

### 改进方法 (Advanced Wavelet Edge Detection)

```
输入图像 → 双边滤波去噪 (保边)
        → 二层小波分解 (Sym4)
        → 第1层细节特征 (微观) ─┐
        → 第2层结构特征 (宏观) ─┼→ 加权融合 → Otsu 二值化
                               → 形态学闭操作
                               → 输出边缘图
```

**关键改进**：
1. **双边滤波**：高效去噪，同时保留边缘
2. **多尺度融合**：第1层（60%）捕捉细节，第2层（40%）保留宏观结构
3. **形态学闭操作**：填补边缘间隙，提高连贯性
4. **Sym4 小波**：比 Haar 更平滑，减少伪影

## 性能评估

程序自动计算以下指标：

| 指标 | 公式 | 说明 |
|------|------|------|
| **Precision（精确率）** | TP / (TP + FP) | 检测为边缘的像素中真正是边缘的比例 |
| **Recall（召回率）** | TP / (TP + FN) | 真实边缘中被成功检测的比例 |
| **F1-Score** | 2 × P × R / (P + R) | 精确率和召回率的调和平均 |

其中：
- TP（True Positive）：正确检测的边缘像素
- FP（False Positive）：错误检测的非边缘像素
- FN（False Negative）：漏检的边缘像素

## 使用说明

### 修改测试图像

1. 将新图像（.jpg 格式）放入 `samples/images/` 目录
2. 将对应的真值边缘图放入 `samples/groundTruth/` 目录（必须同名）
3. 重新运行 `python main.py`

### 自定义参数

编辑 `src/main.py` 中的以下参数：

```python
# 双边滤波参数（高级方法）
cv2.bilateralFilter(img_gray, d=9, sigmaColor=75, sigmaSpace=75)

# 小波融合权重
cv2.addWeighted(mag1_res, 0.6, mag2_res, 0.4, 0)  # 第1层60%，第2层40%

# 形态学核大小
kernel = cv2.getStructuringElement(cv2.MORPH_CROSS, (3, 3))
```

## 技术亮点

🎯 **算法创新**
- 充分利用小波多尺度分析的优势
- 自适应阈值处理（Otsu 方法）
- 形态学后处理优化结果

📊 **完整的评估体系**
- 基于混淆矩阵的客观指标评估
- 支持与多种边缘检测方法对比

🔧 **代码质量**
- 模块化设计，易于扩展
- 详细注释说明关键步骤
- 异常处理和路径健壮性检查

## 示例输出

```
--------------------------------------------------------------------------------
Image ID     | Method     | Precision  | Recall     | F1-Score  
--------------------------------------------------------------------------------
image_001    | Basic      | 0.8234     | 0.7891     | 0.8060
image_001    | Advanced   | 0.8567     | 0.8234     | 0.8398
image_002    | Basic      | 0.8012     | 0.7654     | 0.7830
image_002    | Advanced   | 0.8345     | 0.8123     | 0.8233
...
```

## 参考资源

- 详细技术说明请查看 `基于小波变换的边缘检测.pdf`
- PyWavelets 文档：https://pywt.readthedocs.io/
- OpenCV 文档：https://docs.opencv.org/

## 许可证

本项目为学校课程作业，仅供学习交流使用。

## 联系方式

如有问题或建议，欢迎提出 Issue 或 Pull Request。

---

**最后更新**：2026年06月  
**课程**：数字图像处理  
**项目**：期末作业项目二
