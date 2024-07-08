#pragma once

#include <string>
#include <vector>

#include <objects/enemy.h>
#include <objects/hero.h>
#include "objects/voltage.h"

#include "state_buffer/state_buffer.h"

enum BOARD_STATES {
    NO_STATE,
    NO_HERO,
    NO_ENEMIES
};

class Board {
    Hero* hero = nullptr;
    Enemy* enemy = nullptr;
    std::vector<Voltage>* voltages = nullptr;
public:
    StateBuffer* buffer = nullptr;

    int width = 0;
    int height = 0;

    Board() = default;

    void Board::loadLevel(const std::string& path);

    BOARD_STATES getState() const;

    bool isPositionFree(const Coordinate& point) const;
    void handleMove(const Coordinate& newCoordinate, const Object &object) const;
    void handleCollision(const Coordinate& coordinate, const Object &object);

    void updateHero(const char& key);
    void updateEnemy();
    void updateVoltages();
};


