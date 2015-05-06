#pragma once

#include "Libraries.h"
#include "Objects.h"
#include "Tile.h"

class Boomerang
	: public Objects
{
public:
	Boomerang();
	~Boomerang();

	void Init(float currentX, float currentY, Vector2D &direction);
	void Clear();
	void Move();
	bool Collides(const Tile *tileToCheck);

private:
	// Speed of the bullet
	const int SPEED;

	// Direction of the bullet
	Vector2D direction;

	// Position of the bullet
	float currentX, currentY;

	const int NB_FRAME()						{ return 4; }

	const point<int> FRAME_SIZE()				{ return{ 16, 16 }; };
	const point<int> BOOMERANG_START_SRC()		{ return{ 16, 16 }; };
};

