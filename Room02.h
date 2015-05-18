#pragma once
#include "Level.h"
class Room02 :
	public Level
{
public:
	Room02();
	~Room02();

	point<int> const GetRoomOffset(){ return OFFSET_ROOM_2; }
};