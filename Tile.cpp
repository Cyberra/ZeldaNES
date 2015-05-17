#include "Tile.h"

Tile::Tile()
	: type(0)
{

}

Tile::Tile(int tileType)
	: Sprite(Texture::ID::DungeonRoom, { tileType * TILE_WIDTH, 0 }, { TILE_WIDTH, TILE_HEIGHT })
	, type(tileType)
{
	//Sets up the tile's colliding box to the tile's width & height.
	box.w = TILE_WIDTH;
	box.h = TILE_HEIGHT;
}

Tile::~Tile()
{

}


