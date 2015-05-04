#include "HeartDrop.h"


HeartDrop::HeartDrop()
	:Sprite(Texture::ID::HeartDrop, point<int>(164, 36), point<int>(8, 7))
{
}

void HeartDrop::Init(const int spawnX, const int spawnY, SDL_Rect link)
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
	linkRect.x = link.x;
	linkRect.y = link.y;
	linkRect.w = link.w;
	linkRect.h = link.h;
}

HeartDrop::~HeartDrop()
{
}

void HeartDrop::Update()
{
	if (LinkIsTouching(linkRect))
	{
		isVisible = false;
		std::cout << "HEART!!!!" << std::endl;
	}
}

bool HeartDrop::LinkIsTouching(SDL_Rect linkRect)
{
	Rectangle* r1 = new Rectangle(hCollider.x, hCollider.y, hCollider.w, hCollider.h);
	Rectangle* r2 = new Rectangle(linkRect.x, linkRect.y, linkRect.w, linkRect.h);
	if (r1->CollidesWith(r2))
	{
		return true;
	}
	else
	{
		return false;
	}
}