%% 控制系统降阶近似仿真分析
clc; clear; close all;

% 1. 模型定义
s = tf('s');
G1 = 20 / ((100*s + 1) * (1*s + 1));  % 原二阶系统
G2 = 20 / (100*s + 1);                % 近似1：直接忽略小项
G3 = 20 / (101*s + 1);                % 近似2：时间常数累加

% 配置绘图参数
colors = {'b-', 'r--', 'g-.'};
lineWidth = 1.5;

% 2. 绘制单位脉冲响应 (Impulse Response)
figure('Name', '时域分析-单位脉冲响应', 'Color', 'w');
impulse(G1, colors{1}, G2, colors{2}, G3, colors{3}, lineWidth);
grid on;
title('单位脉冲响应对比');
legend('G_1(s) 原系统', 'G_2(s) 忽略近似', 'G_3(s) 累加近似');

% 3. 绘制单位阶跃响应 (Step Response)
figure('Name', '时域分析-单位阶跃响应', 'Color', 'w');
step(G1, colors{1}, G2, colors{2}, G3, colors{3}, lineWidth);
grid on;
title('单位阶跃响应对比');
legend('G_1(s)', 'G_2(s)', 'G_3(s)', 'Location', 'southeast');

% 4. 绘制伯德图 (Bode Plot)
figure('Name', '频域分析-伯德图', 'Color', 'w');
options = bodeoptions;
options.Grid = 'on';
options.FreqUnits = 'rad/s';
bodeplot(G1, colors{1}, G2, colors{2}, G3, colors{3}, options);
title('频域特性对比 (Bode Plot)');
legend('G_1(s)', 'G_2(s)', 'G_3(s)', 'Location', 'southwest');