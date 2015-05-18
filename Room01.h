#pragma once

#include "Level.h"

class Room01 :
	public Level
{
public:
	Room01();
	~Room01();

	point<int> const GetRoomOffset(){ return OFFSET_ROOM_1; }
	
};

