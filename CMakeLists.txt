cmake_minimum_required(VERSION 3.23)
project(facebook)

set(CMAKE_CXX_STANDARD 14)

add_executable(facebook main.cpp date.cpp date.h time.cpp time.h status.cpp status.h billboard.cpp billboard.h fansPage.cpp fansPage.h)
