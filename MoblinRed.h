#pragma once

#include "Enemy.h"
#include "Level.h"

////////////////////////////////////////////////////////
//Enemy: Red Moblin
//Also known as, the red version of the blue pig monster.
/////////////////////////////////////////////////////////

class MoblinRed :
	public Enemy
{
public:
	MoblinRed();
	~MoblinRed();

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
	const point<int> MOB_RED_DOWN_SRC()		{ return{ 128, 64 }; };
	const point<int> MOB_RED_LEFT_SRC()		{ return{ 96, 64 }; };
	const point<int> MOB_RED_UP_SRC()			{ return{ 64, 64 }; };
	const point<int> MOB_RED_RIGHT_SRC()		{ return{ 160, 64 }; };
};

