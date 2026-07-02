%% 控制系统离散化与伯德图分析
% 针对系统 G(s) = 20 / ((100s+1)(10s+1))

clc; clear; close all;

%% 1. 定义连续系统
num = 20;
den = conv([100, 1], [10, 1]); % 计算分母多项式 (100s+1)(10s+1)
G_continuous = tf(num, den);
fprintf('连续系统 G(s):\n');
disp(G_continuous);

%% 2. 离散化参数设置
Ts_values = [0.1, 1, 10];  % 多个不同的采样时间
methods = {'zoh', 'tustin'}; % 两种离散化方法
legendStr = {'G(s) (连续)'}; % 图例初始化

%% 3. 绘制伯德图
figure('Position', [100, 100, 800, 600]);
hold on;
% 首先绘制连续系统
bode(G_continuous);

% 循环进行离散化并绘图
for i = 1:length(Ts_values)
    Ts = Ts_values(i);
    for j = 1:length(methods)
        method = methods{j};
        % 使用c2d函数进行离散化
        G_discrete = c2d(G_continuous, Ts, method);
        % 绘制该离散模型的伯德图
        bode(G_discrete);
        % 为图例添加描述
        legendStr{end+1} = sprintf('T_s = %.1f s (%s)', Ts, method);
        
        % (可选) 在命令行显示离散模型
        fprintf('离散模型(T_s=%.1f, 方法: %s):\n', Ts, method);
        disp(G_discrete);
    end
end
hold off;

% 美化图形
grid on;
title('连续系统与不同离散模型的伯德图对比');
legend(legendStr, 'Location', 'best');
% 调整坐标范围以便于观察关键频段(可选)
set(findall(gcf, 'Type', 'axes'), 'Xlim', [1e-3, 1e1]);

%% 4. 定量分析示例：计算并比较幅值/相位裕度
fprintf('\n--- 系统稳定性裕度分析 ---\n');
% 连续系统
[Gm_cont, Pm_cont, Wcg_cont, Wcp_cont] = margin(G_continuous);
fprintf('连续系统 G(s):\n');
fprintf('  幅值裕度: %.2f dB, 相位裕度: %.2f°\n', 20*log10(Gm_cont), Pm_cont);
fprintf('  相位穿越频率: %.3f rad/s, 增益穿越(截止)频率: %.3f rad/s\n\n', Wcg_cont, Wcp_cont);

% 分析一个特定的离散模型示例 (Ts=1s, zoh)
Ts_example = 1;
G_discrete_example = c2d(G_continuous, Ts_example, 'zoh');
[Gm_disc, Pm_disc, Wcg_disc, Wcp_disc] = margin(G_discrete_example);
fprintf('离散系统 (T_s=%.1f, zoh):\n', Ts_example);
fprintf('  幅值裕度: %.2f dB, 相位裕度: %.2f°\n', 20*log10(Gm_disc), Pm_disc);
fprintf('  相位穿越频率: %.3f rad/s, 增益穿越(截止)频率: %.3f rad/s\n', Wcg_disc, Wcp_disc);