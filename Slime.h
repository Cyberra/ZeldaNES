#pragma once

#include "Enemy.h"
#include "Level.h"

//////////////////////////////////////////////////
//Enemy: Slime
//Bloop bleep bloop.
//////////////////////////////////////////////////

class Slime :
	public Enemy
{
public:
	Slime();
	~Slime();

	void Update();

	//Changes the enemy's currentRoom
	void Enter(Level* room);


private:
	// Update-like method that takes care of movement
	void Move(TileManager* tm);

	SDL_Rect moverBox;

	// Animation related stuff
	const int NUM_OF_FRAMES()					{ return 2; }
	const point<int> FRAME_SIZE()				{ return{ 16, 16 }; };
	const point<int> SLIMEY_ANIM_SRC()			{ return{ 48, 96 }; };

};