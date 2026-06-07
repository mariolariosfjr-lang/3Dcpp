cmake_minimum_required(VERSION 3.15...3.30)
project(Engine3D VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find System Graphics Dependencies
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED) 

# 1. Define Compiled Library and Map Source File
add_library(Engine3D src/3dcpp.cpp)
add_library(Engine3D::Engine3D ALIAS Engine3D)

# 2. Configure Include Interfaces
target_include_directories(Engine3D PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# 3. Connect App Execution Binary
add_executable(demo main.cpp)

# 4. Link your engine target alongside real graphics hardware libraries
target_link_libraries(demo PRIVATE 
    Engine3D::Engine3D 
    OpenGL::GL 
    glfw
)
