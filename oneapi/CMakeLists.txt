cmake_minimum_required(VERSION 3.16)
project(host-accessor-waits-for-asynchronous-kernel-execution)

set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(host-accessor-waits-for-asynchronous-kernel-execution
  host-accessor-waits-for-asynchronous-kernel-execution.cpp
)

target_compile_options(host-accessor-waits-for-asynchronous-kernel-execution PRIVATE 
  -std=c++20 -stdlib=libstdc++
)

