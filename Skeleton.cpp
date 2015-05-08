#include "Skeleton.h"


Skeleton::Skeleton()
	: Enemies(Texture::ID::LinkAnims, WALK_NB_FRAME(), 0, WALK_DOWN_START_SRC(), FRAME_SIZE())
	, direction(0.0f, 0.0f)
	, isAlive(true)
	, isStunned(false)
	, currentRoom(nullptr)
{
	// Start the animation on creation
	this->Play();
	// Make it loop
	this->SetIsLooping(true);
}

Skeleton::~Skeleton()
{
	delete currentRoom;
}

void Skeleton::Update()
{
	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();
}

void Skeleton::Move(TileManager* tm)
{

}
int Skeleton::GetNextTileType(TileManager* tm)
{
	int type = 0;

	//tm->GetTiles();

	return type;
}