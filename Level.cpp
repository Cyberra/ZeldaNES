#include "Level.h"

Level::Level()
{
}

Level::Level(const std::string mapPath)
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