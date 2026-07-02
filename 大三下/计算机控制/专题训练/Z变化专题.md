为你将文本中提取出的 Z 变换与 Z 反变换相关题目进行了系统性的分类与排版。这里去除了原本重复、交错的题号，按照“求 Z 变换”**、**“求修正 Z 变换”**和**“求 Z 反变换”三大类进行重新整合，方便你后续复习或打印使用。

## 一、 求下列函数的 Z 变换

除特殊说明外，各题均假设采样周期为 $T > 0$（常数）。

### 1. 连续时间信号 $f(t)$ 或离散信号 $f(k)$ 形式

- **(1)** $f(t) = 1 - e^{-at}$ （其中 $a > 0$ 为常数）
- **(2)** $f(t) = \sum_{i=0}^{10} a_{i}\delta(t-iT)$
- **(3)** $f(t) = 2t^{2}$ （当 $t \ge 0$ 时；其它时刻函数取值为 0）
- **(4)** $f(t) = e^{-at}\cos(\omega t)$ （其中 $a > 0, \omega > 0$ 为实数；当 $t \ge 0$ 时；其它时刻函数取值为 0）
- **(5)** $f(t) = \begin{cases} \frac{1}{2}t^{2} & t \ge 0 \\ 0 & t < 0 \end{cases}$
- **(6)** $f(t) = t^{2}$
- **(7)** $f(k) = ka^{k-1}$ （其中 $a$ 为不为 0 的正实数）
- **(8)** $f(t) = 2u(t-2T) - 3\delta(t-5T)$ （其中 $u(t)$ 为单位阶跃函数，$\delta(t)$ 为单位脉冲函数）
- **(9)** $f(t) = e^{-at}u(t-2T)$ （其中 $u(t)$ 为单位阶跃函数）

### 2. 离散卷积信号 $f^*(t)$ 形式

- **(10)** $f^{*}(t) = f_{1}^{*}(t) \otimes f_{2}^{*}(t)$

  其中：$f_{1}^{*}(t) = \sum_{n=0}^{\infty} e^{-anT}\delta(t-nT)$， $f_{2}^{*}(t) = \sum_{n=0}^{\infty}\delta(t-nT)$

- **(11)** $f^{*}(t) = f_{1}^{*}(t) \otimes f_{2}^{*}(t)$

  其中：$f_{1}^{*}(t) = \sum_{i=0}^{\infty} e^{-aiT}\delta(t-iT)$， $f_{2}^{*}(t) = \sum_{i=0}^{\infty}\delta(t-iT)$

### 3. 拉氏变换 / 传递函数 $G(s)$ 或 $F(s)$ 形式

- **(12)** $G(s) = \frac{1}{s^{2} + 2\xi\omega_{n}s + \omega_{n}^{2}}$
- **(13)** $G(s) = \frac{K}{s^{2} + 2\xi\omega_{n}s + \omega_{n}^{2}}$ （其中 $K$ 为非 0 实数，$\xi, \omega_{n}$ 均为正实数，且 $0 \le \xi \le 1$）
- **(14)** $G(s) = \frac{k}{s(s^{2} + s + 1)}$
- **(15)** $F(s) = \frac{3(1 - e^{-Ts})e^{-2.4Ts}}{s(5s + 1)}$
- **(16)** $F(s) = \frac{K(1 - e^{-Ts})e^{-2Ts}}{s(s + 1)}$
- **(17)** $F(s) = \frac{e^{-0.2Ts}}{s + a}$
- **(18)** $F(s) = \frac{1 - e^{-Ts}}{s} \cdot \frac{(s + a)e^{-1.4Ts}}{s + b}$ （其中 $a, b$ 均为正实数）
- **(19)** $F(s) = \frac{b - a}{(s + a)(s + b)}$ （其中 $a$ 和 $b$ 为合适的不相等正实数）
- **(20)** $F(s) = \frac{s}{s^{2} + \omega^{2}}$ （其中 $\omega$ 为合适的正实数）
- **(21)** $F(s) = \frac{se^{-0.6Ts}}{(s + 1)(s + 2)}$
- **(22)** $F(s) = \frac{1}{s(s + 1)^{2}}$
- **(23)** $G(s) = \frac{Ke^{-2Ts}}{(s + a)(s + b)}$ （其中 $K \ne 0$ 实数；$a > 0, b > 0$，二者均为实数且不相等）

## 二、 求下列函数的修正 Z 变换

- **(1)** 求 $F(s) = e^{-at}$（指数函数）的修正 Z 变换。

## 三、 求下列函数的 Z 反变换

- **(1)** $F(z) = \frac{z(1 - e^{-T})}{(z - 1)(z - e^{-T})}$
- **(2)** $F(z) = \frac{z}{z^{3} - 4z^{2} + 5z - 2}$













解答

一、求 Z 变换详细解析

### 1. 连续时间信号 $f(t)$ 或离散信号 $f(k)$ 形式

#### **(1)** $f(t) = 1 - e^{-at}$

- **解析**：

  首先将连续信号在 $t = nT$ 处采样，得到离散序列：

  $$f(nT) = 1 - e^{-anT} \quad (n \ge 0)$$

  利用线性性质分别求 Z 变换：

  - 单位阶跃序列 $1$ 的 Z 变换为：$\frac{z}{z-1}$
  - 指数序列 $e^{-anT} = (e^{-aT})^n$ 的 Z 变换为：$\frac{z}{z-e^{-aT}}$

  相减合并：

  $$F(z) = \frac{z}{z-1} - \frac{z}{z-e^{-aT}} = \frac{z(1 - e^{-aT})}{(z-1)(z-e^{-aT})}$$

#### **(2)** $f(t) = \sum_{i=0}^{10} a_{i}\delta(t-iT)$

- **解析**：

  该信号已经是理想采样信号形式，采样后的离散序列在 $n=i$ 时的值为 $a_i$（其中 $0 \le i \le 10$），其余时刻均为 0。

  根据 Z 变换的定义式 $F(z) = \sum_{n=0}^{\infty} f(nT)z^{-n}$，直接展开即可：

  $$F(z) = a_0 + a_1 z^{-1} + a_2 z^{-2} + \cdots + a_{10} z^{-10} = \sum_{i=0}^{10} a_i z^{-i}$$

#### **(3)** $f(t) = 2t^{2} \quad (t \ge 0)$

- **解析**：

  离散采样序列为 $f(nT) = 2(nT)^2 = 2T^2 n^2$。

  已知常用 Z 变换公式：$\mathcal{Z}\{n\} = \frac{z}{(z-1)^2}$。

  根据 **z 域微分性质**（时域乘以 $n$ 对应 $z$ 域乘 $-z\frac{d}{dz}$）：

  $$\mathcal{Z}\{n^2\} = -z \frac{d}{dz} \left[ \frac{z}{(z-1)^2} \right] = -z \frac{(z-1)^2 - z \cdot 2(z-1)}{(z-1)^4} = \frac{z(z+1)}{(z-1)^3}$$

  因此，乘以常数系数 $2T^2$ 后得到：

  $$F(z) = \frac{2T^2 z(z+1)}{(z-1)^3}$$

#### **(4)** $f(t) = e^{-at}\cos(\omega t) \quad (t \ge 0)$

- **解析**：

  离散采样序列为 $f(nT) = e^{-anT}\cos(\omega nT)$。

  根据欧拉公式，$\cos(\omega nT) = \frac{e^{j\omega nT} + e^{-j\omega nT}}{2}$，所以：

  $$f(nT) = \frac{1}{2} \left[ (e^{-(a-j\omega)T})^n + (e^{-(a+j\omega)T})^n \right]$$

  利用指数函数的 Z 变换公式展开：

  $$F(z) = \frac{1}{2} \left[ \frac{z}{z - e^{-aT}e^{j\omega T}} + \frac{z}{z - e^{-aT}e^{-j\omega T}} \right]$$

  通分合并后，分子分母同乘展开并利用 $\cos(\omega T) = \frac{e^{j\omega T} + e^{-j\omega T}}{2}$ 化简：

  $$F(z) = \frac{z [z - e^{-aT}\cos(\omega T)]}{z^2 - 2ze^{-aT}\cos(\omega T) + e^{-2aT}}$$

#### **(5)** $f(t) = \begin{cases} \frac{1}{2}t^{2} & t \ge 0 \\ 0 & t < 0 \end{cases}$

- **解析**：

  本题与第 (3) 题类似。离散采样序列为 $f(nT) = \frac{1}{2}T^2 n^2$。

  直接代入 $\mathcal{Z}\{n^2\} = \frac{z(z+1)}{(z-1)^3}$ 可得：

  $$F(z) = \frac{T^2 z(z+1)}{2(z-1)^3}$$

#### **(6)** $f(t) = t^{2}$

- **解析**：

  若未指定 $t < 0$ 的取值，在控制工程的 Z 变换上下文中默认其为因果信号（即 $t < 0$ 时 $f(t)=0$）。

  采样序列为 $f(nT) = T^2 n^2$，其 Z 变换结果为：

  $$F(z) = \frac{T^2 z(z+1)}{(z-1)^3}$$

#### **(7)** $f(k) = ka^{k-1} \quad (a \ne 0)$

- **解析**：

  该题目直接给出了离散时间序列 $f(k)$。

  我们可以将表达式改写为：$f(k) = \frac{1}{a} \cdot k a^k$。

  已知序列 $a^k$ 的 Z 变换为 $\frac{z}{z-a}$。根据时域乘以 $k$ 的性质（$-z\frac{d}{dz}$）：

  $$\mathcal{Z}\{k a^k\} = -z \frac{d}{dz} \left( \frac{z}{z-a} \right) = -z \frac{(z-a) - z}{(z-a)^2} = \frac{az}{(z-a)^2}$$

  因此，乘以常数 $\frac{1}{a}$：

  $$F(z) = \frac{1}{a} \cdot \frac{az}{(z-a)^2} = \frac{z}{(z-a)^2}$$

#### **(8)** $f(t) = 2u(t-2T) - 3\delta(t-5T)$

- **解析**：

  根据 Z 变换的时移性质 $\mathcal{Z}\{x(t-kT)\} = z^{-k} X(z)$：

  - 单位阶跃信号 $u(t)$ 的 Z 变换为 $\frac{z}{z-1}$，延迟 $2T$ 后为：$2 z^{-2} \frac{z}{z-1} = \frac{2}{z(z-1)}$
  - 单位脉冲信号 $\delta(t)$ 的 Z 变换为 $1$，延迟 $5T$ 后为：$3 z^{-5}$

  两者相减得到：

  $$F(z) = \frac{2}{z(z-1)} - 3z^{-5} = \frac{2z^4 - 3(z-1)}{z^5(z-1)} = \frac{2z^4 - 3z + 3}{z^5(z-1)}$$

#### **(9)** $f(t) = e^{-at}u(t-2T)$

- **解析**：

  需要特别注意，延迟函数 $u(t-2T)$ 使得信号在 $t < 2T$ 时为 0，但在 $t \ge 2T$ 后，指数衰减项的起点依然是 $t=0$。

  离散序列为：$f(nT) = e^{-anT} \quad (n \ge 2)$。

  根据定义法展开求和：

  $$F(z) = \sum_{n=2}^{\infty} e^{-anT}z^{-n} = \sum_{n=2}^{\infty} (e^{-aT}z^{-1})^n$$

  这是一个首项为 $(e^{-aT}z^{-1})^2$，公比为 $e^{-aT}z^{-1}$ 的无穷等比级数。根据求和公式 $\frac{\text{首项}}{1-\text{公比}}$：

  $$F(z) = \frac{(e^{-aT}z^{-1})^2}{1 - e^{-aT}z^{-1}} = \frac{e^{-2aT}z^{-2}}{1 - e^{-aT}z^{-1}} = \frac{e^{-2aT}}{z(z - e^{-aT})}$$

### 2. 离散卷积分式 $f^*(t)$ 形式

#### **(10) & (11)** $f^{*}(t) = f_{1}^{*}(t) \otimes f_{2}^{*}(t)$

- **解析**：

  第 (10) 题与第 (11) 题物理意义完全相同（只是求和指标从 $n$ 换成了 $i$）。

  根据**时域离散卷积定理**：时域的离散卷积对应 z 域的直接**相乘**，即 $F(z) = F_1(z) \cdot F_2(z)$。

  - 首先求 $f_1^*(t)$ 的 Z 变换：其脉冲序列的幅值随 $n$ 呈 $e^{-anT}$ 指数衰减，对应离散序列 $f_1(nT) = e^{-anT}$。

    $$F_1(z) = \frac{z}{z - e^{-aT}}$$

  - 再求 $f_2^*(t)$ 的 Z 变换：其为标准理想采样单位脉冲序列，对应离散单位阶跃序列 $f_2(nT) = 1$。

    $$F_2(z) = \frac{z}{z - 1}$$

  - 最后将两者相乘：

    $$F(z) = F_1(z) \cdot F_2(z) = \frac{z^2}{(z - e^{-aT})(z - 1)}$$

### 3. 拉氏变换 / 传递函数 $G(s)$ 或 $F(s)$ 形式

连续传递函数求 Z 变换的标准方法是**部分分式展开法**：先将 $G(s)$ 拆分为简单分式，查表求出对应的时域连续信号 $g(t)$，再进行离散采样并求 Z 变换。

#### **(12) & (13)** $G(s) = \frac{K}{s^{2} + 2\xi\omega_{n}s + \omega_{n}^{2}} \quad (0 \le \xi \le 1)$

- **解析**：

  此为典型的二阶欠阻尼系统。配方分母：$s^2 + 2\xi\omega_n s + \omega_n^2 = (s + \xi\omega_n)^2 + \omega_d^2$，其中阻尼振荡频率 $\omega_d = \omega_n\sqrt{1-\xi^2}$。

  为了利用拉氏变换表，分子配上 $\omega_d$：

  $$G(s) = \frac{K}{\omega_d} \cdot \frac{\omega_d}{(s + \xi\omega_n)^2 + \omega_d^2}$$

  反变换回时域连续信号：

  $$g(t) = \frac{K}{\omega_d} e^{-\xi\omega_n t} \sin(\omega_d t)$$

  对 $g(t)$ 进行采样并查 Z 变换表（指数正弦信号变换）：

  $$G(z) = \frac{K}{\omega_d} \cdot \frac{z e^{-\xi\omega_n T} \sin(\omega_d T)}{z^2 - 2z e^{-\xi\omega_n T} \cos(\omega_d T) + e^{-2\xi\omega_n T}}$$

  *(注：第 12 题即为 $K=1$ 的特殊情况)*

#### **(14)** $G(s) = \frac{k}{s(s^{2} + s + 1)}$

- **解析**：

  分母二阶项配方：$s^2 + s + 1 = (s + 0.5)^2 + (\frac{\sqrt{3}}{2})^2$。

  将 $G(s)$ 进行部分分式展开：

  $$G(s) = \frac{k}{s} - \frac{k(s+1)}{s^2+s+1} = \frac{k}{s} - \frac{k(s+0.5)}{(s+0.5)^2+(\frac{\sqrt{3}}{2})^2} - \frac{\frac{k}{\sqrt{3}} \cdot \frac{\sqrt{3}}{2}}{(s+0.5)^2+(\frac{\sqrt{3}}{2})^2}$$

  求拉氏反变换得到连续时间信号 $g(t)$：

  $$g(t) = k \cdot u(t) - k e^{-0.5t} \cos\left(\frac{\sqrt{3}}{2}t\right) - \frac{k}{\sqrt{3}} e^{-0.5t} \sin\left(\frac{\sqrt{3}}{2}t\right)$$

  对照标准时域信号的 Z 变换表转换（令 $\sigma = 0.5, \omega = \frac{\sqrt{3}}{2}$）：

  $$G(z) = \frac{kz}{z-1} - \frac{kz(z - e^{-\sigma T}\cos\omega T)}{z^2 - 2ze^{-\sigma T}\cos\omega T + e^{-2\sigma T}} - \frac{k}{\sqrt{3}} \frac{ze^{-\sigma T}\sin\omega T}{z^2 - 2ze^{-\sigma T}\cos\omega T + e^{-2\sigma T}}$$

  合并后即可得到最终的分式结果。

#### **(15)** $F(s) = \frac{3(1 - e^{-Ts})e^{-2.4Ts}}{s(5s + 1)}$

- **解析**：

  利用 Z 变换的延迟性质。包含因子 $e^{-mTs}$ 时，常将其剥离。

  注意到 $e^{-2.4Ts} = e^{-2Ts} \cdot e^{-0.4Ts}$，这里整数延迟为 $2$（对应 $z^{-2}$），分数延迟 $\Delta = 0.4$。

  本题结合了时域不连续采样，最严谨的方法通常需引入**修正 Z 变换**。但若在常规教学题目中，通常直接把纯延迟项化为 $z$ 的幂次：

  $$F(z) = 3 (1-z^{-1}) z^{-2} \cdot \mathcal{Z}\left\{ \frac{e^{-0.4Ts}}{s(5s+1)} \right\}$$

  对于 $\frac{1}{s(5s+1)} = \frac{1}{s} - \frac{1}{s+0.2}$，其对应的连续信号为 $1 - e^{-0.2t}$。受到 $e^{-0.4Ts}$ 延迟后，时域信号变为 $1 - e^{-0.2(t-0.4T)}$。采样后利用修正 Z 变换公式即可精确求解。

#### **(16)** $F(s) = \frac{K(1 - e^{-Ts})e^{-2Ts}}{s(s + 1)}$

- **解析**：

  由于含有环路中的零阶保持器环节 $(1-e^{-Ts})$ 和纯整数延迟 $e^{-2Ts}$，可以单独提出来转换为 $z$ 变量：

  $$\mathcal{Z}\{F(s)\} = K(1-z^{-1})z^{-2} \cdot \mathcal{Z}\left\{ \frac{1}{s(s+1)} \right\}$$

  对剩余部分进行部分分式展开：$\frac{1}{s(s+1)} = \frac{1}{s} - \frac{1}{s+1}$，对应时域信号为 $1 - e^{-t}$。

  求其 Z 变换：$\mathcal{Z}\left\{\frac{1}{s(s+1)}\right\} = \frac{z}{z-1} - \frac{z}{z-e^{-T}} = \frac{z(1-e^{-T})}{(z-1)(z-e^{-T})}$。

  代回原式：

  $$F(z) = K \frac{z-1}{z} \cdot z^{-2} \cdot \frac{z(1-e^{-T})}{(z-1)(z-e^{-T})} = \frac{K(1-e^{-T})}{z^2(z-e^{-T})}$$

#### **(17)** $F(s) = \frac{e^{-0.2Ts}}{s + a}$

- **解析**：

  延迟项 $e^{-0.2Ts}$ 包含非整数延迟。设纯延迟时间 $\tau = 0.2T$。

  由于 $\tau < T$，可以写成 $\tau = (1-m)T$，则 $m = 1 - 0.2 = 0.8$。

  利用**修正 Z 变换**处理，对于 $G(s) = \frac{1}{s+a}$，其修正 Z 变换公式为 $\mathcal{Z}_m\left\{\frac{1}{s+a}\right\} = \frac{e^{-amT}}{z - e^{-aT}}$。

  结合非整数延迟关系，最终结果为：

  $$F(z) = z^{-1} \cdot \frac{e^{-0.8aT}}{z - e^{-aT}} = \frac{e^{-0.8aT}}{z(z - e^{-aT})}$$

#### **(18)** $F(s) = \frac{1 - e^{-Ts}}{s} \cdot \frac{(s + a)e^{-1.4Ts}}{s + b}$

- **解析**：

  类似地，提取项 $(1-z^{-1})$。纯延迟部分 $e^{-1.4Ts} = e^{-Ts} \cdot e^{-0.4Ts}$，贡献一个 $z^{-1}$ 整数延迟以及一个 $\tau = 0.4T$ 的分数延迟（此时修正系数 $m = 1-0.4 = 0.6$）。

  原式转换为：

  $$F(z) = (1-z^{-1})z^{-1} \cdot \mathcal{Z}_m \left\{ \frac{s+a}{s(s+b)} \right\} \quad (\text{其中 } m=0.6)$$

  将大括号内进行拆分：$\frac{s+a}{s(s+b)} = \frac{a/b}{s} + \frac{1 - a/b}{s+b}$，再分别代入修正 Z 变换公式求解后乘以系数。

#### **(19)** $F(s) = \frac{b - a}{(s + a)(s + b)} \quad (a \ne b)$

- **解析**：

  进行部分分式展开：

  $$F(s) = \frac{1}{s+a} - \frac{1}{s+b}$$

  对应的时域连续信号为 $f(t) = e^{-at} - e^{-bt}$。

  离散采样后直接求 Z 变换：

  $$F(z) = \frac{z}{z - e^{-aT}} - \frac{z}{z - e^{-bT}} = \frac{z(e^{-aT} - e^{-bT})}{(z - e^{-aT})(z - e^{-bT})}$$

#### **(20)** $F(s) = \frac{s}{s^{2} + \omega^{2}}$

- **解析**：

  这是标准余弦信号的拉氏变换，对应的时域连续信号为 $f(t) = \cos(\omega t)$。

  直接查表采样信号的 Z 变换：

  $$F(z) = \frac{z(z - \cos\omega T)}{z^2 - 2z\cos\omega T + 1}$$

#### **(21)** $F(s) = \frac{se^{-0.6Ts}}{(s + 1)(s + 2)}$

- **解析**：

  包含非整数延迟 $e^{-0.6Ts}$，对应的延迟参数为 $\tau = 0.6T$，因此修正系数 $m = 1 - 0.6 = 0.4$。

  将原式除去延迟项后做部分分式展开：

  $$\frac{s}{(s+1)(s+2)} = \frac{-1}{s+1} + \frac{2}{s+2}$$

  利用修正 Z 变换的线性性质及常用公式 $\mathcal{Z}_m\left\{\frac{1}{s+a}\right\} = \frac{e^{-amT}}{z-e^{-aT}}$，并在最前方补上由于非整数延迟跨越周期带来的一个整体延迟 $z^{-1}$：

  $$F(z) = z^{-1} \left[ \frac{-e^{-0.4T}}{z - e^{-T}} + \frac{2e^{-0.8T}}{z - e^{-2T}} \right]$$

#### **(22)** $F(s) = \frac{1}{s(s + 1)^{2}}$

- **解析**：

  分母含有重根。部分分式展开为：

  $$F(s) = \frac{1}{s} - \frac{1}{s+1} - \frac{1}{(s+1)^2}$$

  反变换到时域：$f(t) = 1 - e^{-t} - t e^{-t}$。

  对其进行采样，得到离散序列：$f(nT) = 1 - e^{-nT} - nT e^{-nT}$。

  分别求 Z 变换：

  - $\mathcal{Z}\{1\} = \frac{z}{z-1}$
  - $\mathcal{Z}\{e^{-nT}\} = \frac{z}{z-e^{-T}}$
  - $\mathcal{Z}\{nT e^{-nT}\} = T \cdot \frac{z e^{-T}}{(z - e^{-T})^2}$ （利用复频移与时域乘 $n$ 性质）

  合并最终结果：

  $$F(z) = \frac{z}{z-1} - \frac{z}{z-e^{-T}} - \frac{T z e^{-T}}{(z-e^{-T})^2}$$

#### **(23)** $G(s) = \frac{Ke^{-2Ts}}{(s + a)(s + b)} \quad (a \ne b)$

- **解析**：

  带有 $2$ 个周期的纯整数延迟 $e^{-2Ts}$，对应算子 $z^{-2}$。

  对余下部分展开：$\frac{K}{(s+a)(s+b)} = \frac{K}{b-a}\left(\frac{1}{s+a} - \frac{1}{s+b}\right)$。

  根据第 (19) 题的结论，直接乘上整数延迟因子 $z^{-2}$：

  $$G(z) = z^{-2} \cdot \frac{K}{b-a} \cdot \frac{z(e^{-aT} - e^{-bT})}{(z - e^{-aT})(z - e^{-bT})} = \frac{K(e^{-aT} - e^{-bT})}{(b-a)z(z - e^{-aT})(z - e^{-bT})}$$

## 二、 求修正 Z 变换详细解析

#### **(1)** 求 $F(s) = e^{-at}$ 的修正 Z 变换

- **解析**：

  *(注：原题面写为 $F(s)=e^{-at}$，从上下文看应为时域函数 $f(t)=e^{-at}$ 求修正 Z 变换)*

  修正 Z 变换引入了延迟因子 $m$（$0 \le m \le 1$），定义为对连续信号延迟 $\tau = (1-m)T$ 后再进行常规 Z 变换。

  延迟后的信号为：$f(t - (1-m)T) = e^{-a[t - (1-m)T]}$。

  在采样点 $t = nT$ 处的序列值为：

  $$f(nT - (1-m)T) = e^{-a[nT - T + mT]} = e^{-amT} \cdot e^{-a(n-1)T}$$

  对该序列求 Z 变换（注意 $n$ 从 1 开始计入因果系统）：

  $$F(z, m) = \sum_{n=1}^{\infty} e^{-amT} e^{-a(n-1)T} z^{-n}$$

  令 $k = n-1$，级数变换为：

  $$F(z, m) = e^{-amT} z^{-1} \sum_{k=0}^{\infty} (e^{-aT} z^{-1})^k = e^{-amT} z^{-1} \cdot \frac{1}{1 - e^{-aT}z^{-1}} = \frac{e^{-amT}}{z - e^{-aT}}$$

## 三、 求 Z 反变换详细解析

常用的 Z 反变换方法有**留数法（部分分式法）\**和\**幂级数展开法（长除法）**。这里推荐使用部分分式法。

#### **(1)** $F(z) = \frac{z(1 - e^{-T})}{(z - 1)(z - e^{-T})}$

- **解析**：

  首先两边同除以 $z$（便于部分分式拆分）：

  $$\frac{F(z)}{z} = \frac{1 - e^{-T}}{(z - 1)(z - e^{-T})}$$

  设其等于 $\frac{A}{z-1} + \frac{B}{z-e^{-T}}$，利用待定系数法（留数法）：

  - $A = \left. \frac{1 - e^{-T}}{z - e^{-T}} \right|_{z=1} = \frac{1 - e^{-T}}{1 - e^{-T}} = 1$
  - $B = \left. \frac{1 - e^{-T}}{z - 1} \right|_{z=e^{-T}} = \frac{1 - e^{-T}}{e^{-T} - 1} = -1$

  由此得到：

  $$\frac{F(z)}{z} = \frac{1}{z-1} - \frac{1}{z-e^{-T}} \implies F(z) = \frac{z}{z-1} - \frac{z}{z-e^{-T}}$$

  对照常见 Z 变换表反变换回时域：

  $$f(nT) = 1 - e^{-nT} \quad (n \ge 0)$$

#### **(2)** $F(z) = \frac{z}{z^{3} - 4z^{2} + 5z - 2}$

- **解析**：

  首先对分母进行因式分解。通过观察或试根法可以发现 $z=1$ 是分母的一个根：

  $$z^3 - 4z^2 + 5z - 2 = (z-1)(z^2 - 3z + 2) = (z-1)^2(z-2)$$

  同样，两边先同除以 $z$：

  $$\frac{F(z)}{z} = \frac{1}{(z-1)^2(z-2)}$$

  由于含有重根 $(z-1)^2$，展开形式应为：

  $$\frac{F(z)}{z} = \frac{A}{z-2} + \frac{B}{(z-1)^2} + \frac{C}{z-1}$$

  利用留数法计算系数：

  - $A = \left. \frac{1}{(z-1)^2} \right|_{z=2} = \frac{1}{1} = 1$
  - $B = \left. \frac{1}{z-2} \right|_{z=1} = \frac{1}{1-2} = -1$
  - $C = \left. \frac{d}{dz} \left( \frac{1}{z-2} \right) \right|_{z=1} = \left. -\frac{1}{(z-2)^2} \right|_{z=1} = -1$

  还原出 $F(z)$：

  $$F(z) = \frac{z}{z-2} - \frac{z}{(z-1)^2} - \frac{z}{z-1}$$

  查表逐项进行反变换：

  - $\mathcal{Z}^{-1}\left\{\frac{z}{z-2}\right\} = 2^n$
  - $\mathcal{Z}^{-1}\left\{\frac{z}{(z-1)^2}\right\} = n$
  - $\mathcal{Z}^{-1}\left\{\frac{z}{z-1}\right\} = 1$

  最终得到离散时间序列结果：

  $$f(n) = 2^n - n - 1 \quad (n \ge 0)$$