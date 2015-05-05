#pragma once

#include "Animation.h"
#include "RessourceID.h"

class Objects :
	public Animation
{
public:
	Objects();
	Objects(Texture::ID id, int nbFrame, int animSpeed, const point<int> src, const point<int> size);
	virtual ~Objects();

	void Clear();
	void Move();
};

