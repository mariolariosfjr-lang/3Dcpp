cmake_minimum_required(VERSION 3.15...3.30)
project(Engine3D VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find System Graphics Dependencies
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED) # Make sure GLFW is installed via your package manager

# Define Header-only Library
add_library(Engine3D INTERFACE)
add_library(Engine3D::Engine3D ALIAS Engine3D)

target_include_directories(Engine3D INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Connect App Execution Binary
add_executable(demo main.cpp)

# Link your engine target alongside real graphics hardware rendering contexts
target_link_libraries(demo PRIVATE 
    Engine3D::Engine3D 
    OpenGL::GL 
    glfw
)

