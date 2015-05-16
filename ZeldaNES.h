#pragma once

#include "Skeleton.h"
#include "Bomb.h"
#include "Slime.h"
#include "MoblinRed.h"
#include "MoblinBlue.h"
#include "Link.h"
#include "Room01.h"
#include "Room02.h"
#include "Room03.h"
#include "Room04.h"
#include "Room05.h"
#include "Room06.h"
#include "Room07.h"
#include "Room08.h"
#include "Room09.h"
#include "Room10.h"
#include "Room11.h"
#include "Room12.h"
#include "Room13.h"
#include "Room14.h"
#include "RoomBoss.h"
#include "RoomShop.h"
#include "RoomTriforce.h"
#include "RoomUnderground.h"
#include "Camera.h"
#include "Hud.h"

class ZeldaNES :
	public Component
{
public:
	ZeldaNES();
	~ZeldaNES();

	// Virtuals used
	void Start();
	void Update();
	void Stop();
	void Kill() { delete this; }
	void UpdateCamera();

	static Camera* camera;

	// Virtuals Unused
	void Draw() {}

	void TravelTo(Level* prevRoom, Level* nextRoom, const int direction);
private:

	

	Level *actualRoom;
	Level *rooms[18];
	Hud *hud;
	Link *link;
	Skeleton *skelly;
	Slime *slimey;
	MoblinRed *mobRed;
	MoblinBlue *mobBlue;
	Bomb* Bombe;
	Bomb* Smog;
	Objects* objects;
	
	
};

