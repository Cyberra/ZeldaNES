#pragma once
#include "Level.h"
class RoomBoss :
	public Level
{
public:
	RoomBoss();
	~RoomBoss();

	point<int> const  GetRoomOffset(){ return OFFSET_ROOM_BOSS; }
};

