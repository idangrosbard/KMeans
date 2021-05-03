cmake_minimum_required(VERSION 3.17)
project(KMeans C)

set(CMAKE_C_STANDARD 90)

add_executable(KMeans main.c kmeans_algo.h kmeans_file_input.h kmeans_file_input.c linked_list.h linked_list.c bool.h linked_list_tests.h linked_list_tests.c)