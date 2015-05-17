#include "Enemy.h"

Enemy::Enemy()
	: moveTimer(0)
	, randomizer(0)
	, direction(0.0f, -1.0f)
	, isAlive(true)
	, isStunned(false)
{
}

Enemy::Enemy(Texture::ID id, int nbFrame, int frameRate, const point<int>& srcPos, const point<int>& frameSize)
	: Animation(id, nbFrame, frameRate, srcPos, frameSize)
	, moveTimer(0)
	, randomizer(0)
	, direction(0.0f, -1.0f)
	, isAlive(true)
	, isStunned(false)
{
}

Enemy::~Enemy()
{
	currentRoom = nullptr;
}

// Moves the collider
void Enemy::MoveCollider(const Vector2D &direction)
{
	collider.x = GetNextPos(direction).x;
	collider.y = GetNextPos(direction).y;
}

point<int> const Enemy::GetNextPos(const Vector2D &direction)
{
	point<int> p;
	p.x = (int)(xPos + direction.x);
	p.y = (int)(yPos + direction.y);
	return p;
}

void Enemy::ChangeDirection(int choice)
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

// Lacerate determines when the Enemy gets hit by the player's sword.
void Enemy::Lacerate(SDL_Rect hitter)
{
	// Collision detection based upon our hitter/collider as rectangles.
	Rectangle *r1 = new Rectangle((float)hitter.x, (float)hitter.y, (float)hitter.w, (float)hitter.h);
	Rectangle *r2 = new Rectangle((float)this->collider.x, (float)this->collider.y, (float)this->collider.w, (float)this->collider.h);

	if (r2->CollidesWith(r1))
	{
		// This "kills" the enemy so that it no longer appears as being on the screen
		this->isAlive = false;
		this->SetVisible(false);
	}
	delete r2, r1;
	r2 = nullptr;
	r1 = nullptr;
}