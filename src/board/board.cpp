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
                default:
                    index = CARPET;
                break;
            }

            buffer->setObject({X, Y}, static_cast<GAME_OBJECTS>(index));
        }

        std::cout << std::endl;
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


bool Board::isPositionFree(const Coordinate& point) const {
    return buffer->get(point) == CARPET;
}

void Board::handleMove(const Coordinate &newCoordinate, const Object &object) const {
    buffer->eraseObject(object.getLocation());
    buffer->setObject(newCoordinate, object.getObjectType());
}

void Board::handleCollision(const Coordinate &coordinate, const Object &object) const {
    if (object.getObjectType() != VOLT) {
        return;
    }

    if (const GAME_OBJECTS collisionObject = buffer->get(coordinate); collisionObject == CARPET || collisionObject == BOX) {
       return;
    }

    if (hero->getLocation() == coordinate) {
        hero->eraseLives(-1);
    }

    if (enemy->getLocation() == coordinate) {
        enemy->eraseLives(-1);
    }

    buffer->eraseObject(coordinate);
}


void Board::updateHero(const char &key) const {

    const ACTION_TYPE action = hero->getAction(key);

    if (action == ACTION_TYPE::MOVE) {
        if (const Coordinate newCoordinate = hero->getLocation() + hero->getRoute();
            isPositionFree(newCoordinate))
        {
            handleMove(newCoordinate, *hero);

        }
    }

    if (action == ACTION_TYPE::SHOOT) {
        if (const Coordinate newCoordinate = hero->getLocation() + hero->getRoute();
            isPositionFree(newCoordinate))
        {
            voltages->emplace_back(newCoordinate, hero->getRoute());
            buffer->setObject(newCoordinate, VOLT);
        }
    }
}

void Board::updateEnemy() const {
}

void Board::updateVoltages() const {

    auto it = voltages->begin();

    while (it != voltages->end()) {
        Voltage& voltage = *it;

        if (const Coordinate newCoordinate = voltage.getLocation() + voltage.getRoute();
            isPositionFree(newCoordinate))
        {
            handleMove(newCoordinate, voltage);
            voltage.setLocation(newCoordinate);
            ++it;
        } else {
            buffer->eraseObject(voltage.getLocation());
            it = voltages->erase(it);
        }
    }
}






