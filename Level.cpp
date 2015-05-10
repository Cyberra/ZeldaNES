#include "Level.h"

Level::Level()
{
}

Level::Level(const std::string mapPath)
	: TileManager(mapPath)
	, player(nullptr)
	, enemy(nullptr)

{

}

Level::~Level()
{
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
	if (enemy != nullptr)
	{
		enemy->Move(this);
	}
}

void Level::Hide()
{
	for (int i = 0; i < TOTAL_TILES; i++)
	{
		tiles[i]->SetVisible(false);
	}
}

void Level::Show()
{
	for (int i = 0; i < TOTAL_TILES; i++)
	{
		tiles[i]->SetVisible(true);
	}
}