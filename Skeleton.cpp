#include "Skeleton.h"


Skeleton::Skeleton()
	: Enemies(Texture::ID::Stalfo, NUM_OF_FRAMES(), ANIM_DEFAULT_SPEED, SKELLY_ANIM_SRC(), FRAME_SIZE())
	, direction(0.0f, 1.0f)
	, randomizer(0)
	, isAlive(true)
	, isStunned(false)
	, doneMoving(false)
	, currentRoom(nullptr)
{
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

	MoveCollider(direction);
	//If the dot went too far to the left or right or touched a wall
	if (tm->TouchesWall(collider)) //<---This the function to check collision (TouchesWall)
	{
		//move back
		//std::cout << "Aille!!!!" << std::endl;
		//SetDirection
	}
	//skellyX += (SPEED * direction.x) * dt;
	//Move the dot up or down
	
	//If the dot went too far up or down or touched a wall
	if (tm->TouchesWall(collider))
	{
		//move back
		//skellyY -= (SPEED * direction.y) * dt + direction.y;
	}
	//skellyY += (SPEED * direction.y) * dt;
	
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
// Moves the Collider for the next tile
void Skeleton::MoveCollider(Vector2D direction)
{
	collider.x = GetNextPos(direction).x;
	collider.y = GetNextPos(direction).y;
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