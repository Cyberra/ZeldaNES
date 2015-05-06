#pragma once

#include "Animation.h"
#include "TileManager.h"

class Player
	: public Animation
{
public:
	Player();
	Player(Texture::ID id, int nbFrame, int frameRate, const point<int>& srcPos, const point<int>& frameSize);
	
	virtual void Move(TileManager* tm) = 0;
	virtual point<float> GetNextPos(const Vector2D &direction) = 0;

	virtual ~Player();
};

