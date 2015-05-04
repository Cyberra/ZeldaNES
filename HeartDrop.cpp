#include "HeartDrop.h"


HeartDrop::HeartDrop()
	:Sprite(Texture::ID::HeartDrop, point<int>(0, 0), point<int>(8, 7))
{
	linkIsTouching = false;
}

void HeartDrop::Init(const int spawnX, const int spawnY)
{
	//initializing the variables when spawned from pool
	this->x = spawnX;
	this->y = spawnY;
	isVisible = true;
	SetDstFrame(x, y, HEART_WIDTH, HEART_HEIGHT);
	hCollider.x = this->x;
	hCollider.y = this->y;
	hCollider.h = HEART_HEIGHT;
	hCollider.w = HEART_WIDTH;
}

HeartDrop::~HeartDrop()
{
}

void HeartDrop::Update()
{
	if (linkIsTouching)
	{
		isVisible = false;

	}
}