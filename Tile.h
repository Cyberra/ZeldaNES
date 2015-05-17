#pragma once

#include "Libraries.h"

////////////////////////////////////////////////////////////////////////////
//Tiles are used across the game to represent all the non-actor level assets.
////////////////////////////////////////////////////////////////////////////

// All the available tile types
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

	void Draw()	 { Sprite::Draw(); }

	// Getters & Setters
	int GetType() { return type; }
	SDL_Rect GetBox() { return box; }
	void SetBox(int x, int y) { box.x = x, box.y = y; }

	// Tile size
	static const int TILE_WIDTH = 16;
	static const int TILE_HEIGHT = 16;

private:
	// Collider
	SDL_Rect box;

	// Tile type
	int type;
};

