#pragma once

#include "Animation.h"
#include "RessourceID.h"

class Objects :
	public Animation
{
public:
	Objects();
	Objects(Texture::ID id, int nbFrame, int animSpeed, const point<int> src, const point<int> size);
	
	virtual void Move() = 0;
	virtual void Show() = 0;
	virtual void Clear() = 0;

	virtual ~Objects();
};

