#pragma once
#include "Level.h"
class RoomUnderground :
	public Level
{
public:
	RoomUnderground();
	~RoomUnderground();

	point<int> const  GetRoomOffset(){ return OFFSET_ROOM_UNDERGROUND; }
};

