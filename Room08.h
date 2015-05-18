#pragma once
#include "Level.h"
class Room08 :
	public Level
{
public:
	Room08();
	~Room08();

	point<int> const  GetRoomOffset(){ return OFFSET_ROOM_8; }
};

