cmake_minimum_required(VERSION 3.10)

project(AoC_TI83C C)

add_link_options(-create-app)

add_executable(
    aoc
    ${YEAR}/day${DAY}/part${PART}.c
    build/${INPUT}.c
)

target_include_directories(aoc PRIVATE util)
