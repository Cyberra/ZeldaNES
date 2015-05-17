#pragma once

#include "Libraries.h"
#include "Object.h"
#include "Tile.h"

//////////////////////////////////////////////
//Object: Boomerang
//Throw the boomerang at an enemy to stun it.
//Available in 2017
//////////////////////////////////////////////

class Boomerang
	: public Object
{
public:
	Boomerang();
	~Boomerang();

	void Init(float currentX, float currentY, Vector2D &direction);
	void Clear();
	void Move();
	bool Collides(const Tile *tileToCheck);

private:
	// Boomerang speed
	const int SPEED;

	// Boomerang Direction
	Vector2D direction;

	// Boomerang's position
	float xPos, yPos;

	const int NB_FRAME()						{ return 4; }
	const point<int> FRAME_SIZE()				{ return{ 16, 16 }; };
	const point<int> BOOMERANG_START_SRC()		{ return{ 16, 16 }; };
};

