#pragma once
#include "Level.h"
class Room14 :
	public Level
{
public:
	Room14();
	~Room14();

	point<int> const  GetRoomOffset(){ return OFFSET_ROOM_14; }
};

