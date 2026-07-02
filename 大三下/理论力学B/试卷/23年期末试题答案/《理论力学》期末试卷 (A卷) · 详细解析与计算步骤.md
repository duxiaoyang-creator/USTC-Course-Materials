# 《理论力学》期末试卷 (A卷) · 详细解析与计算步骤


## 一、 简答题 (30分)

1. **力系等效与力螺旋**  
   - **等效条件**：两力系向同一点简化的主矢 $\bm{F}_R$ 和主矩 $\bm{M}_O$ 分别相等。  
   - **力螺旋**：当 $\bm{F}_R \neq 0$，$\bm{M}_O \neq 0$，且 $\bm{F}_R \cdot \bm{M}_O \neq 0$（即两者不垂直）时，力系可简化为沿中心轴的一个力与一个平行于该力的力偶。  

2. **理想约束与完整约束**  
   - **理想约束**：约束力在系统任意虚位移上所作虚功之和为零，即 $\sum \delta W_N = 0$。  
     *例*：光滑支撑面、不可伸长的无重细绳。  
   - **完整约束**：约束方程可通过积分化为仅含坐标和时间的有限形式 $f(q_1, \dots, q_n, t) = 0$，不含不可积的速度项。  
     *例*：质点被限制在固定球面上运动。  

3. **虚位移与虚功原理**  
   - **虚位移 $\delta \bm{r}$**：给定瞬时，为约束所允许的、无限小的、纯几何的假想位移。  
   - **虚功原理**：受理想约束的质点系平衡的充分必要条件是，所有主动力在任意虚位移上所作虚功之和为零：  
     $$\sum \bm{F}_i \cdot \delta \bm{r}_i = 0$$  

4. **绝对导数与相对导数**  
   - **绝对导数** $\frac{\mathrm{d}\bm{A}}{\mathrm{d}t}$：矢量 $\bm{A}$ 在静止参考系中的变化率。  
   - **相对导数** $\frac{\delta\bm{A}}{\delta t}$：矢量 $\bm{A}$ 在动参考系中的变化率。  
   - **关系式（泊松公式）**：  
     $$\frac{\mathrm{d}\bm{A}}{\mathrm{d}t} = \frac{\delta\bm{A}}{\delta t} + \bm{\omega} \times \bm{A}$$  
     其中 $\bm{\omega}$ 为动系的角速度。  

5. **旋转矩阵**  
   - 坐标变换：$\bm{r} = \bm{A} \bm{r}'$（$\bm{A}$ 为旋转矩阵）。  
   - **微分方程**：$\dot{\bm{A}} = \tilde{\bm{\omega}} \bm{A}$，其中 $\tilde{\bm{\omega}}$ 是由角速度矢量 $\bm{\omega} = [\omega_x, \omega_y, \omega_z]^T$ 构造的反对称矩阵。  

6. **达朗伯原理与拉格朗日方程**  
   - **达朗伯原理（刚体平面运动）**：  
     $$\sum \bm{F} + \bm{F}_I = 0, \quad \sum M_C(\bm{F}) + M_{I,C} = 0$$  
     （$C$ 为质心，$\bm{F}_I$ 为惯性力，$M_{I,C}$ 为惯性力偶矩）。  
   - **第二类拉格朗日方程**：  
     $$\frac{\mathrm{d}}{\mathrm{d}t}\left(\frac{\partial T}{\partial \dot{q}_i}\right) - \frac{\partial T}{\partial q_i} = Q_i$$  
     （$T$ 为动能，$q_i$ 为广义坐标，$Q_i$ 为广义力）。  


## 二、 旋转圆盘的运动学分析 (14分)

### 1. 坐标系与运动学建模  
- 固定坐标系 $Oxyz$：$z$ 轴沿 $AB$ 轴向上。  
- 动坐标系固连于 $OC$ 轴所在平面，绕 $z$ 轴转动。  
- **牵连角速度**：$\bm{\Omega} = \Omega \bm{k}$  
- **相对角速度**（绕 $OC$ 轴）：  
  $$\bm{\omega}_r = \omega\sin\alpha \bm{i} + \omega\cos\alpha \bm{k}$$  
- **$C$ 点位置矢量**：  
  $$\bm{r}_C = l \sin\alpha \bm{i} + l \cos\alpha \bm{k}$$  

### 2. 最高点 $M$ 与最低点 $N$ 的相对位置  
圆盘平面垂直于 $OC$ 轴，$M$、$N$ 位于 $Oxz$ 平面内。  
- **相对矢径**：  
  $$\bm{r}_{M/C} = r(-\cos\alpha \bm{i} + \sin\alpha \bm{k}), \quad \bm{r}_{N/C} = r(\cos\alpha \bm{i} - \sin\alpha \bm{k})$$  
- **坐标**：  
  $$M(l\sin\alpha - r\cos\alpha,\ 0,\ l\cos\alpha + r\sin\alpha)$$  
  $$N(l\sin\alpha + r\cos\alpha,\ 0,\ l\cos\alpha - r\sin\alpha)$$  

### 3. 速度分析（点速度合成定理 $\bm{v} = \bm{v}_e + \bm{v}_r$）  
**对于 $M$ 点**：  
$$\begin{aligned}  
\bm{v}_{eM} &= \bm{\Omega} \times \bm{r}_M = \Omega(l\sin\alpha - r\cos\alpha) \bm{j} \\  
\bm{v}_{rM} &= \bm{\omega}_r \times \bm{r}_{M/C} = (\omega\sin\alpha \bm{i} + \omega\cos\alpha \bm{k}) \times r(-\cos\alpha \bm{i} + \sin\alpha \bm{k}) = -\omega r \bm{j} \\  
\Rightarrow \bm{v}_M &= [\Omega(l\sin\alpha - r\cos\alpha) - \omega r] \bm{j}  
\end{aligned}$$  

**对于 $N$ 点（同理）**：  
$$\bm{v}_N = [\Omega(l\sin\alpha + r\cos\alpha) + \omega r] \bm{j}$$  

### 4. 加速度分析（科氏加速度定理 $\bm{a} = \bm{a}_e + \bm{a}_r + \bm{a}_k$）  
**对于 $M$ 点**：  
$$\begin{aligned}  
\bm{a}_{eM} &= \bm{\Omega} \times (\bm{\Omega} \times \bm{r}_M) = -\Omega^2(l\sin\alpha - r\cos\alpha) \bm{i} \\  
\bm{a}_{rM} &= \bm{\omega}_r \times (\bm{\omega}_r \times \bm{r}_{M/C}) = -\omega^2 \bm{r}_{M/C} = \omega^2 r \cos\alpha \bm{i} - \omega^2 r \sin\alpha \bm{k} \\  
\bm{a}_{kM} &= 2 \bm{\Omega} \times \bm{v}_{rM} = 2\Omega\omega r \bm{i} \\  
\Rightarrow \bm{a}_M &= [-\Omega^2(l\sin\alpha - r\cos\alpha) + \omega^2 r \cos\alpha + 2\Omega\omega r] \bm{i} - \omega^2 r \sin\alpha \bm{k}  
\end{aligned}$$  

**对于 $N$ 点**：  
$$\begin{aligned}  
\bm{a}_{eN} &= -\Omega^2(l\sin\alpha + r\cos\alpha) \bm{i} \\  
\bm{a}_{rN} &= -\omega^2 r(\cos\alpha \bm{i} - \sin\alpha \bm{k}) \\  
\bm{a}_{kN} &= -2\Omega\omega r \bm{i} \\  
\Rightarrow \bm{a}_N &= [-\Omega^2(l\sin\alpha + r\cos\alpha) - \omega^2 r \cos\alpha - 2\Omega\omega r] \bm{i} + \omega^2 r \sin\alpha \bm{k}  
\end{aligned}$$  


## 三、 空间桁架与杆内力静力学分析 (14分)

### 1. 几何模型建立  
- 原点 $O(0,0,0)$ 位于 $D$ 点正下方，水平板高度设为 $h$。  
- **板上节点**：$D(0,0,h), E(b,0,h), F(b,a,h), G(0,a,h)$。  
- **地面节点**：$A(0,0,0), B(b,0,0), C(b,a,0)$。  
- **外力**：点 $G$ 受向下外力 $\bm{P} = (0,0,-P)$，设杆件拉力为正。  

### 2. 杆件分布与内力方向  
- **竖杆**：$T_1(AD), T_2(BE), T_3(CF)$（方向沿 $\pm z$）。  
- **斜杆**：  
  - $T_4(AE)$：方向 $\frac{1}{L}(-b, 0, -h)$，$L = \sqrt{b^2 + h^2}$  
  - $T_5(BD)$：方向 $\frac{1}{L}(b, 0, -h)$  
  - $T_6(CE)$：方向 $\frac{1}{L_c}(0, a, -h)$，$L_c = \sqrt{a^2 + h^2}$  

### 3. 空间力系平衡方程求解  
对水平板列写平衡方程：  
$$\begin{aligned}  
\sum F_y = 0 &\implies -T_6 \frac{a}{L_c} = 0 \implies T_6 = 0 \\  
\sum F_x = 0 &\implies -T_4 \frac{b}{L} + T_5 \frac{b}{L} = 0 \implies T_4 = T_5 = T_x \\  
\sum M_{DE} = 0 &\implies P \cdot a + T_3 \cdot a = 0 \implies T_3 = -P \ (\text{受压}) \\  
\sum M_{DG} = 0 &\implies -b T_2 - b T_3 - b T_x \frac{h}{L} = 0 \implies T_2 = P - T_x \frac{h}{L} \\  
\sum F_z = 0 &\implies -T_1 - T_2 - T_3 - P - 2 T_x \frac{h}{L} = 0  
\end{aligned}$$  
代入 $T_2, T_3$ 得：$T_1 = -P - T_x \frac{h}{L}$。  

> **注**：方程组在 $x$ 方向超静定，需补充对称性假设或变形协调条件。  


## 四、 加速车厢内杆的平衡条件 (14分)

### 1. 达朗伯原理与受力分析  
在非惯性系（车厢）中，质心 $C\left(\frac{l}{2}\cos\theta, \frac{l}{2}\sin\theta\right)$ 处加向右惯性力 $\bm{F}_I = ma$。  
- **受力**：重力 $mg$（下），墙弹力 $N_B$（右），地面支持力 $N_A$（上），摩擦力 $f$（左）。  

### 2. 平衡方程  
$$\begin{aligned}  
\sum F_x = 0 &\implies N_B + ma - f = 0 \implies f = N_B + ma \\  
\sum F_y = 0 &\implies N_A - mg = 0 \implies N_A = mg \\  
\sum M_A = 0 &\implies mg \frac{l}{2}\cos\theta - N_B l \sin\theta - ma \frac{l}{2}\sin\theta = 0 \\  
&\implies N_B = \frac{mg\cos\theta - ma\sin\theta}{2\sin\theta} = \frac{mg}{2\tan\theta} - \frac{ma}{2}  
\end{aligned}$$  

### 3. 平衡条件约束  
- **不脱离墙面**（$N_B \geq 0$）：  
  $$\frac{mg}{2\tan\theta} - \frac{ma}{2} \geq 0 \implies a \leq g\cot\theta$$  
- **不滑动**（$|f| \leq \mu N_A$）：  
  $$f = \frac{mg}{2\tan\theta} + \frac{ma}{2} \leq \mu mg \implies a \leq g(2\mu - \cot\theta)$$  

**综合条件**：  
$$a \leq \min\left(g\cot\theta,\ g(2\mu - \cot\theta)\right)$$  


## 五、 RTAC 振荡器动力学微分方程 (14分)

### 1. 运动学关系  
广义坐标：小车位移 $x$，摆角 $\theta$。  
- **小球坐标**：$x_m = x + e\sin\theta,\ y_m = -e\cos\theta$  
- **小球速度**：$\dot{x}_m = \dot{x} + e\dot{\theta}\cos\theta,\ \dot{y}_m = e\dot{\theta}\sin\theta$  
- **速度平方**：$v_m^2 = \dot{x}^2 + e^2\dot{\theta}^2 + 2e\dot{x}\dot{\theta}\cos\theta$  

### 2. 拉格朗日函数 $L = T - V$  
$$\begin{aligned}  
T &= \frac{1}{2}M\dot{x}^2 + \frac{1}{2}m v_m^2 + \frac{1}{2}J\dot{\theta}^2 = \frac{1}{2}(M+m)\dot{x}^2 + \frac{1}{2}(J+me^2)\dot{\theta}^2 + me\dot{x}\dot{\theta}\cos\theta \\  
V &= \frac{1}{2}k x^2 - mge\cos\theta \\  
L &= \frac{1}{2}(M+m)\dot{x}^2 + \frac{1}{2}(J+me^2)\dot{\theta}^2 + me\dot{x}\dot{\theta}\cos\theta - \frac{1}{2}k x^2 + mge\cos\theta  
\end{aligned}$$  

### 3. 第二类拉格朗日方程  
**对 $x$ 坐标（广义力 $Q_x = F$）**：  
$$(M+m)\ddot{x} + me\ddot{\theta}\cos\theta - me\dot{\theta}^2\sin\theta + kx = F$$  

**对 $\theta$ 坐标（广义力 $Q_\theta = T_{\text{torque}}$）**：  
$$(J+me^2)\ddot{\theta} + me\ddot{x}\cos\theta + mge\sin\theta = T_{\text{torque}}$$  


## 六、 对称重刚体定点运动的哈密顿动力学 (14分)

### 1. 拉格朗日函数  
已知欧拉角运动学关系：$\omega_x^2 + \omega_y^2 = \dot{\psi}^2\sin^2\theta + \dot{\theta}^2$，则  
$$\begin{aligned}  
T &= \frac{1}{2}J_x(\dot{\psi}^2\sin^2\theta + \dot{\theta}^2) + \frac{1}{2}J_z(\dot{\varphi} + \dot{\psi}\cos\theta)^2 \\  
V &= mgl\cos\theta \\  
L &= T - V  
\end{aligned}$$  

### 2. 哈密顿函数  
**广义动量**：  
$$p_\theta = J_x\dot{\theta},\ p_\varphi = J_z(\dot{\varphi} + \dot{\psi}\cos\theta),\ p_\psi = J_x\dot{\psi}\sin^2\theta + p_\varphi\cos\theta$$  

**哈密顿函数**（$H = T + V$）：  
$$H = \frac{p_\theta^2}{2J_x} + \frac{(p_\psi - p_\varphi\cos\theta)^2}{2J_x\sin^2\theta} + \frac{p_\varphi^2}{2J_z} + mgl\cos\theta$$  

### 3. 哈密顿正则方程与首次积分  
**正则方程**：  
$$\dot{\psi} = \frac{\partial H}{\partial p_\psi},\ \dot{\varphi} = \frac{\partial H}{\partial p_\varphi},\ \dot{\theta} = \frac{\partial H}{\partial p_\theta}$$  
$$\dot{p}_\psi = 0,\ \dot{p}_\varphi = 0,\ \dot{p}_\theta = -\frac{\partial H}{\partial \theta}$$  

**首次积分（守恒量）**：  
- 能量积分：$H = E = \text{const}$（机械能守恒）  
- 循环坐标积分：$p_\psi = \text{const}$（空间章动角动量守恒），$p_\varphi = \text{const}$（自转角动量守恒）  

**试卷解析完毕。** 如需按考点拆分复习清单或拉格朗日/哈密顿变式题，可进一步补充说明。