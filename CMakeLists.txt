cmake_minimum_required(VERSION 3.0)
project(nbtc LANGUAGES C)

add_library(
    nbtc

    source/nbtc.c
    include/nbtc.h
)

target_include_directories(nbtc PUBLIC include)