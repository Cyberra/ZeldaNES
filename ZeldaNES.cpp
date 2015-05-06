#include "ZeldaNES.h"

ZeldaNES::ZeldaNES()
{
	// Loading resources
	//Sounds
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

	//Textures
	Textures->LoadTexture(Texture::ID::LinkAnims, "Textures/ZeldaSprites.png");
	Textures->LoadTexture(Texture::ID::Dot, "Textures/dot.bmp");
	Textures->LoadTexture(Texture::ID::Tile, "Textures/tiles.png");
	Textures->LoadTexture(Texture::ID::DungeonRoom, "Textures/TilesForDungeonMap.png");
	Textures->LoadTexture(Texture::ID::Walls, "Textures/DungeonWalls.png");
	Textures->LoadTexture(Texture::ID::Doors, "Textures/DungeonDoors.png");

	// Render order
	rooms[0] = new Room01();
	rooms[1] = new Room02();
	rooms[2] = new Room03();
	rooms[3] = new Room04();
	rooms[4] = new Room05();
	rooms[5] = new Room06();
	rooms[6] = new Room07();
	rooms[7] = new Room08();
	rooms[8] = new Room09();
	rooms[9] = new Room10();
	rooms[10] = new Room11();
	rooms[11] = new Room12();
	rooms[12] = new Room13();
	rooms[13] = new Room14();
	rooms[14] = new Room15();
	rooms[15] = new RoomBoss();
	rooms[16] = new RoomShop();
	rooms[17] = new RoomTriforce();
	rooms[18] = new RoomUnderground();

	link = new Link();

	// Initialise game
	link->Enter(rooms[0]);
	link->Leave(rooms[1]);
}

ZeldaNES::~ZeldaNES()
{

}

void ZeldaNES::Start()
{

}

void ZeldaNES::Update()
{
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_1))
	{
		if (link->GetRoom() == rooms[0])
		{
			TravelTo(rooms[0], rooms[9], 0);
		}
	}
}

void ZeldaNES::Stop()
{

}

void ZeldaNES::TravelTo(Level* prevRoom, Level* nextRoom, const int direction)
{
	link->Leave(prevRoom);
	link->Enter(nextRoom);
}
