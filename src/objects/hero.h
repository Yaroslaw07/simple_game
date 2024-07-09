#pragma once

#include "action.h"
#include "objects/object.h"

#include "route_coordinate/route_coordinate.h"

class Hero : public Object
{	
private:
	char upKey, downKey, leftKey, rightKey, shootKey;
public:
	Hero(Coordinate location, int lives,char upKey,char downKey ,char leftKey ,char rightKey ,char shootKey):
		Object(GAME_OBJECTS::HERO, location, lives)
	{
		this->upKey = upKey;
		this->downKey = downKey;
		this->leftKey = leftKey;
		this->rightKey = rightKey;
		this->shootKey = shootKey;
	};

	ACTION_TYPE getAction(const char &key) {

		if (key == upKey) {
			route = Route::UP;
			return ACTION_TYPE::MOVE;
		}

		if (key == downKey) {
			route = Route::DOWN;
			return ACTION_TYPE::MOVE;
		}

		if (key == leftKey) {
			route = Route::LEFT;
			return ACTION_TYPE::MOVE;
		}

		if (key == rightKey) {
			route = Route::RIGHT;
			return ACTION_TYPE::MOVE;
		}

		if (key == shootKey) {
			return ACTION_TYPE::SHOOT;
		}

		return ACTION_TYPE::NONE;
	}

};

