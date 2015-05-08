#pragma once
#include "Libraries.h"
#include "ZeldaNES.h"
#include "Player.h"

class OpeningScreen : public Component
{
public:
	OpeningScreen();
	~OpeningScreen();

	// Virtuals used
	void Update();
	void Kill() { delete this; }

	// Virtuals unused
	void Start() {}
	void Draw() {}
	void Stop() {}

private:
	Text* titleText;
	Animation* background;
};

