#pragma once
#include "Level.h"
class Room13 :
	public Level
{
public:
	Room13();
	~Room13();
	// I know this is probably wrong, but with the amount of time left to accomplish this, 
	// Ain't nobody got time for cleanliness.
	point<int> const  GetRoomOffset(){ return OFFSET_ROOM_13; }
};

