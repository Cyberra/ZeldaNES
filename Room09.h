#pragma once
#include "Level.h"
class Room09 :
	public Level
{
public:
	Room09();
	~Room09();

	point<int> const  GetRoomOffset(){ return OFFSET_ROOM_9; }
};

