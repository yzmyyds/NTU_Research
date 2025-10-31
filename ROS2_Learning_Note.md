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
