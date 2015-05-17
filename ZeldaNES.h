#pragma once

////////////////////////////////////////////////////
//ZeldaNES
//This is our game instance. 
//Pretty much all the meta logic is located over here.
////////////////////////////////////////////////////

#include "Skeleton.h"
#include "Bomb.h"
#include "Slime.h"
#include "MoblinRed.h"
#include "MoblinBlue.h"
#include "Bats.h"
#include "Link.h"
#include "TitleScreen.h"
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

enum GameStates
{
	None,
	Title,
	Dungeon
};

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

	// Virtuals Unused
	void Draw() {}

	void TravelTo(Level* nextRoom, const int direction);
	void UpdateCamera();
	void HandleInputs();
	void SwitchState(GameStates state);

	static Camera* camera;
	static Camera* GetCamera() { return camera; }


private:
	Level		*currentRoom;
	Level		*rooms[18];
	Hud			*hud;
	Link		*link;
	Skeleton	*skelly;
	Slime		*slimey;
	MoblinRed   *mobRed;
	MoblinBlue  *mobBlue;
	Bats		*bats;
	Bomb		*bomb;
	Bomb		*smog;
	Object		*object;
	TitleScreen *titleScreen;
	GameStates	currentState;
	
};