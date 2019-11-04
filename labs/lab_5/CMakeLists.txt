cmake_minimum_required(VERSION 3.14)
project(lab_5 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab_5_sa section_a.c)
add_executable(lab_5_sb section_b.c fxnprot.h masks.h)
