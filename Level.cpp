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
	auto it = enemy.begin();
	while (it != enemy.end())
	{
		it = enemy.erase(it);
	}
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
