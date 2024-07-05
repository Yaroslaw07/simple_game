#pragma once

#include "vector"

#include "../voltage/Voltage.h"
#include "../object.h"

#include "../../board/route_coordinate.h"
#include "../../board/storage.h"


class Heroe : public Object
{	
private:
	char Up_Key, Down_Key, Left_Key, Right_Key, Shoot_Key;
public:
	Heroe(Coordinate location, int lives,char Up_Key,char Down_Key ,char Left_Key ,char Right_Key ,char Shoot_Key);

	void keyPress(char c,Storage& NewDraw,std::vector<Voltage>& Voltages);
};
