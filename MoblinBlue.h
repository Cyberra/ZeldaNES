#pragma once
#include "Enemies.h"
#include "Level.h"

class MoblinBlue :
	public Enemies
{
public:
	MoblinBlue();
	~MoblinBlue();

	// Getter for the room in which the Blue Moblin spawns
	Level const *GetRoom() { return currentRoom; }
	// Room setter
	void Enter(Level* room);
	// Updates and some important elements (resets collider to sprite location)
	void Update();
	// Sets the direction in which the enemy is moving
	void SetDirection(Vector2D whereIGo){ direction = whereIGo; }
	// Takes the sword's collider (or whatever projectile) and kills enemy if collision
	void Lacerate(SDL_Rect hitter);

private:
	// Int used to change the direction of the enemy.
	int randomizer;
	// For easy tracking
	enum cardinal { NORTH, SOUTH, EAST, WEST };

	// Status related bools
	bool isAlive;
	bool isStunned;

	// Room in which the Blue Moblin spawn
	Level* currentRoom;

	// Directional vector that he's moving in
	Vector2D direction;
	const Vector2D UP{ 0, 1 };
	const Vector2D RIGHT{ 1, 0 };
	const Vector2D DOWN{ 0, -1 };
	const Vector2D LEFT{ -1, 0 };

	// His coords
	float mobBlueX;
	float mobBlueY;

	float moveTimer;

	// Collision box
	SDL_Rect collider;

	// Changes the direction when colliding or when having moved at least 1 tile
	void ChangeDirection(int choice);
	// Update-like method that takes care of movement
	void Move(TileManager* tm);
	// Method that moves the collider for a single frame to check for collisions
	void MoveCollider(const Vector2D &direction);
	// Used to check the collision of the next position
	point<int> MoblinBlue::GetNextPos(const Vector2D &direction);

	// Animation related stuff ---- TO DO
	const int NUM_OF_FRAMES()					{ return 2; }
	const point<int> FRAME_SIZE()				{ return{ 16, 16 }; };
	const point<int> MOB_BLUE_ANIM_SRC()			{ return{ 64, 80 }; };
};

