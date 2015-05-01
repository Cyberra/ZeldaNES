#pragma once

#include "Libraries.h"
#include "Animation.h"

class Link
	: public Animation
{
public:
	Link();
	~Link();

	void Update();
	
private:

	// Link stats
	float linkX;
	float linkY;

	// States used by Link.
	enum state { WALK_LEFT, WALK_RIGHT, WALK_UP, WALK_DOWN, ATK_SWORD, ATK_NO_SWORD};
	state currentState;

	void changeState(state newState);

	const int WALK_NB_FRAME() { return 2; }
	const int ATK_SWORD_NB_FRAME() { return 1; }

	const point<int> FRAME_SIZE() { return{ 16, 15 }; };
	const point<int> FRAME_SIZE1() { return{ 16, 15 }; };
	const point<int> FRAME_SIZE2() { return{ 16, 15 }; };
	const point<int> FRAME_SIZE() { return{ 16, 15 }; };
	const point<int> WALK_LEFT_START_SRC() { return{ 00, 0 }; };
	const point<int> WALK_RIGHT_START_SRC() { return{ 32, 0 }; };
	const point<int> WALK_UP_START_SRC() { return{ 16, 0 }; };
	const point<int> WALK_DOWN_START_SRC() { return{ 48, 0 }; };
	const point<int> ATK_SWORD_LEFT_START_SRC() { return{ 48, 0 }; };
	const point<int> ATK_SWORD_RIGHT_START_SRC() { return{ 48, 0 }; };
	const point<int> ATK_SWORD_UP_START_SRC() { return{ 48, 0 }; };
	const point<int> ATK_SWORD_DOWN_START_SRC() { return{ 48, 0 }; };
	const point<int> ATK_NO_SWORD_LEFT_START_SRC() { return{ 48, 0 }; };
	const point<int> ATK_NO_SWORD_RIGHT_START_SRC() { return{ 48, 0 }; };
	const point<int> ATK_NO_SWORD_UP_START_SRC() { return{ 48, 0 }; };
	const point<int> ATK_NO_SWORD_DOWN_START_SRC() { return{ 48, 0 }; };
};

