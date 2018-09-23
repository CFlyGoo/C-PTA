cmake_minimum_required(VERSION 3.12)
project(c_pta C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(qq-register-and-login src/qq-register-and-login.c)

add_executable(array-two-stack src/array-two-stack.c test/array-two-stack-test.c)