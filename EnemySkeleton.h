#pragma once

#include "Libraries.h"
#include "Animation.h"
#include "TileManager.h"
#include "Time.h"

class EnemySkeleton
	: public Animation
{
public:
	EnemySkeleton();
	~EnemySkeleton();

	void Update();

	// Size of the Dot collision box
	static const int SKELETON_WIDTH = 16;
	static const int SKELETON_HEIGHT = 16;

	// Moving Stuff
	void Move(Tile *tiles[TileManager::TOTAL_TILES]);
	void MoveBox();
	void ChangesDirection();
	void AddTileToCount();

private:

	// Skeleton vars
	float skeletonX;
	float skeletonY;
	bool isActive;
	bool tileAddedToCount;

	// Sets his look
	void FaceUp();
	void FaceDown();
	void FaceLeft();
	void FaceRight();
	void Attack(float time);

	// Decision variables

	int tilesToWalk;
	int tilesWalked;

	int directionDecision;
	


	// Speed of the Dot
	const float SPEED;

	// Collider
	SDL_Rect collider;

	// States used by Skeleton.
	enum state {
		IDLE
	};
	state currentState;

	void changeState(state newState);

	const int IDLE_NB_FRAME()					{ return 2; }


	const point<int> FRAME_SIZE()				{ return{ 16, 16 }; };
	const point<int> IDLE_START_SRC()		{ return{ 128, 96 }; };

};