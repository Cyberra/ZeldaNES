#pragma once

#include "TileManager.h"
#include "Entity.h"
#include "Enemy.h"

/////////////////////////////////////////////
// Level
// This represents one room of the dungeon.
/////////////////////////////////////////////

class Level 
	: public TileManager
{
public:
	// Ctor / Dtor
	Level();
	Level(const std::string mapPath);
	virtual ~Level();

	// Getter / Setter
	void SetPlayer(Entity* l){ player = l; }
	void SetEnemy(Enemy* e){ enemy.push_back(e); }
	virtual point<int> const GetRoomOffset() = 0;
	// Virtuals used
	void Update();
	void Kill() { delete this; }

	// Virtual unused
	void Start() {}
	void Draw() {}
	void Stop() {}

protected:
	Entity* player;
	std::vector<Enemy*>::iterator iter;
	std::vector<Enemy*> enemy;
};
