#pragma once

#include "Libraries.h"

////////////////////////////////////////////////////////////////////////////////////////
//Object
//This is the base class for the various in-game Object like the boomerang and the bomb.
////////////////////////////////////////////////////////////////////////////////////////

class Object :
	public Animation
{
public:
	Object();
	Object(Texture::ID id, int nbFrame, int animSpeed, const point<int> src, const point<int> size);
	
	virtual void Move() = 0;
	virtual void Show() = 0;
	virtual void Clear() = 0;

	virtual ~Object();
};

