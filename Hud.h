#pragma once

#include "Sprite.h"

///////////////////////////////////////////////////////////////////////////
// HUD
// This should display the hud located near the upper portion of the screen.
// >should<
///////////////////////////////////////////////////////////////////////////

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

	// Redundant, should use link's health.
	int linkHealth;
	int linkMaxHealth;

	void Hud::ShowHearts();
};

