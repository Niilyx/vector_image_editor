cmake_minimum_required(VERSION 3.24)
project(vector_image_editor C)

set(CMAKE_C_STANDARD 99)

add_executable(vector_image_editor src/main.c src/utils/print_utils.c src/utils/print_utils.h src/states.h src/shapes.c src/shapes.h src/main.h)
