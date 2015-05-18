#pragma once
#include "Level.h"
class Room10 :
	public Level
{
public:
	Room10();
	~Room10();
	// I know this is probably wrong, but with the amount of time left to accomplish this, 
	// Ain't nobody got time for cleanliness.
	point<int> const  GetRoomOffset(){ return OFFSET_ROOM_10; }
};

