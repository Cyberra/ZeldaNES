#pragma once

#include "Libraries.h"

/*
	This is the class for a single tile
*/

// All the tile types, will change in the real game
enum tileTypes{
	NORMAL = 0,
	GREEN_BLOCK,
	ORANGE_BLOCK,
	BLUE_LEFT_STATUE,
	BLUE_RIGHT_STATUE,
	GREY_LEFT_STATUE,
	GREY_RIGHT_STATUE,
	STAIRS,
	WATER,
	BLACK,
	ORANGE,
	DIRT,
	BLUE_DIRT,
	LEFT_BOMB_HOLE,
	RIGHT_BOMB_HOLE,
	DOWN_BOMB_HOLE,
	TOP_BOMB_HOLE,
	STAIR_UNDERGROUND,
	WHITE_BRICK
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
	static const int TILE_WIDTH = 16;
	static const int TILE_HEIGHT = 16;

private:
	// Collider
	SDL_Rect box;

	// What is that tile 
	int type;
};

