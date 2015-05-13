#include "OpeningScreen.h"


OpeningScreen::OpeningScreen()
{
	Fonts->LoadFont(Font::ID::tempFont, "Fonts/FFTA_55.ttf", 21);
	Textures->LoadTexture(Texture::ID::OpeningAnim, "Textures/OpenAnim.jpg");
	Musics->LoadMusic(Music::ID::Title, "Music/TitleTheme.mp3");
	background = new Animation(Texture::ID::OpeningAnim, 6, 9, point<int>(0, 0), point<int>(800, 750));
	background->ResizeTo(256, 240);
	titleText = new Text("Press enter to begin", Font::ID::tempFont, 0, Color::BLACK, OpFadeIn);
	titleText->SetPosition(65, 149);
	background->SetIsLooping(true);
	background->Play();
	AudioSys->PlayMusic(Musics->Get(Music::ID::Title));
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