#include "TitleScreen.h"

TitleScreen::TitleScreen()
{
	background = new Animation(Texture::ID::OpeningAnim, 6, 9, point<int>(0, 0), point<int>(800, 750));
	background->ResizeTo(256, 240);
	text = new Text("Press enter to begin", Font::ID::tempFont, 0, Color::BLACK, OpFadeIn);
	text->SetPosition(65, 149);
	background->SetIsLooping(true);
	Start();
}


TitleScreen::~TitleScreen()
{
}

void TitleScreen::Start()
{
	//AudioSys->PlayMusic(Musics->Get(Music::ID::Title));
	background->Play();
	background->SetActive(true);
}

void TitleScreen::Stop()
{
	//AudioSys->StopMusic();
	background->Stop();
	background->SetActive(false);
}