#pragma once

#include "Libraries.h"

/*
	This is the class for a single tile
*/

// All the tile types, will change in the real game
enum tileTypes{
	TILE_RED = 0,
	TILE_GREEN,
	TILE_BLUE,
	TILE_CENTER,
	TILE_TOP,
	TILE_TOPRIGHT,
	TILE_RIGHT,
	TILE_BOTTOMRIGHT,
	TILE_BOTTOM,
	TILE_BOTTOMLEFT,
	TILE_LEFT,
	TILE_TOPLEFT
};

class Tile:
	public Sprite
{
public:
	Tile();
	Tile(int tileType);
	~Tile();

	//Functions needed for the abstract class component (when it will be...)
	void Start() {}
	void Stop()	 {}
	void Draw()	 { Sprite::Draw(); }
	void Update() {}

	// Getters n Setters
	int GetType() { return type; }
	SDL_Rect GetBox() { return box; }
	void SetBox(int x, int y) { box.x = x, box.y = y; }

	// Size of tile
	static const int TILE_WIDTH = 80;
	static const int TILE_HEIGHT = 80;

private:
	// Collider
	SDL_Rect box;

	// position Stuff
	int currentX;
	int currentY;

	// What is that tile 
	int type;
};

