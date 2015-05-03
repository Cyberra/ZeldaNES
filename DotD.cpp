#include "DotD.h"

const int DotD::DOT_WIDTH;
const int DotD::DOT_HEIGHT;

DotD::DotD()
	: Sprite(Texture::ID::Dot)
	, currentX(0)
	, currentY(0)
	, SPEED(100.0f)
	, lastX(0)
	, lastY(0)
{
	box.w = DOT_WIDTH;
	box.h = DOT_HEIGHT;

	box.x = (int)currentX;
	box.y = (int)currentY;
}

DotD::~DotD()
{

}

// Move and check collision
void DotD::Move(Tile *tiles[TileManager::TOTAL_TILES])
{
	Vector2D direction = Vector2D(
		Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_A) ? -1.0f : 0 + Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_D) ? 1.0f : 0,
		Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_S) ? 1.0f : 0 + Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_W) ? -1.0f : 0);

	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();
	//Move the dot left or right
	currentX += (SPEED * direction.x) * dt;

	//If the dot went too far to the left or right or touched a wall
	if ((box.x < 0) || (box.x + DOT_WIDTH > LEVEL_WIDTH) || TileManager::TouchesWall(box, tiles)) //<---This the function to check collision (TouchesWall)
	{
		//move back
		currentX = lastX;
	}

	//Move the dot up or down
	currentY += (SPEED * direction.y) * dt;

	//If the dot went too far up or down or touched a wall
	if ((box.y < 0) || (box.y + DOT_HEIGHT > LEVEL_HEIGHT) || TileManager::TouchesWall(box, tiles))
	{
		//move back
		currentY = lastY;
	}

	lastX = currentX;
	lastY = currentY;
	SetPosition(currentX, currentY);
	MoveBox();
}

// Move the collider
void DotD::MoveBox()
{
	box.x = (int)currentX;
	box.y = (int)currentY;
}

// Update Everything!!!!!!!
void DotD::Update()
{
	Sprite::Update();
	Move(TileManager::tiles);
}
