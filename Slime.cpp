#include "Slime.h"

const int SPAWN_X = 820;
const int SPAWN_Y = 640;

Slime::Slime()
	: Enemy(Texture::ID::Slime, NUM_OF_FRAMES(), ANIM_DEFAULT_SPEED, SLIMEY_ANIM_SRC(), FRAME_SIZE())
{
	xPos = SPAWN_X;
	yPos = SPAWN_Y;
	SetPosition(SPAWN_X, SPAWN_Y);
	this->Play();
	this->SetIsLooping(true);

	// Sets the Slime's collider
	collider.h = (FRAME_SIZE().x / 3);
	collider.w = (FRAME_SIZE().y / 3);
	collider.x = ((int)xPos / 3);
	collider.y = ((int)xPos / 3);

	// Sets the moverBox to the Slime's location
	moverBox.h = FRAME_SIZE().x;
	moverBox.w = FRAME_SIZE().y;
	moverBox.x = (int)xPos;
	moverBox.y = (int)yPos;
}

Slime::~Slime()
{
}

void Slime::Update()
{
	Animation::Update();
	randomizer = rand() % 4;
	// Keeps mover box at the right coordinates all the time.
	moverBox.x = (int)xPos;
	moverBox.y = (int)yPos;
	// Keeps the slime's collider at the right place at the same time.
	collider.x = ((int)xPos / 3);
	collider.y = ((int)xPos / 3);

}

// Moves the slime
// Picks a random direction based upon randomizer.
// It'll change direction upon colliding with a wall.
void Slime::Move(TileManager* tm)
{
	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();
	moveTimer += (40 * dt);
	
	if (moveTimer >= 16)
	{
		ChangeDirection(randomizer);
		moveTimer = 0;
	}
	if (tm->TouchesWall(moverBox))
	{
		xPos -= direction.x;
		yPos -= direction.y;
		ChangeDirection(randomizer);
	}
	else
	{
		xPos += (direction.x * 40) * dt;
		yPos += (direction.y * 40) * dt;
	}
	SetPosition((int)xPos, (int)yPos);
}

void Slime::Enter(Level* room)
{
	currentRoom = room;
	room->SetEnemy(this);
}
