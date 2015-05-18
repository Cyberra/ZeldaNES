#pragma once
#include "Level.h"
class Room11 :
	public Level
{
public:
	Room11();
	~Room11();

	point<int> const  GetRoomOffset(){ return OFFSET_ROOM_11; }
};

