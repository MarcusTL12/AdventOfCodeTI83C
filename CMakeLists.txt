cmake_minimum_required(VERSION 3.10)

project(AoC_TI83C C)

if(NOT INPUT)
    set(INPUT input)
endif()

set(CMAKE_C_FLAGS "+ti83 -compiler=sdcc -SO3")

add_link_options(-create-app)

add_executable(
    aoc
    ${YEAR}/day${DAY}/part${PART}.c
    ${YEAR}/day${DAY}/${INPUT}.c
)
