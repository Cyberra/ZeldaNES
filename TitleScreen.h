#pragma once
#include "Libraries.h"

//////////////////////////////////////////////////////////////////
//TitleScreen
//The game starts at the TitleScreen until the player press Enter.
//////////////////////////////////////////////////////////////////

class TitleScreen : public Component
{
public:
	TitleScreen();
	~TitleScreen();

	// Virtuals used
	void Kill() { delete this; }
	void Start();
	void Stop();

	// Virtuals unused
	void Update() {}
	void Draw() {}

private:
	Text* text;
	Animation* background;
};

