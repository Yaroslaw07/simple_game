#pragma once

#include <string>
#include <vector>
#include <memory>

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
    std::unique_ptr<Hero> hero = nullptr;
    std::unique_ptr<Enemy> enemy = nullptr;
    std::vector<Voltage> voltages;

    int enemyMoveDelay = 5;
    int enemyMoveTimer = 0;
public:
    std::unique_ptr<StateBuffer> buffer = nullptr;

    int width = 0;
    int height = 0;

    Board();
    ~Board();

    void loadLevel(const std::string& path);

    BOARD_STATES getState() const;

    bool isPositionFree(const Coordinate& coordinate) const;
    void handleBufferMove(const Coordinate& newCoordinate, const Object &object) const;
    void handleBufferCollision(const Coordinate& toCollisionCoordinate, const Object &object);

    void breakObject(const Coordinate& coordinate);

    void updateHero(const char &key);
    void updateEnemy();
    void updateVoltages();

private:
    std::vector<Coordinate> getValidMoves(const Coordinate& location) const;
};


