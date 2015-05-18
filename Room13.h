#pragma once
#include "Level.h"
class Room13 :
	public Level
{
public:
	Room13();
	~Room13();

	point<int> const  GetRoomOffset(){ return OFFSET_ROOM_13; }
};

