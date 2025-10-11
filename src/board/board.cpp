#include "board.h"

#include <algorithm>
#include <fstream>
#include <stdexcept>

#include <iostream>

Board::Board() = default;
Board::~Board() = default;

void Board::loadLevel(const std::string& path)
{
    std::ifstream in(path);

    if (!in.is_open()) {
        throw std::runtime_error("Error: Unable to open level file.");
    }

    int index;
    in >> width >> height;

    buffer = std::make_unique<StateBuffer>(width, height);

    for (int Y = 0; Y < height; Y++) {
        for (int X = 0; X < width; X++) {
            in >> index;


            const Coordinate coordinate(X, Y);

            switch(index) {
                case HERO:
                    if (hero != nullptr) {
                        index = CARPET;
                    } else {
                        hero = std::make_unique<Hero>(coordinate, 5, 'w', 's', 'a', 'd', ' ');
                    }
                break;
                case ENEMY:
                    enemy = std::make_unique<Enemy>(coordinate, 3);
                break;
                case VOLT:
                    index = CARPET;
                default:
                break;
            }

            buffer->setObject({X, Y}, static_cast<GAME_OBJECTS>(index));
        }
    }

    in.close();
}

BOARD_STATES Board::getState() const {
    if (hero == nullptr || !hero->isAlive()) {
        return NO_HERO;
    }

    if (enemy == nullptr || !enemy->isAlive()) {
        return NO_ENEMIES;
    }

    return NO_STATE;
}


bool Board::isPositionFree(const Coordinate& coordinate) const {
    return buffer->get(coordinate) == CARPET;
}

void Board::handleBufferMove(const Coordinate &newCoordinate,const Object &object) const {
    buffer->eraseObject(object.getLocation());
    buffer->setObject(newCoordinate, object.getObjectType());
}

void Board::handleBufferCollision(const Coordinate &toCollisionCoordinate,const Object &object) {
    if (object.getObjectType() != VOLT) {
        return;
    }

    const GAME_OBJECTS collisionObject = buffer->get(toCollisionCoordinate);

    if (collisionObject == CARPET) {
        return;
    }

    if (collisionObject == BOX) {
        breakObject(toCollisionCoordinate);
    }

    if (hero && hero->getLocation() == toCollisionCoordinate) {
        hero->eraseLives(1);
    }

    if (enemy && enemy->getLocation() == toCollisionCoordinate) {
        enemy->eraseLives(1);
    }

    buffer->eraseObject(object.getLocation());
}

void Board::breakObject(const Coordinate& coordinate) {
    buffer->setObject(coordinate, CARPET);
}


void Board::updateHero(const char &key) {
    if (!hero) {
        return;
    }

    const ACTION_TYPE action = hero->getAction(key);

    if (action == ACTION_TYPE::MOVE) {
        if (const Coordinate newCoordinate = hero->getLocation() + hero->getRoute();
            isPositionFree(newCoordinate))
        {
            handleBufferMove(newCoordinate, *hero);
            hero->setLocation(newCoordinate);
        }
    }

    if (action == ACTION_TYPE::SHOOT) {
        if (const Coordinate newCoordinate = hero->getLocation() + hero->getRoute();
            isPositionFree(newCoordinate))
        {
            voltages.emplace_back(newCoordinate, hero->getRoute());
            buffer->setObject(newCoordinate, VOLT);
        }
    }
}

void Board::updateEnemy() {
    if (!hero || !enemy) {
        return;
    }

    enemyMoveTimer--;
    if (enemyMoveTimer > 0) {
        return;
    }
    enemyMoveTimer = enemyMoveDelay;

    const auto validMoves = getValidMoves(enemy->getLocation());

    if (validMoves.empty()) {
        return;
    }

    const Coordinate heroLocation = hero->getLocation();
    const auto bestMove = std::min_element(validMoves.begin(), validMoves.end(),
        [&](const Coordinate& a, const Coordinate& b) {
            return a.distance(heroLocation) < b.distance(heroLocation);
        });

    if (*bestMove == heroLocation) {
        hero->eraseLives(1);
    } else if (buffer->get(*bestMove) == BOX) {
        breakObject(*bestMove);
    } else {
        handleBufferMove(*bestMove, *enemy);
        enemy->setLocation(*bestMove);
    }
}

void Board::updateVoltages() {

    auto it = voltages.begin();

    while (it != voltages.end()) {
        Voltage& voltage = *it;

        const Coordinate currentLocation = voltage.getLocation();

        if (const Coordinate newCoordinate = currentLocation + voltage.getRoute();
            isPositionFree(newCoordinate))
        {
            handleBufferMove(newCoordinate, voltage);
            voltage.setLocation(newCoordinate);
            ++it;
        } else {
            handleBufferCollision(newCoordinate, voltage);
            it = voltages.erase(it);
        }
    }
}

std::vector<Coordinate> Board::getValidMoves(const Coordinate& location) const {
    std::vector<Coordinate> validMoves;
    const Coordinate deltas[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    for (const auto& delta : deltas) {
        const Coordinate newLocation = location + delta;
        if (newLocation.x >= 0 && newLocation.x < width && newLocation.y >= 0 && newLocation.y < height) {
            if (isPositionFree(newLocation) || (hero && newLocation == hero->getLocation()) || buffer->get(newLocation) == BOX) {
                validMoves.push_back(newLocation);
            }
        }
    }

    return validMoves;
}









