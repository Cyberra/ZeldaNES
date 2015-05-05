
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

}