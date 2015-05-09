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
	void SetDirection(Vector2D whereIGo){ direction = whereIGo; }
	void ChangeDirection(int choice);

	void Move(TileManager* tm);
	void MoveCollider(Vector2D direction);

private:
	int randomizer;

	enum cardinal {NORTH, SOUTH, EAST, WEST};

	// Status related bools
	bool isAlive;
	bool isStunned;
	bool doneMoving;
	
	// Room in which the skeletons spawn
	Level* currentRoom;

	// Directional vector that he's moving in
	Vector2D direction;
	const Vector2D UP{ 0, 1 };
	const Vector2D RIGHT{ 1, 0 };
	const Vector2D DOWN{ 0, -1 };
	const Vector2D LEFT{ -1, 0 };

	// His coords
	float skellyX;
	float skellyY;

	// Collision box
	SDL_Rect collider;

	// Collision box to check if next tile is non-collision
	SDL_Rect checker;

	point<int> Skeleton::GetNextPos(const Vector2D &direction);
	
	const int NUM_OF_FRAMES()					{ return 2; }
	const point<int> FRAME_SIZE()				{ return{ 16, 16 }; };
	const point<int> SKELLY_ANIM_SRC()			{ return{ 0, 96 }; };

};

