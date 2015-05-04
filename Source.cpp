
#include "Libraries.h"
#include "TileManager.h"
#include "DotD.h"
#include "Link.h"

#define SCREEN_LENGTH 1280
#define SCREEN_HEIGHT 960

int main(int argc, char* args[])
{
	// Initialize the engine
	Engine::GetInstance()->Init(800, 750, RESOLUTION_NTSC);

	// Loading resources
	Sounds->LoadSound(Sound::ID::Arrow, "SFX/Arrow.wav");
	Sounds->LoadSound(Sound::ID::DropBomb, "SFX/BombDrop.wav");
	Sounds->LoadSound(Sound::ID::Boomerang, "SFX/Boomerang.wav");
	Sounds->LoadSound(Sound::ID::Die, "SFX/Die.wav");
	Sounds->LoadSound(Sound::ID::Fanfare, "SFX/Fanfare.wav");
	Sounds->LoadSound(Sound::ID::GetHeart, "SFX/GetHeart.wav");
	Sounds->LoadSound(Sound::ID::GetItem, "SFX/GetItem.wav");
	Sounds->LoadSound(Sound::ID::Hit, "SFX/Hit.wav");
	Sounds->LoadSound(Sound::ID::Hurt, "SFX/Hurt.wav");
	Sounds->LoadSound(Sound::ID::Kill, "SFX/Kill.wav");
	Sounds->LoadSound(Sound::ID::LowHealth, "SFX/LowHealth.wav");
	Sounds->LoadSound(Sound::ID::BossScream1, "SFX/BossScream1.wav");
	Sounds->LoadSound(Sound::ID::BossScream2, "SFX/BossScream2.wav");
	Sounds->LoadSound(Sound::ID::GetRupee, "SFX/GetRupee.wav");
	Sounds->LoadSound(Sound::ID::Key, "SFX/Key.wav");
	Sounds->LoadSound(Sound::ID::Secret, "SFX/Secret.wav");
	Sounds->LoadSound(Sound::ID::Stairs, "SFX/Stairs.wav");
	Sounds->LoadSound(Sound::ID::Text, "SFX/Text.wav");
	Sounds->LoadSound(Sound::ID::Unlock, "SFX/Unlock.wav");
	Sounds->LoadSound(Sound::ID::Shield, "SFX/Shield.wav");
	Sounds->LoadSound(Sound::ID::Sword, "SFX/Sword.wav");
	Sounds->LoadSound(Sound::ID::SwordShot, "SFX/SwordShoot.wav");
	Sounds->LoadSound(Sound::ID::CombinShot, "SFX/SwordCombined.wav");
	Textures->LoadTexture(Texture::ID::LinkAnims, "Textures/ZeldaSprites.png");
	Textures->LoadTexture(Texture::ID::Dot, "Textures/dot.bmp");
	Textures->LoadTexture(Texture::ID::Tile, "Textures/tiles.png");
	Textures->LoadTexture(Texture::ID::DungeonRoom, "Textures/TilesForDungeonMap.png");
	Textures->LoadTexture(Texture::ID::Walls, "Textures/DungeonWalls.png");
	Textures->LoadTexture(Texture::ID::Doors, "Textures/DungeonDoors.png");

	TileManager *m = new TileManager();
	m->SetTiles(TileManager::tiles);
	Link *link = new Link();

	Engine::GetInstance()->Run();

	return 0;
}
