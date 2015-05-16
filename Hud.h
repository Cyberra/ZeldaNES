#pragma once
#include "Sprite.h"
class Hud :
	public Sprite
{
public:
	Hud();
	Hud(*link);
	~Hud();

	Sprite* sprite;

	// Virtuals used
	void Update();
	void Kill() { delete this; }

	// Virtual unused
	void Start() {}
	void Draw() {}
	void Stop() {}

private:

	// Info needed
	int linkHealth;
	int linkMaxHealth;

	void Hud::ShowHearts();
};

