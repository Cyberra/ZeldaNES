#pragma once

#include "Libraries.h"



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

	int GetType() { return type; }

	SDL_Rect GetBox() { return box; }

	void SetBox(int x, int y) { box.x = x, box.y = y; }

	static const int TILE_WIDTH = 80;
	static const int TILE_HEIGHT = 80;

private:
	SDL_Rect box;

	int currentX;
	int currentY;

	int type;
};

