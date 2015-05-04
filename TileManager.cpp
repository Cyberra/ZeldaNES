#include "TileManager.h"

const int TileManager::TOTAL_TILES;
const int TileManager::TOTAL_TILE_SPRITES;
Tile *TileManager::tiles[TileManager::TOTAL_TILES] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 
													   nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 
													   nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
													   nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  
													   nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
													   nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
													   nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
TileManager::TileManager()
{

}

TileManager::~TileManager()
{

}

// Check for collision
bool TileManager::TouchesWall(SDL_Rect box, Tile *tiles[TOTAL_TILES])
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

// setup the map
bool TileManager::SetTiles(Tile* tiles[TOTAL_TILES])
{
	//Success flag
	bool tilesLoaded = true;

	//The tile offsets
	int x = 0, y = 0;

	//Open the map
	std::ifstream map("Room1.map");

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
			if (x >= LEVEL_WIDTH)
			{
				//Move back
				x = 0;

				//Move to the next row
				y += Tile::TILE_HEIGHT;
			}
		}
	}
	//Close the file
	map.close();

	//If the map was loaded fine
	return tilesLoaded;
}