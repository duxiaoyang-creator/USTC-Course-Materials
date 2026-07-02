%% 控制系统多采样周期离散化分析
clc; clear; close all;

% 1. 定义连续系统 G(s)
num = 20;
den = conv([100, 1], [10, 1]); 
G_cont = tf(num, den);

% 2. 选取四个不同的采样时间 Ts
Ts_list = [0.1, 1, 5, 10];  
methods = {'zoh', 'tustin'};
colors = {'r', 'g', 'b', 'm'}; % 分别对应四个 Ts

% 3. 绘图配置
figure('Color', 'w', 'Position', [100, 100, 1000, 750]);
options = bodeoptions;
options.Grid = 'on';
options.FreqUnits = 'rad/s';
options.XLim = [1e-3, 20];

% 绘制基准：连续系统
hold on;
bodeplot(G_cont, 'k-', options); 
legendLabels = {'Continuous G(s)'};

% 4. 循环生成不同组合
for i = 1:length(Ts_list)
    Ts = Ts_list(i);
    for j = 1:length(methods)
        method = methods{j};
        G_disc = c2d(G_cont, Ts, method);
        
        % 区分线型：ZOH用虚线，Tustin用点线
        if strcmp(method, 'zoh')
            ls = '--';
        else
            ls = ':';
        end
        
        bodeplot(G_disc, [colors{i} ls], options);
        legendLabels{end+1} = sprintf('Ts=%0.1fs (%s)', Ts, method);
    end
end

legend(legendLabels, 'Location', 'southwest', 'FontSize', 8, 'NumColumns', 2);
title('不同采样时间(0.1s, 1s, 5s, 10s)下的系统频域特性对比');