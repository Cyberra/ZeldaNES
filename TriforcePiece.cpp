#include "TriforcePiece.h"


TriforcePiece::TriforcePiece()
	:Animation(Texture::ID::Triforce, SOCKET_NB_FRAME(), 2, SOCKET_START_SRC(), FRAME_SIZE())
{
}


TriforcePiece::~TriforcePiece()
{
}

void TriforcePiece::Init(const int spawnX, const int spawnY, SDL_Rect link)
{
	this->x = spawnX;
	this->y = spawnY;
	this->isVisible = true;
	SetDstFrame(x, y, tForce_WIDTH, tForce_HEIGHT);
	this->tCollider.x = this->x;
	this->tCollider.y = this->y;
	this->tCollider.h = tForce_HEIGHT;
	this->tCollider.w = tForce_WIDTH;
	linkRect.x = link.x;
	linkRect.y = link.y;
	linkRect.w = link.w;
	linkRect.h = link.h;
}

void TriforcePiece::Update()
{
	if (LinkIsTouching)
	{
		return;
	}
}

bool TriforcePiece::LinkIsTouching(SDL_Rect linkRect)
{
	//setting the collision, need to rework it
	Rectangle* r1 = new Rectangle(this->tCollider.x, this->tCollider.y, this->tCollider.w, this->tCollider.h);
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
