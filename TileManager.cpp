#include "TileManager.h"

TileManager::TileManager()
{

}

point<int> TileManager::GetOffSet(const std::string map)
{
	point<int> offSet;
	
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
{
	//Success flag
	bool tilesLoaded = true;

	//The tile offsets
	point<int> offSet = GetOffSet(mapPath);
	int x = offSet.x, y = offSet.y;
	
	if (mapPath != "RoomUnderground.map")
	{
		Sprite *wall = new Sprite(Texture::ID::Walls);
		wall->SetPosition(x - 24, y - 24);
	}

	//Open the map
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
			//Determines what kind of tile will be made
			int tileType = -1;

			//Read tile from map file
			map >> tileType;

			//If the was a problem in reading the map
			if (map.fail())
			{
				//Stop loading map
				printf("Error loading map: Unexpected end of file!\n");
				tilesLoaded = false;
				break;
			}

			//If the number is a valid tile number
			if ((tileType >= 0) && (tileType < TOTAL_TILE_SPRITES))
			{
				//std::cout << i << ": " << tileType << std::endl;
				tiles[i] = new Tile(tileType);
				tiles[i]->SetPosition(x, y);
				tiles[i]->SetBox(x, y);
				std::cout << tiles[i]->GetBox().x << ", " << tiles[i]->GetBox().y << std::endl;
			}
			//If we don't recognize the tile type
			else
			{
				//Stop loading map
				printf("Error loading map: Invalid tile type at %d!\n", i);
				tilesLoaded = false;
				break;
			}
			//Move to next tile spot
			x += Tile::TILE_WIDTH;

			//If we've gone too far
			if (x >= LEVEL_WIDTH + offSet.x)
			{
				//Move back
				x = offSet.x;

				//Move to the next row
				y += Tile::TILE_HEIGHT ;
			}
		}
	}
	//Close the file
	map.close();

	//If the map was loaded fine
	isInitialized = tilesLoaded;
}

TileManager::~TileManager()
{

}

// Check for collision
bool TileManager::TouchesWall(SDL_Rect box)
{
	//Go through the tiles
	for (int i = 0; i < TOTAL_TILES; ++i)
	{
		//If the tile is a wall type tile
		if (((tiles[i]->GetType() >= GREEN_BLOCK) && (tiles[i]->GetType() <= GREY_RIGHT_STATUE)) || (tiles[i]->GetType() == WATER))
		{
			//std::cout << "Hello wall" << std::endl;
			//If the collision box touches the wall tile
			Rectangle *r1 = new Rectangle(box.x, box.y, box.w, box.h);
			Rectangle *r2 = new Rectangle(tiles[i]->GetBox().x, tiles[i]->GetBox().y, tiles[i]->GetBox().w, tiles[i]->GetBox().h);

 			if (r1->CollidesWith(r2))		
			{
				//std::cout << "Hello wall" << std::endl;
				return true;
			}
		}
	}

	//If no wall tiles were touched
	return false;
}