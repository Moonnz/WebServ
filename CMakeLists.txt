cmake_minimum_required(VERSION 3.10)
project(ThreadTest)

set(CMAKE_CXX_STANDARD 11)
find_package (Threads)
add_executable(ThreadTest main.cpp web_serv.cpp web_serv.h decl.h)
target_link_libraries (ThreadTest ${CMAKE_THREAD_LIBS_INIT})