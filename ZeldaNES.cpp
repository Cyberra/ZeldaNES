#include "ZeldaNES.h"

//Creating camera
Camera* ZeldaNES::camera = new Camera();


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

	//Music
	Musics->LoadMusic(Music::ID::Dungeon, "Music/DungeonTheme.mp3");

	//Textures
	Textures->LoadTexture(Texture::ID::LinkAnims, "Textures/ZeldaSprites.png");
	Textures->LoadTexture(Texture::ID::Stalfo, "Textures/ZeldaSprites.png");
	Textures->LoadTexture(Texture::ID::Slime, "Textures/ZeldaSprites.png");
	Textures->LoadTexture(Texture::ID::MoblinBlue, "Textures/ZeldaSprites.png");
	Textures->LoadTexture(Texture::ID::MoblinRed, "Textures/ZeldaSprites.png");
	Textures->LoadTexture(Texture::ID::Aquamentis, "Textures/ZeldaSprites.png");
	Textures->LoadTexture(Texture::ID::Dot, "Textures/dot.bmp");
	Textures->LoadTexture(Texture::ID::Tile, "Textures/tiles.png");
	Textures->LoadTexture(Texture::ID::DungeonRoom, "Textures/TilesForDungeonMap.png");
	Textures->LoadTexture(Texture::ID::Walls, "Textures/DungeonWalls.png");
	Textures->LoadTexture(Texture::ID::Doors, "Textures/DungeonDoors.png");
	Textures->LoadTexture(Texture::ID::Triforce, "Textures/ZeldaSprites.png");
	Textures->LoadTexture(Texture::ID::HeartDrop, "Textures/ZeldaSprites.png");

	// Render order
	rooms[0]  = new Room01();
	rooms[1]  = new Room02();
	rooms[2]  = new Room03();
	rooms[3]  = new Room04();
	rooms[4]  = new Room05();
	rooms[5]  = new Room06();
	rooms[6]  = new Room07();
	rooms[7]  = new Room08();
	rooms[8]  = new Room09();
	rooms[9]  = new Room10();
	rooms[10] = new Room11();
	rooms[11] = new Room12();
	rooms[12] = new Room13();
	rooms[13] = new Room14();
	rooms[14] = new RoomBoss();
	rooms[15] = new RoomShop();
	rooms[16] = new RoomTriforce();
	rooms[17] = new RoomUnderground();

	link = new Link();
	skelly = new Skeleton();
	slimey = new Slime();

	// Initialise game
	actualRoom = rooms[0];
	skelly->Enter(rooms[0]);
	slimey->Enter(rooms[0]);
	link->Enter(rooms[0]);
	link->Leave(rooms[1]);

	camera->SetCameraPosition(400, 400);
}

ZeldaNES::~ZeldaNES()
{
	delete camera;
	camera = nullptr;
}

void ZeldaNES::Start()
{

}

void ZeldaNES::Update()
{
	// Press the associated number to see all Room.
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_Q))
	{
		TravelTo(actualRoom, rooms[0], 0);
		actualRoom = rooms[0];
	}

	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_1))
	{
		TravelTo(actualRoom, rooms[1], 0);
		actualRoom = rooms[1];
	}

	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_2))
	{
		TravelTo(actualRoom, rooms[2], 0);
		actualRoom = rooms[2];
	}

	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_3))
	{
		TravelTo(actualRoom, rooms[3], 0);
		actualRoom = rooms[3];
	}

	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_4))
	{
		TravelTo(actualRoom, rooms[4], 0);
		actualRoom = rooms[4];
	}

	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_5))
	{
		TravelTo(actualRoom, rooms[5], 0);
		actualRoom = rooms[5];
	}

	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_6))
	{
		TravelTo(actualRoom, rooms[6], 0);
		actualRoom = rooms[6];
	}

	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_7))
	{
		TravelTo(actualRoom, rooms[7], 0);
		actualRoom = rooms[7];
	}

	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_8))
	{
		TravelTo(actualRoom, rooms[8], 0);
		actualRoom = rooms[8];
	}

	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_9))
	{
		TravelTo(actualRoom, rooms[9], 0);
		actualRoom = rooms[9];
	}

	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_0))
	{
		TravelTo(actualRoom, rooms[10], 0);
		actualRoom = rooms[10];
	}

	UpdateCamera();


}

void ZeldaNES::Stop()
{

}

void ZeldaNES::TravelTo(Level* prevRoom, Level* nextRoom, const int direction)
{
	link->Leave(prevRoom);
	link->Enter(nextRoom);
}

void ZeldaNES::UpdateCamera()
{
	camera->SetCameraPosition(400, 400);
}
