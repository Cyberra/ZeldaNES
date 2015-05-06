#include "OpeningScreen.h"


OpeningScreen::OpeningScreen()
{
	// Fonts
	Fonts->LoadFont(Font::ID::tempFont, "Fonts/FFTA_55.ttf", 55);
	titleText = new Text("Press enter to begin", Font::ID::tempFont, 0, Color::WHITE, OpNone);
	titleText->SetPosition(SCREEN_LENGTH / 2, SCREEN_HEIGHT / 2);
}


OpeningScreen::~OpeningScreen()
{

}

void OpeningScreen::Update() 
{
	if (ThisKeyPressed(SDL_SCANCODE_RETURN)) {
		cEngine->DeleteComponent(this);
		cEngine->DeleteComponent(titleText);
		new ZeldaNES();
	}
}

void OpeningScreen::Kill() 
{
	delete this;
}
