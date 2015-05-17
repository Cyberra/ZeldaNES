#pragma once

#include "TileManager.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//Entity
//This pure virtual base class is shared by Player & Enemies.
//It holds the entity's currentRoom, world coordinates and also forces them to implement the move function.
///////////////////////////////////////////////////////////////////////////////////////////////////////////

class Level;

class Entity
{
public:
	Entity();
	virtual ~Entity();
	
	virtual void Move(TileManager* tm) = 0;
	virtual const point<int> GetNextPos(const Vector2D &direction) = 0;

protected:
	//Room in which the entity is currently in
	Level* currentRoom;

	//Coordinates for the entity's position
	float xPos, yPos;
};

