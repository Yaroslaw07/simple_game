#include "board.h"

#include <algorithm>
#include <fstream>

#include <iostream>

void Board::loadLevel(const std::string& path)
{
    std::ifstream in(path);

    if (!in.is_open()) {
        printw("Error: Unable to open level file.");
        getch();
        endwin();
        exit(EXIT_FAILURE);
    }

    int index;
    in >> width >> height;

    buffer = new StateBuffer(width, height);

    for (int Y = 0; Y < height; Y++) {
        for (int X = 0; X < width; X++) {
            in >> index;


            const Coordinate coordinate(X, Y);

            switch(index) {
                case HERO:
                    if (hero != nullptr) {
                        index = CARPET;
                    } else {
                        hero = new Hero(coordinate, 3, 'w', 's', 'a', 'd', ' ');
                    }
                break;
                case ENEMY:
                    enemy = new Enemy(coordinate, 3);
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

void Board::handleBufferCollision(const Coordinate &toCollisionCoordinate,const Object &object) const {
    if (object.getObjectType() != VOLT) {
        return;
    }

    const GAME_OBJECTS collisionObject = buffer->get(toCollisionCoordinate);

    if (collisionObject == CARPET) {
        return;
    }

    if (hero->getLocation() == toCollisionCoordinate) {
        hero->eraseLives(1);
    }

    if (enemy->getLocation() == toCollisionCoordinate) {
        enemy->eraseLives(1);
    }

    buffer->eraseObject(object.getLocation());
}


void Board::updateHero(const char &key) {

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






