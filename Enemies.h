#pragma once
#include "Animation.h"
#include "TileManager.h"

class Enemies :
	public Animation
{
public:
	Enemies();
	Enemies();

	virtual ~Enemies();

	virtual void Move(TileManager* tm) = 0;



};

