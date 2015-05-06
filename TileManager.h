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
	: public Component
{
public:
	// Tiles constants
	static const int TOTAL_TILES = 84;
	static const int TOTAL_TILE_SPRITES = 19;

	TileManager();
	TileManager(std::string mapPath);
	~TileManager();

	// Locals
	point<int> GetOffSet(const std::string map);

	// Getters
	Tile** GetTiles(){ return tiles; }

	// CheckCollision
	bool TouchesWall(SDL_Rect box);

protected:
	// The array of all the tiles 1D for simplicity purpose
	Tile *tiles[TOTAL_TILES];
	bool isInitialized;
};

