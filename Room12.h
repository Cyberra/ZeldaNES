#pragma once
#include "Level.h"
class Room12 :
	public Level
{
public:
	Room12();
	~Room12();

	point<int> const  GetRoomOffset(){ return OFFSET_ROOM_12; }
};

