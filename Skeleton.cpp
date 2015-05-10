#include "Skeleton.h"


Skeleton::Skeleton()
	: Enemies(Texture::ID::Stalfo, NUM_OF_FRAMES(), ANIM_DEFAULT_SPEED, SKELLY_ANIM_SRC(), FRAME_SIZE())
	, direction(0.0f, 1.0f)
	, skellyX(804)
	, skellyY(900)
	, randomizer(0)
	, isAlive(true)
	, isStunned(false)
	, doneMoving(false)
	, currentRoom(nullptr)
{
	SetPosition(skellyX, skellyY);
	this->Play();
	this->SetIsLooping(true);
	collider.h = FRAME_SIZE().x;
	collider.w = FRAME_SIZE().y;
	collider.x = (int)skellyX;
	collider.y = (int)skellyY;

	checker.h = FRAME_SIZE().x;
	checker.w = FRAME_SIZE().y;
	checker.x = (int)skellyX;
	checker.y = (int)skellyY;

}

Skeleton::~Skeleton()
{
	delete currentRoom;
}

void Skeleton::Update()
{
	Animation::Update();
	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();
	if (doneMoving)
	{
		randomizer = rand() % 5;
		ChangeDirection(randomizer);
	}

}

void Skeleton::Move(TileManager* tm)
{

	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();

	
	if (tm->TouchesWall(checker)) //<---This the function to check collision (TouchesWall)
	{
		ChangeDirection(randomizer);
	}
	//skellyX += (SPEED * direction.x) * dt;

	//skellyY += (SPEED * direction.y) * dt;
	checker.x = GetNextPos(this->direction).x + skellyX;
	checker.y = GetNextPos(this->direction).y + skellyY;
	SetPosition(skellyX, skellyY);

}
// Checks for a collision at the next tile
point<int> Skeleton::GetNextPos(const Vector2D &direction)
{
	point<int> p;
	p.x = skellyX + 16 * direction.x;
	p.y = skellyY + 16 * direction.y;
	return p;
}
void Skeleton::ChangeDirection(int choice)
{
	switch (choice)
	{
	case NORTH:
		SetDirection(UP);
		break;
	case EAST:
		SetDirection(RIGHT);
		break;
	case SOUTH:
		SetDirection(DOWN);
		break;
	case WEST:
		SetDirection(LEFT);
		break;
	default:
		std::cout << "WHAT!" << std::endl; 
		break;
	}
}

/*
Here's how it's going to go:
	-Check collision in front of Skeleton with random direction
		-If clear, move 1 tile (16 pixels) in that direction
		-if not, take random out of 4 and use a switch case to set new direction (0 , 1 / 0 , -1 )
	-after moving 1 tile, random again.
	-Repeat



*/