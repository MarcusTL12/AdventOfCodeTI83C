cmake_minimum_required(VERSION 3.10)

project(AoC_TI83C C)

set(CMAKE_C_COMPILER_WORKS 1)

add_link_options(-create-app)

add_executable(
    aoc
    ${YEAR}/day${DAY}/part${PART}.c
    build/${INPUT}.c
)
