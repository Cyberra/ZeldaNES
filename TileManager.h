#pragma once

/*
	This is the class that contains all the tiles and check for collision of a given object !
*/

#include "Libraries.h"
#include "Tile.h"
#include "Rectangle.h"

#define LEVEL_WIDTH 192
#define LEVEL_HEIGHT 112

class TileManager
{
public:
	TileManager();
	~TileManager();

	// Tiles constants
	static const int TOTAL_TILES = 84;
	static const int TOTAL_TILE_SPRITES = 17;

	// CheckCollision
	static bool TouchesWall(SDL_Rect box, Tile* tiles[TOTAL_TILES]);

	// Set the map with a given .map text file NB:See example lazy.map in the folder
	bool SetTiles(Tile* tiles[TOTAL_TILES]);

	// The array of all the tiles 1D for simplicity purpose
	static Tile *tiles[TOTAL_TILES];

private:
	
	
};

