
#include "Libraries.h"
#include "TileManager.h"
#include "DotD.h"
#include "Link.h"

#define SCREEN_LENGTH 1280
#define SCREEN_HEIGHT 960

int main(int argc, char* args[])
{
	// Initialize the engine
	Engine::GetInstance()->Init(SCREEN_LENGTH, SCREEN_HEIGHT);

	// Loading resources
	Textures->LoadTexture(Texture::ID::LinkAnims, "Textures/ZeldaSprites.png");
	Textures->LoadTexture(Texture::ID::Dot, "Textures/dot.bmp");
	Textures->LoadTexture(Texture::ID::Tile, "Textures/tiles.png");
	//Textures->LoadTexture(Texture::ID::Level1n1, "Images/MapStuff.png");
	//Sounds->LoadSound(SE::ID::MarioJump, "SE/MarioJump.mp3");
	//Musics->LoadMusic(Musiceroni::ID::Music1, "Music/MusicLevel1.mp3");
	//Fonts->LoadFont(Font::ID::MarioFont, "myFont.ttf", 10);

	TileManager *m = new TileManager();
	m->SetTiles(TileManager::tiles);
	Link *link = new Link();

	Engine::GetInstance()->Run();

	return 0;
}