#include "Level.h"

Level::Level()
{
}

Level::Level(std::string mapPath)
	: TileManager(mapPath)
	, player(nullptr)
{

}

Level::~Level()
{

}

void Level::Update()
{
	if (player != nullptr)
	{
		player->Move(this);
	}
}
