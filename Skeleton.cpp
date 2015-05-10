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
	moveTimer += (40 * dt);
	if (moveTimer >= 16)
	{
		ChangeDirection(randomizer);
		moveTimer = 0;
	}
	if (tm->TouchesWall(collider))
	{
		skellyX -= direction.x;
		skellyY -= direction.y;
		ChangeDirection(randomizer);
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
		break;
	}
}
void Skeleton::Enter(Level* room)
{
	currentRoom = room;
	room->SetEnemies(this);
}