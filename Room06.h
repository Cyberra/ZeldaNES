#pragma once
#include "Level.h"
class Room06 :
	public Level
{
public:
	Room06();
	~Room06();

	point<int> const  GetRoomOffset(){ return OFFSET_ROOM_6; }
};

