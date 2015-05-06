#include "OpeningScreen.h"


OpeningScreen::OpeningScreen()
{
	Fonts->LoadFont(Font::ID::tempFont, "Fonts/FFTA_55.ttf", 55);
	Textures->LoadTexture(Texture::ID::OpeningAnim, "Textures/OpenAnim.jpg");
	background = new Animation(Texture::ID::OpeningAnim, 3, 6, point<int>(0, 0), point<int>(256, 240));
	titleText = new Text("Press enter to begin", Font::ID::tempFont, 0, Color::WHITE, OpNone);
	titleText->SetPosition(SCREEN_LENGTH / 2, SCREEN_HEIGHT / 2);
	background->SetIsLooping(true);
	background->Play();
}


OpeningScreen::~OpeningScreen()
{

}

void OpeningScreen::Update() 
{
	if (ThisKeyPressed(SDL_SCANCODE_RETURN)) {
		cEngine->DeleteComponent(this);
		cEngine->DeleteComponent(titleText);
		cEngine->DeleteComponent(background);
		new ZeldaNES();
	}
}

void OpeningScreen::Kill() 
{
	delete this;
}
