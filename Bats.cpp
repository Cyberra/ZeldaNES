#include "Bats.h"


Bats::Bats()
	: Enemies(Texture::ID::Bats, NUM_OF_FRAMES(), ANIM_DEFAULT_SPEED, BATS_ANIM_SRC(), FRAME_SIZE())
	, direction(0.0f, -1.0f)
	, batsX(750)
	, batsY(900)
	, moveTimer(0)
	, randomizer(0)
	, isAlive(true)
	, isStunned(false)
	, currentRoom(nullptr)
{
	SetPosition(batsX, batsY);
	this->Play();
	this->SetIsLooping(true);
	collider.h = FRAME_SIZE().x;
	collider.w = FRAME_SIZE().y;
	collider.x = (int)batsX;
	collider.y = (int)batsY;
}

Bats::~Bats()
{
	delete currentRoom;
}

void Bats::Update()
{
	if (isAlive)
	{
		Animation::Update();
		randomizer = rand() % 4;
		collider.x = batsX;
		collider.y = batsY;
	}
}
// Move the collider
void Bats::MoveCollider(const Vector2D &direction)
{
	collider.x = GetNextPos(direction).x;
	collider.y = GetNextPos(direction).y;
}

void Bats::Move(TileManager* tm)
{
	if (isAlive)
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
			batsX -= direction.x;
			batsY -= direction.y;
			ChangeDirection(randomizer);
		}
		else
		{
			batsX += (direction.x * 40) * dt;
			batsY += (direction.y * 40) * dt;
		}
		SetPosition(batsX, batsY);
	}
}
// Checks for a collision at the next tile
point<int> Bats::GetNextPos(const Vector2D &direction)
{
	point<int> p;
	p.x = batsX + direction.x;
	p.y = batsY + direction.y;
	return p;
}
void Bats::ChangeDirection(int choice)
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
void Bats::Enter(Level* room)
{
	currentRoom = room;
	room->SetEnemies(this);
}

void Bats::Lacerate(SDL_Rect hitter)
{
	Rectangle *r1 = new Rectangle(hitter.x, hitter.y, hitter.w, hitter.h);
	Rectangle *r2 = new Rectangle(this->collider.x, this->collider.y, this->collider.w, this->collider.h);

	if (r2->CollidesWith(r1))
	{
		this->isAlive = false;
		this->SetVisible(false);
	}
	delete r2, r1;
	r2 = nullptr;
	r1 = nullptr;
}