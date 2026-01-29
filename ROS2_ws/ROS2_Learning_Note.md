# ROS2 学习日志
***
>2025/10/31

## 环境搭建（*基于 WSL2*）
版本选择：
- Ubuntu 22.04 + ROS2 Humble
- Ubuntu 24.04 + ROS2 Jazzy

Ubuntu与ROS2版本应相互对应，否则容易引起版本冲突。

以 **Ubuntu 22.04 + ROS2 Humble** 为例：
1. 添加 ROS2 apt 源
```bash
sudo apt update && sudo apt install -y software-properties-common
sudo add-apt-repository universe
sudo apt update
sudo apt install -y curl gnupg lsb-release
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
sudo apt update
```
2. 安装 ROS2 Desktop
```bash
sudo apt install ros-humble-desktop
```
3. 配置环境变量
```bash
echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
source ~/.bashrc
```
4. 安装编译工具及依赖
```bash
sudo apt install -y python3-colcon-common-extensions python3-rosdep python3-argcomplete
sudo rosdep init
rosdep update
```
5. 测试turtle

> 2025/11/1
## 配置、编写与编译
1. 创建工作空间
```bash
mkdir -p ~/ros2_ws/src
cd ~/ros2_ws
colcon build
```
2. 创建功能包
- Cpp：
  ```bash
  ros2 pkg create --build-type ament_cmake my_cpp_pkg --dependencies rclcpp --node-name helloworld_node
  ```
- Python:
  ```bash
  ros2 pkg create --build-type ament_python my_python_pkg --dependencies rclpy --node-name helloworld_node
  ```
3. 编译（回到工作空间）
```bash
colcon build
```
4. 执行
```bash
source install/setup.bash
ros2 run my_cpp_pkg helloworld_node

ros2 run my_python_pkg helloworld_node
```
## 基本语法

### Cpp 语法

> 2026/01/26
## Intro:
Since doing dissertation, I successfully get the permission to use the EEE cluster server, which contains A6000 and A5000 GPUs, much better than mine. I do not want to waste this source, so I decide to transmit my study from WSL to online server. Following is my progress.

## Environment & Infrastructure

- __Storage Strategy:__ Defined a clear boundary between your SSD (20GB) for high-frequency compilation/I/O and HDD (50GB) for bulk data storage.

- __Permission Bypass:__ Successfully bypassed sudo restrictions by installing ROS2 and ```colcon``` tools directly into your SSD directory using ```Mamba``` and the ```--prefix``` flag.

- __Resource Management__: Mastered the use of srun to hijack GPU A5000 nodes for high-performance robotics development.

## Engineering Workflow
- __Workspace Mastery:__ Established a standard ROS2 workspace (learning_ws).

- __Automation:__ Configured .bashrc aliases to automate the "```loading``` → ```activating``` → ```navigating``` → ```sourcing```" sequence in one command.

- __Development Cycle:__ Successfully executed the standard ROS2 development loop: Modify Code → colcon build → source → ros2 run.