

#include "Link.h"

Link::Link()
	: Animation(Texture::ID::LinkAnims, WALK_NB_FRAME(), 0, WALK_DOWN_START_SRC(), FRAME_SIZE())
	, linkX(0)
	, linkY(0)
	, SPEED(100.0f)
{
	//Start the animation on creation
	this->Play();
	//Make it loop
	this->SetIsLooping(true);

	collider.w = DOT_WIDTH;
	collider.h = DOT_HEIGHT;

	collider.x = (int)linkX;
	collider.y = (int)linkY;
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
		case IDLE:
			this->SetFrameRate(0);
			break;
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
		case ATK_LEFT:
			this->SetSrcPos(ATK_LEFT_START_SRC());
			this->SetNbFrame(ATK_NB_FRAME());
			this->SetFrameRate(ANIM_DEFAULT_SPEED);
			break;
		case ATK_RIGHT:
			this->SetSrcPos(ATK_RIGHT_START_SRC());
			this->SetNbFrame(ATK_NB_FRAME());
			this->SetFrameRate(ANIM_DEFAULT_SPEED);
			break;
		case ATK_UP:
			this->SetSrcPos(ATK_UP_START_SRC());
			this->SetNbFrame(ATK_NB_FRAME());
			this->SetFrameRate(ANIM_DEFAULT_SPEED);
			break;
		case ATK_DOWN:
			this->SetSrcPos(ATK_DOWN_START_SRC());
			this->SetNbFrame(ATK_NB_FRAME());
			this->SetFrameRate(ANIM_DEFAULT_SPEED);
			break;
		case HURT_LEFT:
			this->SetSrcPos(HURT_LEFT_START_SRC());
			this->SetNbFrame(HURT_NB_FRAME());
			this->SetFrameRate(ANIM_DEFAULT_SPEED);
			break;
		case HURT_RIGHT:
			this->SetSrcPos(HURT_RIGHT_START_SRC());
			this->SetNbFrame(HURT_NB_FRAME());
			this->SetFrameRate(ANIM_DEFAULT_SPEED);
			break;
		case HURT_UP:
			this->SetSrcPos(HURT_UP_START_SRC());
			this->SetNbFrame(HURT_NB_FRAME());
			this->SetFrameRate(ANIM_DEFAULT_SPEED);
			break;
		case HURT_DOWN:
			this->SetSrcPos(HURT_DOWN_START_SRC());
			this->SetNbFrame(HURT_NB_FRAME());
			this->SetFrameRate(ANIM_DEFAULT_SPEED);
			break;
		case PICK_OBJECT:
			this->SetSrcPos(PICK_OBJECT_START_SRC());
			this->SetNbFrame(PICKUP_NB_FRAME());
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

// Move and check collision
void Link::Move(Tile *tiles[TileManager::TOTAL_TILES])
{
	Vector2D direction = Vector2D(
		Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_A) && !(Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_S) || Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_W)) ? -1.0f : 0 +
		Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_D) && !(Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_S) || Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_W)) ? 1.0f : 0,
		Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_S) && !(Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_A) || Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_D)) ? 1.0f : 0 +
		Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_W) && !(Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_A) || Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_D)) ? -1.0f : 0);

	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();

	//Move the dot left or right
	linkX += (SPEED * direction.x) * dt;

	//If the dot went too far to the left or right or touched a wall
	if ((collider.x < 0) || (collider.x + DOT_WIDTH > LEVEL_WIDTH) || TileManager::TouchesWall(collider, tiles)) //<---This the function to check collision (TouchesWall)
	{
		//move back
		linkX -= (SPEED * direction.x) * dt + direction.x;
	}

	//Move the dot up or down
	linkY += (SPEED * direction.y) * dt;

	//If the dot went too far up or down or touched a wall
	if ((collider.y < 0) || (collider.y + DOT_HEIGHT > LEVEL_HEIGHT) || TileManager::TouchesWall(collider, tiles))
	{
		//move back
		linkY -= (SPEED * direction.y) * dt + direction.y;
	}
	SetPosition(linkX, linkY);
	MoveBox();
}

// Move the collider
void Link::MoveBox()
{
	collider.x = (int)linkX;
	collider.y = (int)linkY;
}

// Update Everything!!!!!!!
void Link::Update()
{
	Animation::Update();
	Move(TileManager::tiles);


	//////////////////////////////////////////////
	// ANIMATIONS
	//////////////////////////////////////////////

	// W
	if (Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_W))
	{
		faceLeft = false;
		faceRight = false;
		faceUp = true;
		faceDown = false;
		changeState(WALK_UP);
	}
	else if (Engine::GetInstance()->GetInput()->IsKeyReleased(SDL_SCANCODE_W))
	{
		changeState(IDLE);
	}

	// A
	if (Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_A))
	{
		faceLeft = true;
		faceRight = false;
		faceUp = false;
		faceDown = false;
		changeState(WALK_LEFT);
	}
	else if (Engine::GetInstance()->GetInput()->IsKeyReleased(SDL_SCANCODE_A))
	{
		changeState(IDLE);
	}

	// S
	if (Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_S))
	{
		faceLeft = false;
		faceRight = false;
		faceUp = false;
		faceDown = true;
		changeState(WALK_DOWN);
	}
	else if (Engine::GetInstance()->GetInput()->IsKeyReleased(SDL_SCANCODE_S))
	{
		changeState(IDLE);
	}

	// D
	if (Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_D))
	{
		faceLeft = false;
		faceRight = true;
		faceUp = false;
		faceDown = false;
		changeState(WALK_RIGHT);
	}
	else if (Engine::GetInstance()->GetInput()->IsKeyReleased(SDL_SCANCODE_D))
	{
		changeState(IDLE);
	}
	
	// KP 1
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_L) && faceLeft == true)
	{
		changeState(ATK_LEFT);
	}
	else if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_L) && faceRight == true)
	{
		changeState(ATK_RIGHT);
	}
	else if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_L) && faceUp == true)
	{
		changeState(ATK_UP);
	}
	else if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_L) && faceDown == true)
	{
		changeState(ATK_DOWN);
	}
	else if (Engine::GetInstance()->GetInput()->IsKeyReleased(SDL_SCANCODE_L))
	{
		changeState(IDLE);
	}

	// If Link picks up a collectable  ////// TODO ///////
	if (isCollecting == true)
	{
		changeState(PICK_OBJECT);
	}
}

/*
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
	// CONTROLS USED FOR LINK
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

	// KP 1
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_KP_1) && currentState == WALK_LEFT)
	{
		changeState(ATK_LEFT);
		if (Engine::GetInstance()->GetInput()->IsKeyReleased(SDL_SCANCODE_KP_1))
		{
			changeState(WALK_LEFT);
		}
	}
	else if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_KP_1) && currentState == WALK_RIGHT)
	{
		changeState(ATK_RIGHT);
		if (Engine::GetInstance()->GetInput()->IsKeyReleased(SDL_SCANCODE_KP_1))
		{
			changeState(WALK_RIGHT);
		}
	}
	else if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_KP_1) && currentState == WALK_UP)
	{
		changeState(ATK_UP);
		if (Engine::GetInstance()->GetInput()->IsKeyReleased(SDL_SCANCODE_KP_1))
		{
			changeState(WALK_UP);
		}
	}
	else
	{
		changeState(ATK_DOWN);
		if (Engine::GetInstance()->GetInput()->IsKeyReleased(SDL_SCANCODE_KP_1))
		{
			changeState(WALK_DOWN);
		}
	}

	// If Link picks up a collectable  ////// TODO ///////
	if (isCollecting == true)
	{
		changeState(PICK_OBJECT);
	}
}
*/