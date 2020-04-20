cmake_minimum_required(VERSION 3.5)

project(fightingGame LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(fightingGame
  main.cpp
  character.cpp
)
