#pragma once

#include "Libraries.h"
#include "Tile.h"
#include "Rectangle.h"

#define LEVEL_WIDTH 1280
#define LEVEL_HEIGHT 960

class TileManager
{
public:
	TileManager();
	~TileManager();

	static const int TOTAL_TILES = 192;
	static const int TOTAL_TILE_SPRITES = 12;

	static bool TouchesWall(SDL_Rect box, Tile* tiles[TOTAL_TILES]);
	bool SetTiles(Tile* tiles[TOTAL_TILES]);

	static Tile *tiles[TOTAL_TILES];

private:
	
	
};

