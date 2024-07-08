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
        src/route_coordinate/route_coordinate.h
        src/route_coordinate/route_coordinate.cpp
        src/state_buffer/state_buffer.h
        src/state_buffer/state_buffer.cpp
        src/draw/draw_engine.h
        src/objects/object.h
        src/objects/object.cpp
        src/draw/draw_engine.cpp
        include/curses.h
        src/objects/object_map.h
        src/objects/voltage.h
        src/board/board.cpp
        src/board/board.h
        src/objects/action.h
)

target_link_libraries(simple_game ${CURSES_LIBRARIES})
