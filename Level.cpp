#include "Level.h"

Level::Level()
: player(nullptr)
{
}

Level::Level(const std::string mapPath)
	: TileManager(mapPath)
	, player(nullptr)
{

}

Level::~Level()
{
	enemy.clear();
	//for (int i = 0; i < TOTAL_TILES; i++)
	//{
	//	delete tiles[i];
	//	tiles[i] = nullptr;
	//}
}

void Level::Update()
{
	if (player != nullptr)
	{
		player->Move(this);
	}
	
	for (iter = enemy.begin(); iter != enemy.end(); ++iter)
	{
		if ((*iter) != nullptr)
		{
			(*iter)->Move(this);
		}
	}
	
}