cmake_minimum_required(VERSION 3.29)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        scr/ServerMetric.cpp
        scr/AlertManager.cpp
        scr/ServerMonitor.cpp
        scr/SlidingWindow.cpp)
