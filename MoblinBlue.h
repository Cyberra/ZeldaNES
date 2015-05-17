#pragma once

#include "Enemy.h"
#include "Level.h"

///////////////////////////////////////
//Enemy: Blue Moblin
//Also known as, the blue pig monster.
///////////////////////////////////////

class MoblinBlue :
	public Enemy
{
public:
	MoblinBlue();
	~MoblinBlue();

	void Update();

	//Changes the enemy's currentRoom
	void Enter(Level* room);


private:
	// Locally Reimpementing this to make it easier for a fool
	// to set the orientation animations.
	void ChangeDirection(int choice);

	// Update-like method that takes care of movement
	void Move(TileManager* tm);

	// Animation related stuff
	const int NUM_OF_FRAMES()					{ return 2; }
	const point<int> FRAME_SIZE()				{ return{ 16, 16 }; };
	const point<int> MOB_BLUE_DOWN_SRC()		{ return{ 128, 80 }; };
	const point<int> MOB_BLUE_LEFT_SRC()		{ return{ 96, 80 }; };
	const point<int> MOB_BLUE_UP_SRC()			{ return{ 64, 80 }; };
	const point<int> MOB_BLUE_RIGHT_SRC()		{ return{ 160, 80 }; };
};

