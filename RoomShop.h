#pragma once
#include "Level.h"
class RoomShop :
	public Level
{
public:
	RoomShop();
	~RoomShop();

	point<int> const  GetRoomOffset(){ return OFFSET_ROOM_SHOP; }
};

