#pragma once
#include "Level.h"
class Room02 :
	public Level
{
public:
	Room02();
	~Room02();
	// I know this is probably wrong, but with the amount of time left to accomplish this, 
	// Ain't nobody got time for cleanliness.
	point<int> const GetRoomOffset(){ return OFFSET_ROOM_2; }
};