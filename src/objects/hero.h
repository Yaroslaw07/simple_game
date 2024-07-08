#pragma once

#include "action.h"
#include "objects/object.h"

#include "route_coordinate/route_coordinate.h"

class Hero : public Object
{	
private:
	char Up_Key, Down_Key, Left_Key, Right_Key, Shoot_Key;
public:
	Hero(Coordinate location, int lives,char Up_Key,char Down_Key ,char Left_Key ,char Right_Key ,char Shoot_Key): Object(GAME_OBJECTS::HERO, location, lives)
	{
		this->Up_Key = Up_Key;
		this->Down_Key = Down_Key;
		this->Left_Key = Left_Key;
		this->Right_Key = Right_Key;
		this->Shoot_Key = Shoot_Key;
	};

	ACTION_TYPE getAction(const char& key);
};

inline ACTION_TYPE Hero::getAction(const char &key) {
	switch(key) {
		case Up_Key:
			route = Route::UP;
			return ACTION_TYPE::MOVE;
		case Down_Key:
			route = Route::DOWN;
			return ACTION_TYPE::MOVE;
		case Left_Key:
			route = Route::LEFT;
			return ACTION_TYPE::MOVE;
		case Right_Key:
			route = Route::RIGHT;
			return ACTION_TYPE::MOVE;
		case Shoot_Key:
			return ACTION_TYPE::SHOOT;
		default:
			return ACTION_TYPE::NONE;
	}
}
