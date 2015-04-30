

#include "Link.h"

Link::Link()
	:Animation(Texture::ID::LinkAnims, WALK_NB_FRAME(), ANIM_DEFAULT_SPEED, WALK_DOWN_START_SRC(), FRAME_SIZE())
{
	//Start the animation on creation
	this->Play();
	//Make it loop
	this->SetIsLooping(true);
}

Link::~Link()
{

}

void Link::changeState(state newState)
{
	//////////////////////////////////////////////
	// INSERT CASES FOR EACH ANIMS DOWN HERE
	//////////////////////////////////////////////

	if (this->currentState != newState)
	{
		switch (newState)
		{
		case WALK_LEFT:
			this->SetSrcPos(WALK_LEFT_START_SRC());
			this->SetNbFrame(WALK_NB_FRAME());
			this->SetFrameRate(ANIM_DEFAULT_SPEED);
			break;
		case WALK_RIGHT:
			this->SetSrcPos(WALK_RIGHT_START_SRC());
			this->SetNbFrame(WALK_NB_FRAME());
			this->SetFrameRate(ANIM_DEFAULT_SPEED);
			break;
		case WALK_UP:
			this->SetSrcPos(WALK_UP_START_SRC());
			this->SetNbFrame(WALK_NB_FRAME());
			this->SetFrameRate(ANIM_DEFAULT_SPEED);
			break;
		case WALK_DOWN:
			this->SetSrcPos(WALK_DOWN_START_SRC());
			this->SetNbFrame(WALK_NB_FRAME());
			this->SetFrameRate(ANIM_DEFAULT_SPEED);
			break;
		default:
			break;
		}
		//It's important to reset back to the first frame on change
		this->currentState = newState;
		this->ResetCurrentFrame();
	}
}

void Link::Update()
{
	//////////////////////////////////////////////
	// VARIABLES UPDATED EVERY FRAMES
	//////////////////////////////////////////////

	// Get delta time.
	float delta = Engine::GetInstance()->GetTimer()->GetDeltaTime();

	// Very important, otherwise our animation won't update itself
	Animation::Update();

	// Updates position of the player.
	SetPosition((int)linkX, (int)linkY);

	//////////////////////////////////////////////
	// CONTROLS USED TO MOVE LINK
	//////////////////////////////////////////////

	// W
	if (Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_W))
	{
		changeState(WALK_UP);
		linkY--;
	}

	// A
	if (Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_A))
	{
		changeState(WALK_LEFT);
		linkX--;
	}

	// S
	if (Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_S))
	{
		changeState(WALK_DOWN);
		linkY++;
	}

	// D
	if (Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_D))
	{
		changeState(WALK_RIGHT);
		linkX++;
	}
}