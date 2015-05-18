#pragma once
#include "Level.h"
class Room04 :
	public Level
{
public:
	Room04();
	~Room04();
	// I know this is probably wrong, but with the amount of time left to accomplish this, 
	// Ain't nobody got time for cleanliness.
	point<int> const  GetRoomOffset(){ return OFFSET_ROOM_4; }
};

