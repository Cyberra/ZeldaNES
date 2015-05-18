#pragma once
#include "Level.h"
class RoomShop :
	public Level
{
public:
	RoomShop();
	~RoomShop();
	// I know this is probably wrong, but with the amount of time left to accomplish this, 
	// Ain't nobody got time for cleanliness.
	point<int> const  GetRoomOffset(){ return OFFSET_ROOM_SHOP; }
};

