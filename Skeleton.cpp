#include "Skeleton.h"


Skeleton::Skeleton()
	: Enemies(Texture::ID::Stalfo, NUM_OF_FRAMES(), ANIM_DEFAULT_SPEED, SKELLY_ANIM_SRC(), FRAME_SIZE())
	, direction(0.0f, -1.0f)
	, skellyX(820)
	, skellyY(954)
	, moveTimer(0)
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


}

Skeleton::~Skeleton()
{
	delete currentRoom;
}

void Skeleton::Update()
{
	Animation::Update();
	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();

	randomizer = rand() % 4;

	collider.x = skellyX;
	collider.y = skellyY;

}
// Move the collider
void Skeleton::MoveCollider(const Vector2D &direction)
{
	collider.x = GetNextPos(direction).x;
	collider.y = GetNextPos(direction).y;
}


void Skeleton::Move(TileManager* tm)
{
	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();
	moveTimer += dt;
	std::cout << randomizer << std::endl;

	if (moveTimer >= (40 * dt))
	{
		ChangeDirection(randomizer);
		moveTimer = 0;
		
	}

	if (tm->TouchesWall(collider))
	{
		ChangeDirection(randomizer);
		std::cout << "gotta change" << std::endl;
	}
	else
	{
		skellyX += (direction.x * 40) * dt;
		skellyY += (direction.y * 40) * dt;
	}

	SetPosition(skellyX, skellyY);

}
// Checks for a collision at the next tile
point<int> Skeleton::GetNextPos(const Vector2D &direction)
{
	point<int> p;
	p.x = skellyX + direction.x;
	p.y = skellyY + direction.y;
	return p;
}
void Skeleton::ChangeDirection(int choice)
{
	switch (choice)
	{
	case NORTH:
		//std::cout << "UP!" << std::endl;

		SetDirection(UP);
		break;
	case EAST:
		//std::cout << "RIGHT!" << std::endl;

		SetDirection(RIGHT);
		break;
	case SOUTH:
		//std::cout << "DOWN!" << std::endl;

		SetDirection(DOWN);
		break;
	case WEST:
		//std::cout << "LEFT!" << std::endl;

		SetDirection(LEFT);
		break;
	default:
		//std::cout << "WHAT!" << std::endl;
		break;
	}
}
void Skeleton::Enter(Level* room)
{
	currentRoom = room;
	room->Show();
	room->SetEnemies(this);
}


/*
Here's how it's going to go:
	-Check collision in front of Skeleton with random direction
		-If clear, move 1 tile (16 pixels) in that direction
		-if not, take random out of 4 and use a switch case to set new direction (0 , 1 / 0 , -1 )
	-after moving 1 tile, random again.
	-Repeat



*/