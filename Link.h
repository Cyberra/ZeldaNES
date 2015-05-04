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
	static const int LINK_WIDTH = 14;
	static const int LINK_HEIGHT = 14;

	// Moving Stuff
	void Move(Tile *tiles[TileManager::TOTAL_TILES]);
	void MoveBox();
	
private:

	// Link stats
	float linkX;
	float linkY;
	bool isCollecting;
	bool facingLeft;
	bool facingRight;
	bool facingUp;
	bool facingDown;
	bool isAttacking;
	bool isMoving;

	// Sets his look
	void FaceUp();
	void FaceDown();
	void FaceLeft();
	void FaceRight();
	void Attack(float time);

	float attackTimer;

	// Speed of the Dot
	const float SPEED;

	// Collider
	SDL_Rect collider;

	// States used by Link.
	enum state { IDLE, WALK_LEFT, WALK_RIGHT, 
					WALK_UP, WALK_DOWN, ATK_LEFT, 
					ATK_RIGHT, ATK_UP, ATK_DOWN, 
					PICK_OBJECT, HURT_LEFT, HURT_RIGHT, 
					HURT_UP, HURT_DOWN };
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

