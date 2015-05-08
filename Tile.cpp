#include "Tile.h"

Tile::Tile()
	: type(0)
{

}

Tile::Tile(int tileType)
	: Sprite(Texture::ID::DungeonRoom, { tileType * TILE_WIDTH, 0 }, { TILE_WIDTH, TILE_HEIGHT })
	, type(tileType)
{
	box.w = TILE_WIDTH;
	box.h = TILE_HEIGHT;
}

Tile::~Tile()
{

}


