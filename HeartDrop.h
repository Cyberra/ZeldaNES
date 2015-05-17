#pragma once

#include "Common.h"
#include "Sprite.h"
#include "RessourceID.h"
#include "PoolObject.h"
#include "Rectangle.h"

/////////////////////////////////////////////
// Object: Heartdrop
// Grab these to recover some your health...
/////////////////////////////////////////////

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
	bool LinkIsTouching(SDL_Rect linkRect);

	//Size of the collision box for Heart.
	static const int HEART_HEIGHT = 8;
	static const int HEART_WIDTH = 7;

	

private:
	int x, y;
	
	//Colliders
	SDL_Rect hCollider;
	SDL_Rect linkRect;
};

