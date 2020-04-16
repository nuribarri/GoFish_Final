cmake_minimum_required(VERSION 3.15)
project(GoFish)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(GoFish
        card.cpp
        card.h
        deck.cpp
        deck.h
        GoFish_Driver.cpp
        output.txt
        player.cpp
        player.h)
