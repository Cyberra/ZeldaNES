#include "Slime.h"


Slime::Slime()
	: Enemies(Texture::ID::Slime, NUM_OF_FRAMES(), ANIM_DEFAULT_SPEED, SLIMEY_ANIM_SRC(), FRAME_SIZE())
	, direction(0.0f, -1.0f)
	, slimeyX(820)
	, slimeyY(954)
	, moveTimer(0)
	, randomizer(0)
	, isAlive(true)
	, isStunned(false)
	, currentRoom(nullptr)
{
	SetPosition(slimeyX, slimeyY);
	this->Play();
	this->SetIsLooping(true);
	collider.h = (FRAME_SIZE().x / 3);
	collider.w = (FRAME_SIZE().y / 3);
	collider.x = ((int)slimeyX / 3);
	collider.y = ((int)slimeyX / 3);
	// Sets the moverBox to the Slime's location
	moverBox.h = FRAME_SIZE().x;
	moverBox.w = FRAME_SIZE().y;
	moverBox.x = (int)slimeyX;
	moverBox.y = (int)slimeyY;
}

Slime::~Slime()
{
	delete currentRoom;
}

void Slime::Update()
{
	Animation::Update();
	randomizer = rand() % 4;
	// keeps mover box at the right coordinates all the time.
	moverBox.x = slimeyX;
	moverBox.y = slimeyY;
	// Keeps the slime's collider at the right place at the same time.
	collider.x = ((int)slimeyX / 3);
	collider.y = ((int)slimeyX / 3);

}
// Move the collider
void Slime::MoveCollider(const Vector2D &direction)
{
	moverBox.x = GetNextPos(direction).x;
	moverBox.y = GetNextPos(direction).y;
}

void Slime::Move(TileManager* tm)
{
	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();
	moveTimer += (40 * dt);
	
	if (moveTimer >= 16)
	{
		ChangeDirection(randomizer);
		moveTimer = 0;
	}
	if (tm->TouchesWall(moverBox))
	{
		slimeyX -= direction.x;
		slimeyY -= direction.y;
		ChangeDirection(randomizer);
	}
	else
	{
		slimeyX += (direction.x * 40) * dt;
		slimeyY += (direction.y * 40) * dt;
	}
	SetPosition(slimeyX, slimeyY);

}
// Checks for a collision at the next tile
point<int> Slime::GetNextPos(const Vector2D &direction)
{
	point<int> p;
	p.x = slimeyX + direction.x;
	p.y = slimeyY + direction.y;
	return p;
}
void Slime::ChangeDirection(int choice)
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
void Slime::Enter(Level* room)
{
	currentRoom = room;
	room->SetEnemies(this);
}