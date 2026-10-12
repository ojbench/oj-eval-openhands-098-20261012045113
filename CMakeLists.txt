cmake_minimum_required(VERSION 3.10)
project(BSTNodeFinder)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set compiler flags for better warnings and optimization
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")

# Add executable
add_executable(code main.cpp)