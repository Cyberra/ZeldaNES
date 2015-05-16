#include "MoblinBlue.h"


MoblinBlue::MoblinBlue()
	: Enemies(Texture::ID::MoblinRed, NUM_OF_FRAMES(), ANIM_DEFAULT_SPEED, MOB_BLUE_ANIM_SRC(), FRAME_SIZE())
	, direction(0.0f, -1.0f)
	, mobBlueX(900)
	, mobBlueY(900)
	, moveTimer(0)
	, randomizer(0)
	, isAlive(true)
	, isStunned(false)
	, currentRoom(nullptr)
{
	SetPosition(mobBlueX, mobBlueY);
	this->Play();
	this->SetIsLooping(true);
	collider.h = FRAME_SIZE().x;
	collider.w = FRAME_SIZE().y;
	collider.x = (int)mobBlueX;
	collider.y = (int)mobBlueY;
}

MoblinBlue::~MoblinBlue()
{
	delete currentRoom;
}

void MoblinBlue::Update()
{
	if (isAlive)
	{
		Animation::Update();
		randomizer = rand() % 4;
		collider.x = mobBlueX;
		collider.y = mobBlueY;
	}
}
// Move the collider
void MoblinBlue::MoveCollider(const Vector2D &direction)
{
	collider.x = GetNextPos(direction).x;
	collider.y = GetNextPos(direction).y;
}

void MoblinBlue::Move(TileManager* tm)
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
			mobBlueX -= direction.x;
			mobBlueY -= direction.y;
			ChangeDirection(randomizer);
		}
		else
		{
			mobBlueX += (direction.x * 40) * dt;
			mobBlueY += (direction.y * 40) * dt;
		}
		SetPosition(mobBlueX, mobBlueY);
	}
}
// Checks for a collision at the next tile
point<int> MoblinBlue::GetNextPos(const Vector2D &direction)
{
	point<int> p;
	p.x = mobBlueX + direction.x;
	p.y = mobBlueY + direction.y;
	return p;
}
void MoblinBlue::ChangeDirection(int choice)
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
void MoblinBlue::Enter(Level* room)
{
	currentRoom = room;
	room->SetEnemies(this);
}

void MoblinBlue::Lacerate(SDL_Rect hitter)
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