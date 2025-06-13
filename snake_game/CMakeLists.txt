cmake_minimum_required(VERSION 3.10)
project(snake_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# SDL2
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})
link_directories(${SDL2_LIBRARY_DIRS})

# Tìm source files
file(GLOB_RECURSE SOURCES "src/*.cpp" )

add_executable(snake_game ${SOURCES})

target_link_libraries(snake_game ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES})
