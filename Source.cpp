
#include "Libraries.h"

#define SCREEN_LENGTH 1280
#define SCREEN_HEIGHT 800

int main(int argc, char* args[])
{
	// Initialize the engine
	Engine::GetInstance()->Init(SCREEN_LENGTH, SCREEN_HEIGHT);

	// Loading resources
	Textures->LoadTexture(Texture::ID::LinkAnims, "Textures/ZeldaSprites.png");
	//Textures->LoadTexture(Texture::ID::Level1n1, "Images/MapStuff.png");
	//Sounds->LoadSound(SE::ID::MarioJump, "SE/MarioJump.mp3");
	//Musics->LoadMusic(Musiceroni::ID::Music1, "Music/MusicLevel1.mp3");
	//Fonts->LoadFont(Font::ID::MarioFont, "myFont.ttf", 10);

	Engine::GetInstance()->Run();

	return 0;
}