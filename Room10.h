#pragma once
#include "Level.h"
class Room10 :
	public Level
{
public:
	Room10();
	~Room10();

	point<int> const  GetRoomOffset(){ return OFFSET_ROOM_10; }
};

