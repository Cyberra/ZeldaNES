#include "DotD.h"

const int DotD::DOT_WIDTH;
const int DotD::DOT_HEIGHT;

const float DotD::SPEED = 100.0f;

DotD::DotD()
	: Sprite(Texture::ID::Dot)
	, currentX(0)
	, currentY(0)
{
	box.w = DOT_WIDTH;
	box.h = DOT_HEIGHT;

	box.x = (int)currentX;
	box.y = (int)currentY;
}

DotD::~DotD()
{

}

void DotD::Move(Tile *tiles[TileManager::TOTAL_TILES])
{
	Vector2D direction = Vector2D(
		Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_A) ? -1.0f : 0 + Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_D) ? 1.0f : 0,
		Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_S) ? 1.0f : 0 + Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_W) ? -1.0f : 0)
		;
//	std::cout << direction.x << ", " << direction.y << std::endl;

	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();
	//Move the dot left or right
	currentX += (SPEED * direction.x) * dt;
	//std::cout << dt << std::endl;

	//If the dot went too far to the left or right or touched a wall
	if ((box.x < 0) || (box.x + DOT_WIDTH > LEVEL_WIDTH) || TileManager::TouchesWall(box, tiles))
	{
		//move back
		//std::cout << dt << std::endl;
		currentX -= (SPEED * direction.x) * dt;
	}

	//Move the dot up or down
	currentY += (SPEED * direction.y) * dt;

	//If the dot went too far up or down or touched a wall
	if ((box.y < 0) || (box.y + DOT_HEIGHT > LEVEL_HEIGHT) || TileManager::TouchesWall(box, tiles))
	{
		//move back
		//std::cout << "OUCH!!" << std::endl;
		currentY -= (SPEED * direction.y) * dt;
	}
	SetPosition(currentX, currentY);
	MoveBox();
}

void DotD::MoveBox()
{
	box.x = (int)currentX;
	box.y = (int)currentY;
}

void DotD::Update()
{
	Sprite::Update();
	Move(TileManager::tiles);
}
