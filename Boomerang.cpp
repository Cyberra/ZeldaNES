
#include "Boomerang.h"

Boomerang::Boomerang()
	: Objects(Texture::ID::LinkAnims, NB_FRAME(), ANIM_DEFAULT_SPEED, BOOMERANG_START_SRC(), FRAME_SIZE())
	, SPEED(60)
{
	isVisible = false;
	//Start the animation on creation
	this->Play();
	//Make it loop
	this->SetIsLooping(true);
}

Boomerang::~Boomerang()
{

}

void Boomerang::Init(float currentX, float currentY, Vector2D &direction)
{
	if (direction.x == 0 && direction.y == 0)
	{
		direction.y = 1;
	}

	isVisible = true;
	this->direction = direction;
	this->currentX = currentX;
	this->currentY = currentY;
	SetPosition((int)this->currentX, (int)this->currentY);
}

void Boomerang::Clear()
{
	isVisible = false;
}

void Boomerang::Move()
{
	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();

	currentX += SPEED * direction.x * dt;
	currentY += SPEED * direction.y * dt;

	this->SetPosition((int)currentX, (int)currentY);
}

// Function that check if there is a collision
bool Boomerang::Collides(const Tile *tileToCheck)
{
	bool canMove = true;

	//switch (tileToCheck->GetId())
	//{
	//case TILE_TYPE_NONE:
	//	break;
	//
	//case TILE_TYPE_BLOCK:
	//	canMove = false;
	//	break;
	//
	//case TILE_TYPE_DOOR:
	//	break;
	//
	//case TILE_TYPE_CHEST:
	//	break;
	//
	//case TILE_TYPE_SPAWN:
	//	break;
	//
	//case TILE_TYPE_POT:
	//	break;
	//
	//case TILE_TYPE_FOOD:
	//	break;
	//
	//case TILE_TYPE_KEY:
	//	break;

	//default:
	//	break;
	//}

	return canMove;
}