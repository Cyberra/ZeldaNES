#pragma once
#include "Level.h"
class Room07 :
	public Level
{
public:
	Room07();
	~Room07();

	point<int> const  GetRoomOffset(){ return OFFSET_ROOM_7; }
};

