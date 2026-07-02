clear; clc;

%% 系统参数定义
A = [0  1   0    0;
     0  0   0    0;
     0  0   0    1;
     0  0  29.4  0]; 

B = [0; 1; 0; 3];

C = [1 0 0 0;   % 小车位置
     0 0 1 0];   % 摆杆角度

desired_poles=[-3,-4,-5+3i,-5-3i];

syms s k1 k2 k3 k4 real
K=[k1,k2,k3,k4];
Ac=A-B*K;

f = det(s*eye(4)-Ac);
coeff_cl=coeffs(f,s,'All');

coeff_des=poly(desired_poles);
eqns = coeff_cl(2:end) == coeff_des(2:end);

sol= solve(eqns,K);
K_num= double([sol.k1,sol.k2,sol.k3,sol.k4]);

fprintf('待定法K=[%.4f,%.4f,%.4f,%.4f]\n',K_num);

closed_poles = eig(A -B*K_num);
disp(closed_poles); 

%%
desired_poles_obs=[-6,-8,-10+3i,-10-3i];
H=place(A',C',desired_poles_obs)';

fprintf('H=\n');
disp(H);
