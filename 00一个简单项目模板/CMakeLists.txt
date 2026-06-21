cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 设置头文件路径（让编译器找到 include 文件夹）
include_directories(include)

# 自动把 src/ 下所有 .cpp 文件都加进来
file(GLOB SRC_FILES src/*.cpp)

# 生成可执行程序
add_executable(myapp ${SRC_FILES})