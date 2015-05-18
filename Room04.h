#pragma once
#include "Level.h"
class Room04 :
	public Level
{
public:
	Room04();
	~Room04();

	point<int> const  GetRoomOffset(){ return OFFSET_ROOM_4; }
};

