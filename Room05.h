#pragma once
#include "Level.h"
class Room05 :
	public Level
{
public:
	Room05();
	~Room05();

	point<int> const  GetRoomOffset(){ return OFFSET_ROOM_5; }
};

