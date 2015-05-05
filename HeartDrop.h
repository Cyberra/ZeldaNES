#pragma once

#include "Common.h"
#include "Sprite.h"
#include "RessourceID.h"
#include "PoolObject.h"
#include "Link.h"
#include "Rectangle.h"


class HeartDrop
	: public Sprite
{
public:
	HeartDrop();
	~HeartDrop();

	void Update();
	//Initializing
	void Init(const int spawnX, const int spawnY, SDL_Rect link);

	//Size of the collision box for Heart.
	static const int HEART_HEIGHT = 8;
	static const int HEART_WIDTH = 7;

private:
	//Collision check
	bool LinkIsTouching(SDL_Rect Link);

	//Collider
	SDL_Rect hCollider;
	SDL_Rect linkRect;

	int x, y;
	bool isTouched;
};

