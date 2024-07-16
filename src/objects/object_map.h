#pragma once
#include <draw/texture_colors.h>

enum GAME_OBJECTS {
    CARPET = 0,
    BOX = 1,
    HERO = 2,
    ENEMY = 3,
    WALL_TOP_LEFT = 4,
    WALL_BOTTOM_LEFT = 5,
    WALL_TOP_RIGHT = 6,
    WALL_BOTTOM_RIGHT = 7,
    WALL_HORIZONTAL = 8,
    WALL_VERTICAL = 9,
    VOLT = 10
};

inline TexturesColors getColorPair(const GAME_OBJECTS& obj) {
    switch (obj) {
        case CARPET: return Carpet_Pair;
        case BOX: return Boxes_Pair;
        case HERO: return Hero_Pair;
        case ENEMY: return Enemy_Pair;
        case WALL_TOP_LEFT:
        case WALL_BOTTOM_LEFT:
        case WALL_TOP_RIGHT:
        case WALL_BOTTOM_RIGHT:
        case WALL_HORIZONTAL:
        case WALL_VERTICAL: return Wall_Pair;
        case VOLT: return Volt_Pair;
        default: return Carpet_Pair;
    }
}

inline wchar_t getSymbol(const GAME_OBJECTS& obj) {
    switch (obj) {
        case CARPET: return ' ';
        case BOX: return L'\u9604';
        case HERO:
        case ENEMY: return L'$';
        case WALL_TOP_LEFT: return L'\u2551';
        case WALL_BOTTOM_LEFT: return L'\u25F1';
        case WALL_TOP_RIGHT: return L'╗';
        case WALL_BOTTOM_RIGHT: return 9565;
        case WALL_HORIZONTAL: return 9552;
        case WALL_VERTICAL: return 9553;
        case VOLT: return '~';
        default: return L'?';
    }
}