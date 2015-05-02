#pragma once

#include "Libraries.h"
#include "TileManager.h"
class DotD:
	public Sprite
{
public:
	DotD();
	~DotD();

	void Update();

	static const int DOT_WIDTH = 20;
	static const int DOT_HEIGHT = 20;

	static const float SPEED;

	void Move(Tile *tiles[192]);

	void MoveBox();

private:
	SDL_Rect box;

	float currentX, currentY;
};

