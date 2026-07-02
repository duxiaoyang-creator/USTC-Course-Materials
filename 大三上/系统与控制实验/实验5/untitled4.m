% 清除环境
clf;
clear all;
close all;

% 时间序列设置
t = 0:0.1:10;

% 系统参数设置（根据实验指导书）
T1 = 0.1;           % T1 = R1C1 = 0.1
k1 = 10.5;          % K1 = (R12+R13)/R11 = 10.5
T2 = 0.005;         % T2 = R2C2 = 0.005

% 校正网络参数（超前校正）
T0 = 0.001;         % T0 = R14C4 = 0~0.002，根据实验调整
TD = 0.0476;        % TD = C4*(R12*R13)/(R12+R13)
Td = T0 + TD;       % Td = R14*C4 + TD

% 系统增益参数（根据实验要求调整）
k3 = 1.0;           % K3 = R32/R31 = 0.2~3，临界值K(临)=2.04
T3 = k3 * 0.1;      % T3 = R32*C3 = K3*R31*C3

% 计算总增益
k = k1 * k3;

% 开环传递函数系数（超前校正）
numo = [k*Td, k];   % 分子系数：[k*Td, k]
% 分母系数：T1*s * (T2*s+1) * (T3*s+1) * (T0*s+1)
deno = conv(conv(conv([T1, 0], [T2, 1]), [T3, 1]), [T0, 1]);

% 闭环传递函数系数
numc = numo;   % 分子系数不变
denc = [zeros(1, length(deno)-length(numo)), numo] + deno;

% 绘制图形
figure('Position', [100, 100, 800, 600]);

% 子图1：带裕度的开环Bode图
subplot(2, 1, 1);
margin(numo, deno);
grid on;
title('开环Bode图（含幅值裕度和相位裕度）');
xlabel('频率 (rad/s)');

% 子图2：闭环阶跃响应
subplot(2, 1, 2);
step(numc, denc, t);
grid on;
title('闭环系统阶跃响应');
xlabel('时间 (s)');
ylabel('幅值');

% 显示系统参数信息
fprintf('=== 系统参数 ===\n');
fprintf('T1 = %.4f, k1 = %.2f, T2 = %.4f\n', T1, k1, T2);
fprintf('T0 = %.4f, TD = %.4f, Td = %.4f\n', T0, TD, Td);
fprintf('k3 = %.2f, T3 = %.4f, 总增益 k = %.2f\n', k3, T3, k);

% 计算并显示稳定性指标
[Gm, Pm, Wcg, Wcp] = margin(numo, deno);
fprintf('\n=== 稳定性分析 ===\n');
fprintf('幅值裕度: %.2f dB (在 %.2f rad/s 处)\n', 20*log10(Gm), Wcg);
fprintf('相位裕度: %.2f° (在 %.2f rad/s 处)\n', Pm, Wcp);

if Pm > 45 && 20*log10(Gm) > 6
    fprintf('系统状态: 稳定 ✅\n');
elseif Pm > 0
    fprintf('系统状态: 临界稳定 ⚠️\n');
else
    fprintf('系统状态: 不稳定 ❌\n');
end
% 清除环境
clf;
clear all;
close all;

% 时间序列设置
t = 0:0.1:10;

% 系统参数设置（根据实验指导书）
T1 = 0.1;           % T1 = R1C1 = 0.1
k1 = 10.5;          % K1 = (R12+R13)/R11 = 10.5
T2 = 0.005;         % T2 = R2C2 = 0.005

% 校正网络参数（超前校正）
T0 = 0.001;         % T0 = R14C4 = 0~0.002，根据实验调整
TD = 0.0476;        % TD = C4*(R12*R13)/(R12+R13)
Td = T0 + TD;       % Td = R14*C4 + TD

% 系统增益参数（根据实验要求调整）
k3 = 1.0;           % K3 = R32/R31 = 0.2~3，临界值K(临)=2.04
T3 = k3 * 0.1;      % T3 = R32*C3 = K3*R31*C3

% 计算总增益
k = k1 * k3;

% 开环传递函数系数（超前校正）
numo = [k*Td, k];   % 分子系数：[k*Td, k]
% 分母系数：T1*s * (T2*s+1) * (T3*s+1) * (T0*s+1)
deno_temp1 = conv([T1, 0], [T2, 1]);
deno_temp2 = conv(deno_temp1, [T3, 1]);
deno = conv(deno_temp2, [T0, 1]);

% 创建传递函数对象
sys_open = tf(numo, deno);

% 闭环传递函数系数
numc = numo;
denc = [zeros(1, length(deno)-length(numo)), numo] + deno;
sys_close = tf(numc, denc);

% 绘制图形
figure('Position', [100, 100, 800, 600]);

% 子图1：带裕度的开环Bode图
subplot(2, 1, 1);
margin(sys_open);  % 使用传递函数对象
grid on;
title('开环Bode图（含幅值裕度和相位裕度）');
xlabel('频率 (rad/s)');

% 子图2：闭环阶跃响应
subplot(2, 1, 2);
step(sys_close, t);  % 使用传递函数对象
grid on;
title('闭环系统阶跃响应');
xlabel('时间 (s)');
ylabel('幅值');

% 显示系统参数信息
fprintf('=== 系统参数 ===\n');
fprintf('T1 = %.4f, k1 = %.2f, T2 = %.4f\n', T1, k1, T2);
fprintf('T0 = %.4f, TD = %.4f, Td = %.4f\n', T0, TD, Td);
fprintf('k3 = %.2f, T3 = %.4f, 总增益 k = %.2f\n', k3, T3, k);

% 计算并显示稳定性指标
[Gm, Pm, Wcg, Wcp] = margin(sys_open);
fprintf('\n=== 稳定性分析 ===\n');
fprintf('幅值裕度: %.2f dB (在 %.2f rad/s 处)\n', 20*log10(Gm), Wcg);
fprintf('相位裕度: %.2f° (在 %.2f rad/s 处)\n', Pm, Wcp);

if Pm > 45 && 20*log10(Gm) > 6
    fprintf('系统状态: 稳定 ✅\n');
elseif Pm > 0
    fprintf('系统状态: 临界稳定 ⚠️\n');
else
    fprintf('系统状态: 不稳定 ❌\n');
end

% 显示传递函数
fprintf('\n=== 传递函数 ===\n');
disp('开环传递函数:');
sys_open
disp('闭环传递函数:');
sys_close
% 清除环境
clf;
clear all;

% 时间设置
t = 0:0.1:10;

% 系统参数设置（根据图片中的参数）
T1 = 0.1;           % T1 = R1C1 = 0.1
k1 = 10.5;          % K1 = (R12+R13)/R11 = 10.5
T2 = 0.005;         % T2 = R2C2 = 0.005

% 滞后校正网络参数（根据图片）
TD = 0.4762;        % TD = (R12*R13)/(R12+R13)*C5 = 0.4762
Tc = 0.5;           % Tc = R15*C5 = 0~1 （可调节参数）
Tf = 10;            % Tf = R12*C5 = 10
Td = Tc + TD;       % Td = Tc + TD = 0.4762~1.4762

% 系统增益参数
k3 = 1.0;           % K3 = R32/R31 （根据实验调整）
T3 = k3 * 0.1;      % T3 = R32*C3

% 计算总增益
k = k1 * k3;

% 开环传递函数系数（滞后校正）
numo = k * [Td, 1];  % 分子系数：k*[Td, 1]

% 分母系数：T1*s * (T2*s+1) * (T3*s+1) * ((Tc+Tf)*s+1)
deno_temp1 = conv([T1, 0], [T2, 1]);
deno_temp2 = conv(deno_temp1, [T3, 1]);
deno = conv(deno_temp2, [Tc+Tf, 1]);

% 专门绘制Bode图的代码
figure('Position', [100, 100, 800, 400]);
margin(numo, deno);
grid on;
title('开环系统Bode图 - 滞后校正');
xlabel('频率 (rad/s)');

% 显示稳定性裕度
[Gm, Pm, Wcg, Wcp] = margin(numo, deno);
fprintf('幅值裕度: %.2f dB, 相位裕度: %.2f°\n', 20*log10(Gm), Pm);
% 清除环境
clf;
clear all;

% 时间序列设置
t = 0:0.1:10;

% 系统参数设置
T1 = 0.1;           % T1 = R1C1 = 0.1
k1 = 10.5;          % K1 = (R12+R13)/R11 = 10.5
T2 = 0.005;         % T2 = R2C2 = 0.005

% 超前校正网络参数（关键调节参数）
T0 = 0.001;         % T0 = R14C4 = 0~0.002（根据实验调节）
TD = 0.0476;        % TD = C4*(R12*R13)/(R12+R13) = 0.0476
Td = T0 + TD;       % Td = R14*C4 + TD = 0.0476~0.0496

% 系统增益参数
k3 = 1.0;           % K3 = R32/R31 = 0.2~3（临界值K临=2.04）
T3 = k3 * 0.1;      % T3 = R32*C3 = k3*R31*C3

% 计算总增益
k = k1 * k3;

% 超前校正开环传递函数系数
numo = [k*Td, k];   % 分子系数：k*[Td, 1]
% 分母系数：T1*s * (T2*s+1) * (T3*s+1) * (T0*s+1)
deno_temp1 = conv([T1, 0], [T2, 1]);
deno_temp2 = conv(deno_temp1, [T3, 1]);
deno = conv(deno_temp2, [T0, 1]);

% 专门绘制超前校正Bode图
figure('Position', [100, 100, 800, 400]);
margin(numo, deno);
grid on;
title('超前校正系统Bode图');
xlabel('频率 (rad/s)');

% 计算并显示稳定性指标
[Gm, Pm, Wcg, Wcp] = margin(numo, deno);
fprintf('超前校正稳定性分析:\n');
fprintf('幅值裕度: %.2f dB (在 %.2f rad/s 处)\n', 20*log10(Gm), Wcg);
fprintf('相位裕度: %.2f° (在 %.2f rad/s 处)\n', Pm, Wcp);
% 清除环境
clf;
clear all;

% 时间序列设置
t = 0:0.1:10;

% 系统参数设置
T1 = 0.1;           % T1 = R1C1 = 0.1
k1 = 10.5;          % K1 = (R12+R13)/R11 = 10.5
T2 = 0.005;         % T2 = R2C2 = 0.005

% 超前校正网络参数（关键调节参数）
T0 = 0.001;         % T0 = R14C4 = 0~0.002（根据实验调节）
TD = 0.0476;        % TD = C4*(R12*R13)/(R12+R13) = 0.0476
Td = T0 + TD;       % Td = R14*C4 + TD = 0.0476~0.0496

% 系统增益参数
k3 = 1.0;           % K3 = R32/R31 = 0.2~3（临界值K临=2.04）
T3 = k3 * 0.1;      % T3 = R32*C3 = k3*R31*C3

% 计算总增益
k = k1 * k3;

% 超前校正开环传递函数系数
numo = [k*Td, k];   % 分子系数：k*[Td, 1]
% 分母系数：T1*s * (T2*s+1) * (T3*s+1) * (T0*s+1)
deno_temp1 = conv([T1, 0], [T2, 1]);
deno_temp2 = conv(deno_temp1, [T3, 1]);
deno = conv(deno_temp2, [T0, 1]);

% 专门绘制超前校正Bode图
figure('Position', [100, 100, 800, 400]);
margin(numo, deno);
grid on;
title('超前校正系统Bode图');
xlabel('频率 (rad/s)');

% 计算并显示稳定性指标
[Gm, Pm, Wcg, Wcp] = margin(numo, deno);
fprintf('超前校正稳定性分析:\n');
fprintf('幅值裕度: %.2f dB (在 %.2f rad/s 处)\n', 20*log10(Gm), Wcg);
fprintf('相位裕度: %.2f° (在 %.2f rad/s 处)\n', Pm, Wcp);
