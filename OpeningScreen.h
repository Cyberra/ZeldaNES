#pragma once
#include "Libraries.h"
#include "ZeldaNES.h"
#include "Player.h"

class OpeningScreen : public Component
{
public:
	OpeningScreen();
	~OpeningScreen();

	void Update();
	void Kill();

private:
	Text* titleText;
};

