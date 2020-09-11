cmake_minimum_required(VERSION 3.10)
project(efrei_l3_se_tp3_mutex C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")

add_executable(efrei_l3_se_tp3_mutex main.c)