#pragma once

#include "Enemy.h"
#include "Level.h"


//////////////////////////////////////////////////
//Enemy: Bat
//This airborne enemy should fly around the room.
//Sadly, it does not.
//////////////////////////////////////////////////

class Bats :
	public Enemy
{
public:
	Bats();
	~Bats();

	void Update();

	//Changes the enemy's currentRoom
	void Enter(Level* room);


private:
	// Update-like method that takes care of movement
	void Move(TileManager* tm);

	// Animation related stuff
	const int NUM_OF_FRAMES()					{ return 2; }
	const point<int> FRAME_SIZE()				{ return{ 16, 16 }; };
	const point<int> BATS_ANIM_SRC()			{ return{ 0, 112 }; };
};

