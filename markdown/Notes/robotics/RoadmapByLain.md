# 机器人学习路线图

> 整理自 Lain 的机器人学习建议

## 一、通用能力

### 1. 基础开发平台与网络能力

#### 学术与开源资源访问

能够熟练使用学校的学术访问权限，顺畅访问 IEEE Xplore、Springer 等数据库和海外开发资源；熟练使用 GitHub 进行开源项目检索和版本管理。

#### 个人主页搭建

能够在大一搭建起个人主页（如 GitHub Pages），用于持续更新和积累后续的项目与赛事成果。

#### Linux 操作系统使用

掌握 Linux 系统安装与环境配置，熟练使用终端进行文件操作、软件安装和权限管理。

#### ROS 2 开发框架

熟练掌握 2026 年主流的 ROS 2 开发环境（新项目优先使用 Ubuntu 24.04 LTS + ROS 2 Jazzy），不盲从过期博客，能按官方教程独立跑通命令行、topic/service/action、launch、tf2 和 URDF，并具备多机通信的基础网络配置能力。

---

### 2. 数学基础能力

#### 微积分与线性代数（核心）

必须具备对分块矩阵、零空间投影、SVD（奇异值分解）等概念的"身体直觉"，能够看懂并推导四足机器人 WBC（全身控制）、正逆运动学、力控算法及凸优化中的矩阵公式。

#### 机器人学基础理论

能同步参考《Modern Robotics》等教材，在大一大二建立起指数坐标、screw axis（螺旋轴）等术语体系，配合 Python 代码库进行推导验证。

---

### 3. 工具英语能力

#### 工程英语阅读

摆脱对应试分数的依赖，能够不依赖 AI 独立读懂外文芯片手册、开源项目 README 说明文档以及顶会论文。

---

### 4. 编程语言与工程构建能力（拒绝 AI 依赖）

#### Python 语言

熟练运用 Python 进行神经网络实现、仿真搭建与前期数据处理验证，并统一使用 Miniconda 进行轻量化的环境管理。

#### C 语言

熟练掌握 C 语言，作为工业级嵌入式开发和底层实时控制逻辑的基本功。

#### C++ 语言

大一阶段完成基础语法入门即可，用于后续算法在实机部署时的执行效率提升。

#### CMake 项目构建

在学完 C/C++ 后必须同步掌握，用于处理超过 3 个文件的中大型项目中的头文件管理、多文件编译与跨平台构建。

---

### 5. 动手实践与量化设计能力

#### 低成本动手闭环

能够利用开源项目（如机械臂 SO-ARM100、四足 StanfordQuadruped 等），低成本动手跑通机械、电控和控制算法的"最小闭环"。

#### 量化设计与仿真转型

拒绝盲目改结构试错和手动瞎拧 PID。必须具备面向对象的开发思维、熟练使用状态机梳理控制逻辑，并提早使用 MATLAB / MuJoCo 等仿真工具进行模型估算与参数预调。

---

## 二、规划与导航能力

### 1. 移动导航入门

- **核心工具链：** 以 **ROS 2 Nav2** 为主线。
- **前置基础：** 优先阅读 Nav2 的[官方文档](https://navigation.ros.org/)与 tutorials，切忌参考易过期的中文博客。
- **基础概念理解：**
  - 理解 **TF 坐标变换**。
  - 掌握传感器数据接入（LaserScan/PointCloud）。
  - 掌握代价地图配置（涵盖 static/global/local 三层）。
  - 掌握 AMCL 定位。
- **规划器配置：** 先跑通 SmacPlanner 的 **Hybrid-A*** 和 **2D A***，随后进行局部规划器（**DWB/MPPI**）的调参。
- **流程编排：** 理解如何利用行为树（Behavior Tree）编排整个导航流程。
- **算法直觉建立（进阶前）：** 在进入 ROS 2 之前，可刷 [PythonRobotics](https://github.com/AtsushiSakai/PythonRobotics) 库，摸清 **A***、**Dijkstra**、**RRT**、**MPC**、**Pure Pursuit** 的最小实现与算法骨架。
- **动手项目：** 在 **Gazebo** 中搭建差分驱动移动底盘，完成 Nav2 参数配置，在室内仿真中实现定点导航、巡逻模式和动态避障。
- **高阶开发：** 基于特定场景需求修改 costmap layer 或定制规划器插件；在 Gazebo 中跑三台 TurtleBot 实现多机器人协同导航，处理碰撞避免与路径协调。

### 2. 机械臂运动规划

- **核心工具链：** **MoveIt2** 为入门第一站。
- **基础配置：** 按照 [MoveIt 2 官方教程](https://moveit.picknik.ai/)导入机械臂 URDF，通过 Setup Assistant 配置碰撞矩阵、规划组和位姿。
- **API 与规划器调用：** 使用 Python/C++ MoveIt2 API 调用 **OMPL** 规划器，配置轨迹时间参数化，在仿真中实现 **pick-and-place（抓取与放置）**。
- **核心理论理解：**
  - 理解运动学求解器（明确 **KDL** 和 **TRAC-IK** 的区别）。
  - 掌握 OMPL 各类规划器（**RRT / RRTConnect / RRT***）的各自适用场景。
  - 理解碰撞检测中 **meshing 精度**对规划成功率的影响。
- **轨迹生成与参数化：** 学习工业机械臂常见的 [Ruckig](https://github.com/pantor/ruckig)（偏在线轨迹生成）与 [TOPP-RA](https://github.com/leisun/toppra)（偏路径参数化）。
- **系统联调优化：** 尝试做自定义约束（如力控方向约束和姿态约束），并在 **Isaac Sim** 或 **MuJoCo** 中与控制代码联调，使轨迹生成、控制执行、视觉反馈和在线重规划组成可调试的工程系统。

### 3. 多机器人调度与行为树

- **多机器人调度算法：** 从 CBS（基于冲突搜索）算法入手，理解 MAPF（多智能体路径规划）问题如何利用网格图、时间步和约束依赖图进行建模。
- **多机通信与仿真：** 在 Stage 或 Gazebo 里搭多机器人仿真，处理 ROS 2 多机通信中的 **namespace 隔离**和 **DDS domain 配置**。
- **工程集成框架：** 学习 [Open-RMF](https://github.com/open-rmf/rmf) 框架，理解真实场景下的 fleet adapter、任务调度、交通管制以及门禁电梯集成的复杂度。
- **行为树技术：** 必修 [BehaviorTree.CPP](https://github.com/BehaviorTree/BehaviorTree.CPP)。先理解 **Sequence**、**Fallback**、**Parallel**、**Decorator** 等节点，随后手写一个涵盖 costmap 异常检测、清除、重定位和重新规划的导航恢复行为树，并将其嵌入 Nav2 的行为树插件体系。
- **核心进阶目标：** 掌握工程系统整合能力——对齐调度层、规划层、控制层的时序，并制定异常场景（规划失败、通信中断、定位漂移）的降级策略。

---

## 三、运动控制能力

### 1. 数学打底与仿真先行

- **数学与理论基础：**
  - **线性代数：** 必须拿下矩阵变换、特征值、SVD（奇异值分解），这是进行状态空间和 LQR（线性二次型调节器）开发每天必见的基础。
  - **微积分：** 侧重于 ODE（常微分方程）数值求解和优化理论的基本概念。
  - **自动控制原理：** 建立 PID 的频域理解，拒绝盲目调参；必须掌握根轨迹法、状态空间方程的基本概念。
  - **推荐学习资源：** 参考 MIT 的 [Underactuated Robotics](https://underactuated.mit.edu/)（配有 MuJoCo 的 notebook 可直接上手）以及 Brian Douglas 的 [YouTube 系列视频](https://www.youtube.com/user/ControlLectures)。

- **机器人学基础：**
  - **正逆运动学：** 掌握 DH 参数法、几何法、数值解。
  - **雅可比矩阵：** 理解速度级运动学和静力传递。
  - **动力学建模：** 掌握拉格朗日法和牛顿欧拉法。
  - **硬核通关任务：** 亲手推导一个 2 自由度机械臂的运动学和动力学，再用 MATLAB 的 Robotics Toolbox 或 [robotics-toolbox-python](https://github.com/petercorke/robotics-toolbox-python) 进行数值验证（必须先手推再计算）。

- **入门项目实践：**
  - 在 **MATLAB/Simulink** 中搭建倒立摆或两轮平衡车的仿真模型，实现 PID 控制和 LQR 控制，并对比两者的稳定裕度和鲁棒性。
  - 习惯使用 **Simscape Multibody** 将 Simulink 模型做成三维可视化，以便直观观察机器人翻倒形态、高效调参。

### 2. LQR、MPC 与强化学习

- **基于模型的控制（最优控制）：**
  - **LQR：** 从倒立摆控制开始，理解代价函数 Q/R 矩阵的工程含义，进阶至整机全身控制（WBC）的 QP（二次规划）问题构建。
  - **MPC（模型预测控制）：** 重点掌握模型离散化、预测时域设计、滚动优化求解和约束处理。参考 MIT 的 MPC 讲义，并使用 [acados](https://github.com/acados/acados) 或 [OSQP](https://github.com/osqp/osqp) 求解器完成简单四旋翼的轨迹跟踪 MPC（先调包理解框架，不要盲目手写求解器）。

- **物理仿真工具链：**
  - **主力仿真器：** 首选 [MuJoCo](https://mujoco.org/)（轻量、快速、RL 训练友好、Python 绑定完善）。
  - **开发工作流：** 在 MuJoCo 中搭建模型或导入 URDF，编写控制器并做仿真验证，参数稳定后将控制代码迁移到 ROS 2 的 **ros2_control** 框架。
  - **模型与辅助工具：** 参考 DeepMind 的 [MuJoCo Menagerie](https://github.com/google-deepmind/mujoco_menagerie) 获取常见机器人模型；使用 [URDF Viewer](https://goforward.github.io/urdf-viewer/) 等网页预览工具提升修改 URDF/Xacro 的效率。
  - **工具辨析：** Isaac Sim 适合高保真渲染和多传感器仿真，但吃 GPU，做快速原型验证的流畅度不如 MuJoCo。
