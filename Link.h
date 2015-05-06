#pragma once

#include "Libraries.h"
#include "Player.h"
#include "Level.h"
#include "Pool.h"
#include "Boomerang.h"

class Link
	: public Player
{
public:
	Link();
	~Link();

	void Update();

	// Getter
	Level const *GetRoom() { return actualRoom; }

	// Size of the Dot collision box
	static const int LINK_WIDTH = 14;
	static const int LINK_HEIGHT = 14;

	// Moving Stuff
	void Enter(Level* room);
	void Leave(Level* room);
	void Move(TileManager* tm);
	void MoveBox();

	bool isAttacking;
	
private:

	// Speed of the Dot
	const float SPEED;

	// Name
	std::string name;

	// States used by Link.
	enum state {
		IDLE, 
		WALK_LEFT, 
		WALK_RIGHT,
		WALK_UP, 
		WALK_DOWN, 
		ATK_LEFT,
		ATK_RIGHT, 
		ATK_UP, 
		ATK_DOWN,
		PICK_OBJECT, 
		HURT_LEFT, 
		HURT_RIGHT,
		HURT_UP, 
		HURT_DOWN
	};

	// Sets his look
	void FaceUp();
	void FaceDown();
	void FaceLeft();
	void FaceRight();
	void Attack(float time);

	float attackTimer;
	float linkX;
	float linkY;
	bool isCollecting;
	bool facingLeft;
	bool facingRight;
	bool facingUp;
	bool facingDown;
	bool isMoving;

	Level *actualRoom;

	Pool<Boomerang>* boomerangPool;
	Boomerang* actualBoomerang;

	SDL_Rect collider;
	state currentState;

	void changeState(state newState);

	const int WALK_NB_FRAME()					{ return 2; }
	const int HURT_NB_FRAME()					{ return 2; }
	const int ATK_NB_FRAME()					{ return 1; }
	const int PICKUP_NB_FRAME()					{ return 1; }
	const int BOOMERANG_NB_FRAME()				{ return 4; }

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
	const point<int> BOOMERANG_START_SRC()		{ return{ 16, 16 }; };
};

