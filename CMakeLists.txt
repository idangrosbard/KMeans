cmake_minimum_required(VERSION 3.17)
project(KMeans C)

set(CMAKE_C_STANDARD 90)

add_executable(KMeans main.c kmeans_algo.h)