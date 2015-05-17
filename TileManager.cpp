#include "TileManager.h"
#include "ZeldaNES.h"

TileManager::TileManager()
{

}

point<int> TileManager::GetOffSet(const std::string map)
{
	if (map == "Room01.map")
	{
		offSet.x = 732; 
		offSet.y = 864;
	}
	else if (map == "Room02.map")
	{
		offSet.x = 492;
		offSet.y = 864;
	}
	else if (map == "Room03.map")
	{
		offSet.x = 972;
		offSet.y = 864;
	}
	else if (map == "Room04.map")
	{
		offSet.x = 732;
		offSet.y = 704;
	}
	else if (map == "Room05.map")
	{
		offSet.x = 492;
		offSet.y = 544;
	}
	else if (map == "Room06.map")
	{
		offSet.x = 732;
		offSet.y = 544;
	}
	else if (map == "Room07.map")
	{
		offSet.x = 972;
		offSet.y = 544;
	}
	else if (map == "Room08.map")
	{
		offSet.x = 492;
		offSet.y = 384;
	}
	else if (map == "Room09.map")
	{
		offSet.x = 732;
		offSet.y = 384;
	}
	else if (map == "Room10.map")
	{
		offSet.x = 972;
		offSet.y = 384;
	}
	else if (map == "Room11.map")
	{
		offSet.x = 1212;
		offSet.y = 384;
	}
	else if (map == "Room12.map")
	{
		offSet.x = 732;
		offSet.y = 224;
	}
	else if (map == "Room13.map")
	{
		offSet.x = 732;
		offSet.y = 64;
	}
	else if (map == "Room14.map")
	{
		offSet.x = 492;
		offSet.y = 64;
	}
	else if (map == "RoomBoss.map")
	{
		offSet.x = 1212;
		offSet.y = 224;
	}
	else if (map == "RoomShop.map")
	{
		offSet.x = 252;
		offSet.y = 384;
	}
	else if (map == "RoomTriforce.map")
	{
		offSet.x = 1452;
		offSet.y = 224;
	}
	else if (map == "RoomUnderground.map")
	{
		offSet.x = 252;
		offSet.y = 64;
	}

	return offSet;
}

TileManager::TileManager(std::string mapPath)
	:isInitialized(false)
	, offSet(0, 0)
{
	//Success flag
	bool tilesLoaded = true;

	//The tile offsets
	point<int> offSet = GetOffSet(mapPath);
	int x = offSet.x, y = offSet.y;
	
	//If the current room isn't underground, we place the dungeon walls around it.
	if (mapPath != "RoomUnderground.map")
	{
		Sprite *wall = new Sprite(Texture::ID::Walls);
		wall->SetPosition(x - 24, y - 24);
		walls.push_back(wall);
	}

	//Tries to open the map file
	std::ifstream map(mapPath);

	//If the map couldn't be loaded
	if (map.fail())
	{
		printf("Unable to load map file!\n");
		tilesLoaded = false;
	}
	else
	{
		//Initialize the tiles
		for (int i = 0; i < TOTAL_TILES; ++i)
		{
			//Represents the current tile type we're dealing with.
			int tileType = -1;

			//Read tiles types from map file
			map >> tileType;

			//If there was a problem reading from the map or if the specifiedType was invalid.
			if (map.fail() || !(tileType >= 0) && (tileType < TOTAL_TILE_SPRITES))
			{
				//Stops loading map
				printf("Error loading map: Unexpected end of file!\n");
				tilesLoaded = false;
				break;
			}
			//Otherwise, spawn the tile and set its corresponding position/collision box.
			else
			{
				//std::cout << i << ": " << tileType << std::endl;
				tiles[i] = new Tile(tileType);
				tiles[i]->SetPosition((int)x - ZeldaNES::GetCamera()->GetView()->x, (int)y - ZeldaNES::GetCamera()->GetView()->y);;
				tiles[i]->SetBox(x, y);
				//std::cout << tiles[i]->GetBox().x << ", " << tiles[i]->GetBox().y << std::endl;
			}

			//Move over to the next tile
			x += Tile::TILE_WIDTH;

			//If we're done with the current row
			if (x >= LEVEL_WIDTH + offSet.x)
			{
				//Go back to the leftmost tile
				x = offSet.x;

				//And skip to the next row
				y += Tile::TILE_HEIGHT ;
			}
		}
	}
	//Close the file
	map.close();

	//Stores whether we managed to initialize the tiles correctly.
	isInitialized = tilesLoaded;
}

TileManager::~TileManager()
{
	//delete tiles[TileManager::TOTAL_TILES];
	//tiles[TileManager::TOTAL_TILES] = nullptr;
}

//Checks for collision
bool TileManager::TouchesWall(SDL_Rect box)
{
	bool collision = false;
	//Go through all tiles
	for (int i = 0; i < TOTAL_TILES; ++i)
	{
		//If the tile can be collided with
		if (((tiles[i]->GetType() >= GREEN_BLOCK) && (tiles[i]->GetType() <= GREY_RIGHT_STATUE)) || (tiles[i]->GetType() == WATER))
		{
			//Check if there is collision between the tile's bounding box and the collider.
			Rectangle *r1 = new Rectangle((float)box.x, (float)box.y, (float)box.w, (float)box.h);
			Rectangle *r2 = new Rectangle((float)tiles[i]->GetBox().x, (float)tiles[i]->GetBox().y, (float)tiles[i]->GetBox().w, (float)tiles[i]->GetBox().h);

 			if (r1->CollidesWith(r2))		
			{
				collision = true;
			}
			delete r1;
			delete r2;
			r1 = nullptr;
			r2 = nullptr;
		}
	}
	//Returns whether or not there was collision.
	return collision;
}

//Sets all the room's tiles and the surrounding walls active
void TileManager::SetActive(bool toggle)
{
	for (iterWalls = walls.begin(); iterWalls != walls.end(); iterWalls++)
	{
		(*iterWalls)->SetActive(toggle);
	}
	for (int i = 0; i < TOTAL_TILES; i++)
	{
		tiles[i]->SetVisible(toggle);
	}
}