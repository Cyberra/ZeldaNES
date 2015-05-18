#pragma once
#include "Level.h"
class RoomTriforce :
	public Level
{
public:
	RoomTriforce();
	~RoomTriforce();
	point<int> const  GetRoomOffset(){ return OFFSET_ROOM_TRIFORCE; }
};

