cmake_minimum_required(VERSION 3.16)

add_library(
  Planting_Spot
  STATIC
  Planting_Spot.hpp
  Planting_Spot.cpp
)

target_link_libraries(
  Planting_Spot
  GameObject
  GameWorld
  Plant
)

target_include_directories(
  Planting_Spot
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/Planting_Spot/
  ${CMAKE_SOURCE_DIR}/src/Plant/
)