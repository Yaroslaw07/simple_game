#include "board.h"

#include <fstream>

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

void Board::handleCollision(const Coordinate &coordinate, const Object &object) {
    switch (object.getObjectType()) {
        case HERO:
            if (enemy->getLocation() == coordinate) {
                hero->eraseLives();
            }
        break;
        case ENEMY:
            if (hero->getLocation() == coordinate) {
                enemy->eraseLives();
            }
        break;
        case VOLT:
            if (hero->getLocation() == coordinate) {
                hero->eraseLives();
            }
        break;
        default:
        break;
    }
}


void Board::updateHero(const char &key) {

}




