cmake_minimum_required(VERSION 3.16)

add_library(
  Cooldownmask
  STATIC
  Cooldownmask.hpp
  Cooldownmask.cpp
)

target_link_libraries(
  Cooldownmask
  GameObject
  GameWorld
)

target_include_directories(
  Cooldownmask
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
   ${CMAKE_SOURCE_DIR}/src/Cooldownmask/
)