#pragma once
#include "Level.h"
class Room03 :
	public Level
{
public:
	Room03();
	~Room03();

	point<int> const GetRoomOffset(){ return OFFSET_ROOM_3; }
};

