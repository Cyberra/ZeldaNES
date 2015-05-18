#pragma once
#include "Level.h"
class Room12 :
	public Level
{
public:
	Room12();
	~Room12();
	// I know this is probably wrong, but with the amount of time left to accomplish this, 
	// Ain't nobody got time for cleanliness.
	point<int> const  GetRoomOffset(){ return OFFSET_ROOM_12; }
};

