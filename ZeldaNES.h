#pragma once

#include "Link.h"
#include "Room01.h"
#include "Room02.h"

class ZeldaNES :
	public Component
{
public:
	ZeldaNES();
	~ZeldaNES();

	void Start();
	void Update();
	void Stop();

	void TravelTo(Level* prevRoom, Level* nextRoom);
private:

	Level* rooms[18];
	Link *link;
};

