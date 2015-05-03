#pragma once

/*
	This is the Test class for the players, its the moving Dot on the screen
	Warning !: All this will be put in Link class at some point
*/

#include "Libraries.h"
#include "TileManager.h"
class DotD:
	public Sprite
{
public:
	DotD();
	~DotD();

	//Functions needed for the abstract class component (when it will be...)
	void Start() {}
	void Stop()	 {}
	void Draw()	 { Sprite::Draw(); }
	void Update();

	// Size of the Dot collision box
	static const int DOT_WIDTH = 20;
	static const int DOT_HEIGHT = 20;


	// Moving Stuff
	void Move(Tile *tiles[TileManager::TOTAL_TILES]);
	void MoveBox();

private:	
	// Speed of the Dot
	const float SPEED;

	// Collider
	SDL_Rect box;

	// Position Shit
	float currentX, currentY;
};

