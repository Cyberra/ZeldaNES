#include "ZeldaNES.h"

//Creating camera
Camera* ZeldaNES::camera = new Camera();

const int NB_ROOMS = 18;

ZeldaNES::ZeldaNES()
:currentState(None)
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
	Musics->LoadMusic(Music::ID::Title, "Music/TitleTheme.mp3");

	//Textures
	Textures->LoadTexture(Texture::ID::LinkAnims, "Textures/ZeldaSprites.png");
	Textures->LoadTexture(Texture::ID::Stalfo, "Textures/ZeldaSprites.png");
	Textures->LoadTexture(Texture::ID::Slime, "Textures/ZeldaSprites.png");
	Textures->LoadTexture(Texture::ID::MoblinBlue, "Textures/ZeldaSprites.png");
	Textures->LoadTexture(Texture::ID::MoblinRed, "Textures/ZeldaSprites.png");
	Textures->LoadTexture(Texture::ID::Bats, "Textures/ZeldaSprites.png");
	Textures->LoadTexture(Texture::ID::Aquamentis, "Textures/ZeldaSprites.png");
	Textures->LoadTexture(Texture::ID::Dot, "Textures/dot.bmp");
	Textures->LoadTexture(Texture::ID::DungeonRoom, "Textures/TilesForDungeonMap.png");
	Textures->LoadTexture(Texture::ID::Walls, "Textures/DungeonWalls.png");
	Textures->LoadTexture(Texture::ID::Doors, "Textures/DungeonDoors.png");
	Textures->LoadTexture(Texture::ID::Triforce, "Textures/ZeldaSprites.png");
	Textures->LoadTexture(Texture::ID::HeartDrop, "Textures/ZeldaSprites.png");
	Textures->LoadTexture(Texture::ID::Bombe, "Textures/ZeldaSprites.png");
	Textures->LoadTexture(Texture::ID::Smog, "Textures/ZeldaSprites.png");
	Textures->LoadTexture(Texture::ID::OpeningAnim, "Textures/OpenAnim.jpg");

	// Fonts
	Fonts->LoadFont(Font::ID::tempFont, "Fonts/FFTA_55.ttf", 21);

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

	// Our title screen
	titleScreen = new TitleScreen();

	// Characters
	link = new Link();
	skelly = new Skeleton();
	slimey = new Slime();
	mobRed = new MoblinRed();
	mobBlue = new MoblinBlue();
	bats = new Bats();

	// HUD
	//hud = new Hud(link*);

	Start();
}

ZeldaNES::~ZeldaNES()
{
	delete camera;
	camera = nullptr;
}

//As soon as the game start we start with the title screen
void ZeldaNES::Start()
{
	SwitchState(Title);
}

//Every frame, handle inputs and update the camera
void ZeldaNES::Update()
{
	HandleInputs();
	UpdateCamera();
	
	//Here's my idea of the logic behind it.
	// I can only think of making a collider for each room and when Link's
	// collider overlaps the other room, he "travels" to it.
	//std::cout << link->GetCurrentPos().x << std::endl;
	//
	//if (link->GetCurrentPos().x >= rooms[0]->GetRoomOffset().x
	//	|| link->GetCurrentPos().x <= rooms[0]->GetRoomOffset().x + LEVEL_WIDTH)
	//{
	//	TravelTo(rooms[0], 0);
	//}
	//else if (link->GetCurrentPos().x >= rooms[1]->GetRoomOffset().x
	//	|| link->GetCurrentPos().x <= rooms[1]->GetRoomOffset().x + LEVEL_WIDTH)
	//{
	//	TravelTo(rooms[1], 0);
	//}

	
	

}

void ZeldaNES::Stop()
{

}

//Remove link's reference from the current room and add him to the specified one.
//This also makes the new room the current active one.
void ZeldaNES::TravelTo(Level* nextRoom, const int direction)
{
	link->Leave(currentRoom);
	link->Enter(nextRoom);
	currentRoom = nextRoom;
}

void ZeldaNES::UpdateCamera()
{
	
}

void ZeldaNES::HandleInputs()
{
	switch (currentState)
	{
	case (Title):
	{
		//From the main title press Enter to start the game
		if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_RETURN))
		{
			SwitchState(Dungeon);
		}
		break;
	}
	case (Dungeon):
	{
		// Press the associated number to see all Room.
		if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_Q))
		{
		 TravelTo(rooms[0], 0);
		}
		else if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_1))
		{
		 TravelTo(rooms[1], 0);
		}
		else if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_2))
		{
		 TravelTo(rooms[2], 0);
		}
		else if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_3))
		{
		 TravelTo(rooms[3], 0);
		}
		else if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_4))
		{
		 TravelTo(rooms[4], 0);
		}
		else if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_5))
		{
		 TravelTo(rooms[5], 0);
		}
		else if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_6))
		{
		 TravelTo(rooms[6], 0);
		}
		else if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_7))
		{
		 TravelTo(rooms[7], 0);
		}
		else if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_8))
		{
		 TravelTo(rooms[8], 0);
		}
		else if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_9))
		{
		 TravelTo(rooms[9], 0);
		}
		else if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_0))
		{
		 TravelTo(rooms[10], 0);
		}
		//Press B to deploy a bomb
		if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_B))
		{
		 bomb = new Bomb();
		 //bomb->Update();
		 bomb->TouchesBomb();
		}
		//Press R to go back to the Title Screen
		if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_R))
		{
			SwitchState(Title);
		}
		break;
	}
	default:
		break;
	}
}

//Handle what happens upon changing the game state
void ZeldaNES::SwitchState(GameStates state)
{
	if (currentState != state)
	{
		currentState = state;
		switch (state)
		{
		case (Dungeon) :
			currentRoom = rooms[0];
			titleScreen->Stop();
			//AudioSys->PlayMusic(Musics->Get(Music::ID::Dungeon));
			//for (int i = 0; i < NB_ROOMS; i++)
			//{
			//	rooms[i]->SetActive(true);
			//}
			skelly	    ->SetActive(true);
			slimey	    ->SetActive(true);
			link	    ->SetActive(true);
			bats		->SetActive(true);
			mobRed		->SetActive(true);
			mobBlue		->SetActive(true);
			currentRoom->SetActive(true);
			link		->Enter(rooms[0]);
			link		->Leave(rooms[1]);
			skelly		->Enter(currentRoom);
			slimey		->Enter(currentRoom);
			bats		->Enter(currentRoom);
			mobRed		->Enter(currentRoom);
			mobBlue		->Enter(currentRoom);
			break;
		case (Title) :
			titleScreen->Start();
			for (int i = 0; i < NB_ROOMS; i++)
			{
				rooms[i]->SetActive(false);
			}
			skelly      ->SetActive(false);
			slimey      ->SetActive(false);
			link        ->SetActive(false);
			bats        ->SetActive(false);
			mobRed      ->SetActive(false);
			mobBlue     ->SetActive(false);
			break;
		default:
			break;
		}
	}
}