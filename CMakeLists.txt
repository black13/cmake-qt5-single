  
cmake_minimum_required(VERSION 3.5)

project(single)

# Find includes in the build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Turn on automatic invocation of the MOC, UIC & RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

find_package(Qt5 COMPONENTS Qml Core Widgets REQUIRED)

find_package(Qt5 REQUIRED COMPONENTS Widgets Core Gui Sql PrintSupport Test)

add_executable(single main.cpp)

target_link_libraries(single Qt5::Widgets Qt5::Qml Qt5::Test) 