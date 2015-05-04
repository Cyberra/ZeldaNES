#pragma once

#include "TileManager.h"
#include "Player.h"

class Level 
	: public TileManager
{
public:
	// Ctor / Dtor
	Level();
	Level(std::string mapPath);
	virtual ~Level();

	// Getter / Setter
	void SetPlayer(Player* l){ player = l; }
	
	// Virtuals
	void Update();

protected:
	Player* player;

};
