#pragma once
#include <draw/texture_colors.h>

enum GameObject {
    Carpet = 0,
    Boxes = 1,
    Hero = 2,
    Enemy = 3,
    Wall_TopLeft = 4,
    Wall_BottomLeft = 5,
    Wall_TopRight = 6,
    Wall_BottomRight = 7,
    Wall_Horizontal = 8,
    Wall_Vertical = 9,
    Volt = 10
};

inline int getColorPair(const GameObject& obj) {
    switch (obj) {
        case Carpet: return Carpet_Pair;
        case Boxes: return Boxes_Pair;
        case Hero: return Hero_Pair;
        case Enemy: return Enemy_Pair;
        case Wall_TopLeft:
        case Wall_BottomLeft:
        case Wall_TopRight:
        case Wall_BottomRight:
        case Wall_Horizontal:
        case Wall_Vertical: return Wall_Pair;
        case Volt: return Volt_Pair;
        default: return 0;
    }
}

inline wchar_t getSymbol(GameObject obj) {
    switch (obj) {
        case Carpet: return ' ';
        case Boxes: return 9604;
        case Hero:
        case Enemy: return 167;
        case Wall_TopLeft: return 9556;
        case Wall_BottomLeft: return 9562;
        case Wall_TopRight: return 9559;
        case Wall_BottomRight: return 9565;
        case Wall_Horizontal: return 9552;
        case Wall_Vertical: return 9553;
        case Volt: return 1161;
        default: return L'?';
    }
}