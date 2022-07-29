cmake_minimum_required(VERSION 3.0)
project(segment_tree)

# 设置调试信息
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++2a -fPIC")

# 设置项目库文件输出路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 配置头文件信息
include_directories(${PROJECT_SOURCE_DIR}/include)

# 定义了SRC_LIST变量，包含当前目录下所有的源文件
aux_source_directory(. SRC_LIST)

# add_executable(segment_tree ${SRC_LIST})

# 生成静态库
add_library(segment_tree_static STATIC ${SRC_LIST}) 
# 生成动态库
add_library(segment_tree_shared SHARED ${SRC_LIST})