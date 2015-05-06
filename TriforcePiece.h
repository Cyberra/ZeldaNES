#pragma once

#include "Animation.h"
#include "Rectangle.h"
#include "RessourceID.h"

class TriforcePiece :
	public Animation
{
public:
	TriforcePiece();
	~TriforcePiece();

	void Update();
	//Initializing
	void Init(const int spawnX, const int spawnY, SDL_Rect link);

	//Collision check
	bool LinkIsTouching(SDL_Rect linkRect);

	//Size of the collision box for Heart.
	static const int tForce_HEIGHT = 16;
	static const int tForce_WIDTH = 16;

private:

	int x, y;

	//Collider
	SDL_Rect tCollider;
	SDL_Rect linkRect;

	enum state{
		SOCKET,
		HAND
	};

	state currentState;

	void changeState(state newState);

	const int SOCKET_NB_FRAME()					{ return 2; }
	const int HAND_NB_FRAME()					{ return 1; }

	const point<int> FRAME_SIZE()				{ return{ 16, 16 }; };
	const point<int> SOCKET_START_SRC()			{ return{ 176, 48 }; };
	const point<int> HAND_START_SRC()			{ return{ 176, 48 }; };
};

