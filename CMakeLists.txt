cmake_minimum_required(VERSION 3.28)
project(simple_game)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(simple_game main.cpp include/curses.h
        src/Game.h
        src/Game.cpp
        src/board/route_coordinate.h
        src/board/route_coordinate.cpp
        src/board/Storage.h
        src/board/storage.cpp
        src/draw/draw_engine.h
        src/objects/Object.h
        src/objects/object.cpp
        src/objects/enemy/enemy.cpp
        src/objects/hero/hero.cpp
        src/objects/voltage/voltage.cpp
        src/draw/draw_engine.cpp
)

find_path(PDC_INCLUDES curses.h HINTS ${CMAKE_CURRENT_SOURCE_DIR}/include REQUIRED)
find_library(PDC_LIBS pdcurses HINTS ${CMAKE_CURRENT_SOURCE_DIR}/lib REQUIRED)

target_include_directories(simple_game PRIVATE ${PDC_INCLUDES})
target_link_libraries(simple_game PRIVATE ${PDC_LIBS})