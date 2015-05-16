#include "MoblinRed.h"


MoblinRed::MoblinRed()
	: Enemies(Texture::ID::MoblinRed, NUM_OF_FRAMES(), ANIM_DEFAULT_SPEED, MOB_RED_ANIM_SRC(), FRAME_SIZE())
	, direction(0.0f, -1.0f)
	, mobRedX(800)
	, mobRedY(900)
	, moveTimer(0)
	, randomizer(0)
	, isAlive(true)
	, isStunned(false)
	, currentRoom(nullptr)
{
	SetPosition(mobRedX, mobRedY);
	this->Play();
	this->SetIsLooping(true);
	collider.h = FRAME_SIZE().x;
	collider.w = FRAME_SIZE().y;
	collider.x = (int)mobRedX;
	collider.y = (int)mobRedY;
}

MoblinRed::~MoblinRed()
{
	delete currentRoom;
}

void MoblinRed::Update()
{
	if (isAlive)
	{
		Animation::Update();
		randomizer = rand() % 4;
		collider.x = mobRedX;
		collider.y = mobRedY;
	}
}
// Move the collider
void MoblinRed::MoveCollider(const Vector2D &direction)
{
	collider.x = GetNextPos(direction).x;
	collider.y = GetNextPos(direction).y;
}

void MoblinRed::Move(TileManager* tm)
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
			mobRedX -= direction.x;
			mobRedY -= direction.y;
			ChangeDirection(randomizer);
		}
		else
		{
			mobRedX += (direction.x * 40) * dt;
			mobRedY += (direction.y * 40) * dt;
		}
		SetPosition(mobRedX, mobRedY);
	}
}
// Checks for a collision at the next tile
point<int> MoblinRed::GetNextPos(const Vector2D &direction)
{
	point<int> p;
	p.x = mobRedX + direction.x;
	p.y = mobRedY + direction.y;
	return p;
}
void MoblinRed::ChangeDirection(int choice)
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
void MoblinRed::Enter(Level* room)
{
	currentRoom = room;
	room->SetEnemies(this);
}

void MoblinRed::Lacerate(SDL_Rect hitter)
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