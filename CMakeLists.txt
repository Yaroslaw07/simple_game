cmake_minimum_required(VERSION 3.28)
project(simple_game)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)



find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(simple_game main.cpp
        src/game.h
        src/game.cpp
        src/board/route_coordinate.h
        src/board/route_coordinate.cpp
        src/board/engine_buffer.h
        src/board/engine_buffer.cpp
        src/draw/draw_engine.h
        src/objects/object.h
        src/objects/object.cpp
        src/objects/enemy/enemy.cpp
        src/objects/hero/hero.cpp
        src/objects/voltage/voltage.cpp
        src/draw/draw_engine.cpp
        include/curses.h
        src/objects/object_map.h
)

target_link_libraries(simple_game ${CURSES_LIBRARIES})
