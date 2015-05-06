#pragma once
#include "Enemies.h"
#include "Level.h"

class Skeleton :
	public Enemies
{
public:
	Skeleton();
	~Skeleton();

	// Getter for the room in which the Skeleton spawns
	Level const *GetRoom() { return currentRoom; }
	
	// Setter for this ^
	void SetRoom(Level *room) { currentRoom = room; }

	void Update();


	void Move(TileManager* tm);
	int GetNextTileType(TileManager* tm);

private:
	const int SKELLY_HEIGHT = 14;
	const int SKELLY_WIDTH = 14;

	// Status related bools
	bool isAlive;
	bool isStunned;
	
	// Room in which the skeletons spawn
	Level* currentRoom;

	//Directional vector that he's moving in
	Vector2D direction;
	
	// TO BE REMOVED
	const int WALK_NB_FRAME()					{ return 2; }

	const point<int> FRAME_SIZE()				{ return{ 16, 16 }; };

	const point<int> WALK_DOWN_START_SRC()		{ return{ 96, 0 }; };

};

