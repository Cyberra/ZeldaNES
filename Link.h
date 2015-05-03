#pragma once

#include "Libraries.h"
#include "Animation.h"
#include "TileManager.h"

class Link
	: public Animation
{
public:
	Link();
	~Link();

	void Update();

	// Size of the Dot collision box
	static const int DOT_WIDTH = 20;
	static const int DOT_HEIGHT = 20;

	// Moving Stuff
	void Move(Tile *tiles[TileManager::TOTAL_TILES]);
	void MoveBox();
	
private:

	// Link stats
	float linkX;
	float linkY;
	bool isCollecting;
	bool faceLeft;
	bool faceRight;
	bool faceUp;
	bool faceDown;

	// Speed of the Dot
	const float SPEED;

	// Collider
	SDL_Rect collider;

	// States used by Link.
	enum state { IDLE, WALK_LEFT, WALK_RIGHT, WALK_UP, WALK_DOWN, ATK_LEFT, ATK_RIGHT, ATK_UP, ATK_DOWN, PICK_OBJECT, HURT_LEFT, HURT_RIGHT, HURT_UP, HURT_DOWN };
	state currentState;

	void changeState(state newState);

	const int WALK_NB_FRAME()					{ return 2; }
	const int HURT_NB_FRAME()					{ return 2; }
	const int ATK_NB_FRAME()					{ return 1; }
	const int PICKUP_NB_FRAME()					{ return 1; }

	const point<int> FRAME_SIZE()				{ return{ 16, 16 }; };
	const point<int> WALK_LEFT_START_SRC()		{ return{ 0, 0 }; };
	const point<int> WALK_RIGHT_START_SRC()		{ return{ 64, 0 }; };
	const point<int> WALK_UP_START_SRC()		{ return{ 32, 0 }; };
	const point<int> WALK_DOWN_START_SRC()		{ return{ 96, 0 }; };
	const point<int> ATK_LEFT_START_SRC()		{ return{ 32, 32 }; };
	const point<int> ATK_RIGHT_START_SRC()		{ return{ 16, 48 }; };
	const point<int> ATK_UP_START_SRC()			{ return{ 0, 48 }; };
	const point<int> ATK_DOWN_START_SRC()		{ return{ 48, 32 }; };
	const point<int> HURT_LEFT_START_SRC()		{ return{ 0, 32 }; };
	const point<int> HURT_RIGHT_START_SRC()		{ return{ 32, 32 }; };
	const point<int> HURT_UP_START_SRC()		{ return{ 16, 32 }; };
	const point<int> HURT_DOWN_START_SRC()		{ return{ 48, 32 }; };
	const point<int> PICK_OBJECT_START_SRC()	{ return{ 64, 48 }; };
};

