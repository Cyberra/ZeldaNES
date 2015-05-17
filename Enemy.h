#pragma once

#include "Animation.h"
#include "Entity.h"
#include "TileManager.h"
#include <random>

class Level;

//////////////////////////////////////////////////////////////////////////////////
// This abstract class is to be implemented in all enemy types.
// It handles most of their basic functions.
// Everything can be reimplemented as needed; bunch of virtual funcs.
//////////////////////////////////////////////////////////////////////////////////

class Enemy :
	public Animation, public virtual Entity
{
public:
	Enemy();
	Enemy(Texture::ID id, int nbFrame, int frameRate, const point<int>& srcPos, const point<int>& frameSize);
	virtual ~Enemy();

	//Changes the enemy's currentRoom
	virtual void Enter(Level* room) = 0;

	// Method that moves the collider for a single frame to check for collisions
	virtual void MoveCollider(const Vector2D &direction);

	// Fancy getter to find the next tile's type. Nearly all Enemy can only move on 00 tile types.
	virtual point<int> const GetNextPos(const Vector2D &direction);

	// Getter for the room in which the Enemy spawns.
	virtual Level const *GetRoom() { return currentRoom; }

	// Sets the direction in which the enemy is moving
	virtual void SetDirection(Vector2D whereIGo){ direction = whereIGo; }

	// Changes the direction when colliding or when having moved at least 1 tile
	virtual void ChangeDirection(int choice);

	// If the collision with the sword is true, then apply damage to the enemy.
	virtual void Lacerate(SDL_Rect hitter);


protected:
	//Cardinal directions for which way the enemy's facing
	enum cardinal { NORTH, SOUTH, EAST, WEST };

	// Directional vector for where the enemy is heading
	Vector2D direction;
	const Vector2D UP{ 0, 1 };
	const Vector2D RIGHT{ 1, 0 };
	const Vector2D DOWN{ 0, -1 };
	const Vector2D LEFT{ -1, 0 };

	//Whether or not the enemy is alive/stunned
	bool isAlive;
	bool isStunned;

	//Used to determine the enemy's direction
	int randomizer;

	//Delay between movements
	float moveTimer;

	//Collider
	SDL_Rect collider;
};

