#pragma once

#include "Enemy.h"
#include "Level.h"

//////////////////////////////////////////////////
//Enemy: Skeleton
//This is the skeleton enemy. Very descriptive.
//////////////////////////////////////////////////

class Skeleton :
	public Enemy
{
public:
	Skeleton();
	~Skeleton();

	void Update();

	//Changes the enemy's currentRoom
	void Enter(Level* room);


private:
	// Update-like method that takes care of movement
	void Move(TileManager* tm);

	// Animation related stuff
	const int NUM_OF_FRAMES()					{ return 2; }
	const point<int> FRAME_SIZE()				{ return{ 16, 16 }; };
	const point<int> SKELLY_ANIM_SRC()			{ return{ 0, 96 }; };

};

