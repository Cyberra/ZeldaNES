#include "EnemySkeleton.h"

Vector2D direction = Vector2D(0, 1);

EnemySkeleton::EnemySkeleton()
	: Animation(Texture::ID::LinkAnims, IDLE_NB_FRAME(), 4, IDLE_START_SRC(), FRAME_SIZE())
	, skeletonX(32)
	, skeletonY(32)
	, SPEED(20.0f)
	, tilesToWalk(0)
	, tilesWalked(0)
	, directionDecision()
	, tileAddedToCount(false)
{
	//Start the animation on creation
	this->Play();
	//Make it loop
	this->SetIsLooping(true);

	collider.w = SKELETON_WIDTH;
	collider.h = SKELETON_HEIGHT;

	collider.x = (int)skeletonX;
	collider.y = (int)skeletonY;

	srand(time(0));
	directionDecision = rand() % 4;
	tilesToWalk = rand() % 3 + 2;

}

EnemySkeleton::~EnemySkeleton()
{

}

void EnemySkeleton::changeState(state newState)
{
	//////////////////////////////////////////////
	// SKELETON ONLY HAS IDLE ANIMATION
	//////////////////////////////////////////////

	if (this->currentState != newState)
	{
		switch (newState)
		{
		case IDLE:
			this->SetFrameRate(0);
			break;
		default:
			break;
		}
		//It's important to reset back to the first frame on change
		this->currentState = newState;
		this->ResetCurrentFrame();
	}
}

// Move and check collision
void EnemySkeleton::Move(Tile *tiles[TileManager::TOTAL_TILES])
{
	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();

	//Move the dot left or right
	skeletonX += (SPEED * direction.x) * dt;

	//If the dot went too far to the left or right or touched a wall
	if ((collider.x < 0) || (collider.x + SKELETON_WIDTH > LEVEL_WIDTH) || TileManager::TouchesWall(collider, tiles)) //<---This the function to check collision (TouchesWall)
	{
		//move back
		
		direction.x *= -1;
		ChangesDirection();
	}

	//Move the dot up or down
	skeletonY += (SPEED * direction.y) * dt;

	//If the dot went too far up or down or touched a wall
	if ((collider.y < 0) || (collider.y + SKELETON_HEIGHT > LEVEL_HEIGHT) || TileManager::TouchesWall(collider, tiles))
	{
		//move back
		direction.y *= -1;
		ChangesDirection();
	}

	SetPosition(skeletonX, skeletonY);
	MoveBox();
}

// Move the collider
void EnemySkeleton::MoveBox()
{
	collider.x = (int)skeletonX;
	collider.y = (int)skeletonY;
}

void EnemySkeleton::Update()
{
	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();
	Animation::Update();

	if (((int)skeletonX % 16) == 0 && ((int)skeletonY % 16) == 0 && tileAddedToCount == false)
	{
		tilesWalked++;
		tileAddedToCount = true;
		std::cout << tilesWalked << std::endl;
	}

	if ((int)skeletonX % 16 != 0 && tileAddedToCount == true)
	{
		tileAddedToCount = false;
		std::cout << "YO MOM" << std::endl;
	}

	if (  tilesWalked >= tilesToWalk )
	{
		ChangesDirection();
	}

	Move(TileManager::tiles);
}

void EnemySkeleton::ChangesDirection()
{



	// Goes up or down if going left/right
	//if (direction.y == 0)
	//{
	//	direction.x = 0;
	//	direction.y = 0;
	//	directionDecision = rand() % 2;
	//	if (directionDecision == 0)
	//	{
	//		std::cout << "WOOPS GOING UP" << std::endl;
	//		direction.y = -1;
	//	}
	//	else
	//	{
	//		std::cout << "WOOPS GOING DOWN" << std::endl;
	//		direction.y = 1;
	//	}
	//}
	//else if (direction.y != 0)
	//{
	//	direction.x = 0;
	//	direction.y = 0;
	//
	//	directionDecision = rand() % 2;
	//
	//	if (directionDecision == 0)
	//	{
	//		std::cout << "WOOPS GOING LEFT" << std::endl;
	//		direction.x = -1;
	//	}
	//	else
	//	{
	//		std::cout << "WOOPS GOING RIGHT" << std::endl;
	//		direction.x = 1;
	//	}
	//}
	
	tilesToWalk = rand() % 3 + 2;
	tilesWalked = 0;
}