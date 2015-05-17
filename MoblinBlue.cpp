#include "MoblinBlue.h"

const int SPAWN_X = 820;
const int SPAWN_Y = 640;

MoblinBlue::MoblinBlue()
	: Enemy(Texture::ID::MoblinRed, NUM_OF_FRAMES(), ANIM_DEFAULT_SPEED, MOB_BLUE_DOWN_SRC(), FRAME_SIZE())
{
	xPos = SPAWN_X;
	yPos = SPAWN_Y;
	SetPosition(SPAWN_X, SPAWN_Y);
	this->Play();
	this->SetIsLooping(true);
	collider.h = FRAME_SIZE().x;
	collider.w = FRAME_SIZE().y;
	collider.x = (int)xPos;
	collider.y = (int)yPos;
}

MoblinBlue::~MoblinBlue()
{
}

void MoblinBlue::Update()
{
	if (isAlive)
	{
		Animation::Update();
		randomizer = rand() % 4;
		collider.x = (int)xPos;
		collider.y = (int)yPos;
	}
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
			xPos -= direction.x;
			yPos -= direction.y;
			ChangeDirection(randomizer);
		}
		else
		{
			xPos += (direction.x * 40) * dt;
			yPos += (direction.y * 40) * dt;
		}
		SetPosition((int)xPos, (int)yPos);
	}
}
void MoblinBlue::Enter(Level* room)
{
	currentRoom = room;
	room->SetEnemy(this);
}
void MoblinBlue::ChangeDirection(int choice)
{
	switch (choice)
	{
	case NORTH:
		SetDirection(UP);
		this->SetSrcPos(MOB_BLUE_UP_SRC());
		break;
	case EAST:
		SetDirection(RIGHT);
		this->SetSrcPos(MOB_BLUE_RIGHT_SRC());
		break;
	case SOUTH:
		SetDirection(DOWN);
		this->SetSrcPos(MOB_BLUE_DOWN_SRC());
		break;
	case WEST:
		SetDirection(LEFT);
		this->SetSrcPos(MOB_BLUE_LEFT_SRC());
		break;
	default:
		break;
	}
}