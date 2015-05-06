#include "HeartDrop.h"


HeartDrop::HeartDrop()
	:Sprite(Texture::ID::HeartDrop, point<int>(164, 36), point<int>(HEART_WIDTH, HEART_HEIGHT))
{
	//when creating a new heart, you have to start it's Init() from where you create it
}

void HeartDrop::Init(const int spawnX, const int spawnY, SDL_Rect link)
{
	//initializing the variables when spawned from pool
	this->x = spawnX;
	this->y = spawnY;
	this->isVisible = true;
	SetDstFrame(x, y, HEART_WIDTH, HEART_HEIGHT);
	this->hCollider.x = this->x;
	this->hCollider.y = this->y;
	this->hCollider.h = HEART_HEIGHT;
	this->hCollider.w = HEART_WIDTH;
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
	//need to UP Link's health, right now it's only disapearing
	if (LinkIsTouching(linkRect))
	{
		this->isVisible = false;
		std::cout << "HEART!!!!" << std::endl;
	}
}

bool HeartDrop::LinkIsTouching(SDL_Rect linkRect)
{
	//setting the collision, need to rework it
	Rectangle* r1 = new Rectangle(this->hCollider.x, this->hCollider.y, this->hCollider.w, this->hCollider.h);
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