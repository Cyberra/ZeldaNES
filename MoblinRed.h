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
	// Update-like method that takes care of movement
	void Move(TileManager* tm);

	// Animation related stuff ---- TO DO
	const int NUM_OF_FRAMES()					{ return 2; }
	const point<int> FRAME_SIZE()				{ return{ 16, 16 }; };
	const point<int> MOB_RED_ANIM_SRC()			{ return{ 64, 64 }; };
};

