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

    void loadLevel(const std::string& path);

    BOARD_STATES getState() const;

    bool isPositionFree(const Coordinate& coordinate) const;
    void handleBufferMove(const Coordinate& newCoordinate, const Object &object) const;
    void handleBufferCollision(const Coordinate& coordinate, const Object &object) const;

    void updateHero(const char &key) const;
    void updateEnemy() const;
    void updateVoltages() const;
};


