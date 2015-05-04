#pragma once

#include "Common.h"
#include "Sprite.h"
#include "RessourceID.h"
#include "PoolObject.h"
#include "Link.h"
#include "Rectangle.h"


class HeartDrop
	: public Sprite, public PoolObject<HeartDrop>//the pool we draw the hearts from
{
public:
	HeartDrop();
	~HeartDrop();

	void Update();
	//Initializing
	void Init(const int spawnX, const int spawnY, SDL_Rect link);

	//Collision check
	bool HeartDrop::LinkIsTouching(SDL_Rect Link);

	//Size of the collision box for Heart.
	static const int HEART_HEIGHT = 8;
	static const int HEART_WIDTH = 7;

	//Collider
	SDL_Rect hCollider;
	SDL_Rect linkRect;

private:
	int x, y;
};

