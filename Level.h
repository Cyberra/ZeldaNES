#pragma once

#include "TileManager.h"
#include "Player.h"

class Level 
	: public TileManager
{
public:
	// Ctor / Dtor
	Level();
	Level(const std::string mapPath);
	virtual ~Level();

	// Getter / Setter
	void SetPlayer(Player* l){ player = l; }
	
	// Virtuals used
	void Update();
	void Kill() { delete this; }

	// Virtual unused
	void Start() {}
	void Draw() {}
	void Stop() {}

	// Locals
	void Show();
	void Hide();


protected:
	Player* player;
};
