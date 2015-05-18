#pragma once

//////////////////////////////////////////////////////////////////////////////////////////
//This is the class that contains all the tiles and check for collision of a given object!
//////////////////////////////////////////////////////////////////////////////////////////

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

	virtual void SetActive(bool toggle);

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
	point<int> offSet;
	std::vector<Sprite*> walls;
	std::vector<Sprite*>::iterator iterWalls;
	Tile *tiles[TOTAL_TILES];
	bool isInitialized;

	// Consts for the rooms offset, Yeah! I know it's bad, but in this case I had to make it work fast
	// and without magic numbers so here's what I did !
	const point<int> OFFSET_ROOM_1 =			{732, 864};
	const point<int> OFFSET_ROOM_2 =			{492, 864};
	const point<int> OFFSET_ROOM_3 =			{972, 864};
	const point<int> OFFSET_ROOM_4 =			{732, 720};
	const point<int> OFFSET_ROOM_5 =			{492, 544};
	const point<int> OFFSET_ROOM_6 =			{732, 544};
	const point<int> OFFSET_ROOM_7 =			{972, 544};
	const point<int> OFFSET_ROOM_8 =			{492, 384};
	const point<int> OFFSET_ROOM_9 =			{732, 384};
	const point<int> OFFSET_ROOM_10 =			{972, 384};
	const point<int> OFFSET_ROOM_11 =			{1212, 384};
	const point<int> OFFSET_ROOM_12 =			{732, 224};
	const point<int> OFFSET_ROOM_13 =			{732, 64};
	const point<int> OFFSET_ROOM_14 =			{492, 64};
	const point<int> OFFSET_ROOM_BOSS =			{1212, 224};
	const point<int> OFFSET_ROOM_SHOP =			{252, 384};
	const point<int> OFFSET_ROOM_TRIFORCE =		{1452, 224};
	const point<int> OFFSET_ROOM_UNDERGROUND =	{252, 64};
};

