#include "Link.h"

Link::Link()
	: Player(Texture::ID::LinkAnims, WALK_NB_FRAME(), 0, WALK_DOWN_START_SRC(), FRAME_SIZE())
	, linkX(820)
	, linkY(954)
	, SPEED(100.0f)
	, attackTimer(0.0f)
	, boomerangPool(nullptr)
	, actualBoomerang(nullptr)
	, actualRoom(nullptr)
{
	SetPosition(linkX, linkY);

	//Start the animation on creation
	this->Play();
	//Make it loop
	this->SetIsLooping(true);

	collider.w = LINK_WIDTH;
	collider.h = LINK_HEIGHT;

	collider.x = (int)linkX;
	collider.y = (int)linkY;
}

Link::~Link()
{
	delete actualRoom;
	delete boomerangPool;
	boomerangPool = nullptr;
	actualRoom = nullptr;
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

point<float> Link::GetNextPos(const Vector2D &direction)
{
	point<float> p;

	p.x = linkX + direction.x;
	p.y = linkY + direction.y;

	return p;
}

void Link::Enter(Level* room)
{
	actualRoom = room;
	room->Show();
	room->SetPlayer(this);
}

void Link::Leave(Level* room)
{
	room->SetPlayer(nullptr);
	room->Hide();
}

// Move and check collision
void Link::Move(TileManager* tm)
{
	Vector2D direction = Vector2D(
		Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_A) && !(Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_S) || Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_W)) ? -1.0f : 0 +
		Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_D) && !(Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_S) || Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_W)) ? 1.0f : 0,
		Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_S) && !(Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_A) || Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_D)) ? 1.0f : 0 +
		Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_W) && !(Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_A) || Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_D)) ? -1.0f : 0);

	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();

	//Move the dot left or right
	linkX += (SPEED * direction.x) * dt;

	/*
		WARNING!!!!!! -> Collision is not totaly working, the wall is not working AT ALL! So you can go wherever you want ! and the object collision is floppy.
	*/

	//If the dot went too far to the left or right or touched a wall
	if (tm->TouchesWall(collider)) //<---This the function to check collision (TouchesWall)
	{
		//move back
		//std::cout << "Aille!!!!" << std::endl;
		linkX -= (SPEED * direction.x) * dt + direction.x;
	}

	//Move the dot up or down
	linkY += (SPEED * direction.y) * dt;

	//If the dot went too far up or down or touched a wall
	if (tm->TouchesWall(collider))
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

	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();

	//////////////////////////////////////////////
	// ANIMATIONS
	//////////////////////////////////////////////

	// W
	if (Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_W))
	{
		FaceUp();
		changeState(WALK_UP);
		isMoving = true;
	}

	// A
	if (Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_A))
	{
		FaceLeft();
		changeState(WALK_LEFT);
		isMoving = true;
	}

	// S
	if (Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_S))
	{
		FaceDown();
		changeState(WALK_DOWN);
		isMoving = true;
	}

	// D
	if (Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_D))
	{
		FaceRight();
		changeState(WALK_RIGHT);
		isMoving = true;
	}

	if		(Engine::GetInstance()->GetInput()->IsKeyReleased(SDL_SCANCODE_D) ||
			 Engine::GetInstance()->GetInput()->IsKeyReleased(SDL_SCANCODE_S) ||
			 Engine::GetInstance()->GetInput()->IsKeyReleased(SDL_SCANCODE_A) ||
			 Engine::GetInstance()->GetInput()->IsKeyReleased(SDL_SCANCODE_W)	)
	{
		isMoving = false;
	}
	
	if (isAttacking)
	{
 		Attack(dt);
	}
	
	// L
	if (Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_L) && facingLeft)
	{
		changeState(ATK_LEFT);
	}
	if (Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_L) && facingRight)
	{
		changeState(ATK_RIGHT);
	}
	if (Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_L) && facingUp)
	{
		changeState(ATK_UP);
	}
	if (Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_L) && facingDown)
	{
		changeState(ATK_DOWN);
	}
	else if (Engine::GetInstance()->GetInput()->IsKeyReleased(SDL_SCANCODE_L))
	{
		isAttacking = true;
	}

	if (!Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_L) && !Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_A) && facingLeft)
	{
		changeState(WALK_LEFT);
		changeState(IDLE);
	}
	if (!Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_L) && !Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_D) && facingRight)
	{
		changeState(WALK_RIGHT);
		changeState(IDLE);
	}
	if (!Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_L) && !Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_W) && facingUp)
	{
		changeState(WALK_UP);
		changeState(IDLE);
	}
	if (!Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_L) && !Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_S) && facingDown)
	{
		changeState(WALK_DOWN);
		changeState(IDLE);
	}

	// If Link picks up a collectable  ////// TODO ///////
	if (isCollecting)
	{
		changeState(PICK_OBJECT);
	}
}
void Link::Attack(float time)
{
	attackTimer += time;
	if (attackTimer > 0.5f)
	{
		isAttacking = false;
		attackTimer = 0;
	}
}
void Link::FaceUp()
{
	facingLeft = false;
	facingRight = false;
	facingUp = true;
	facingDown = false;
}
void Link::FaceDown()
{
	facingLeft = false;
	facingRight = false;
	facingUp = false;
	facingDown = true;
}
void Link::FaceLeft()
{
	facingLeft = true;
	facingRight = false;
	facingUp = false;
	facingDown = false;
}
void Link::FaceRight()
{
	facingLeft = false;
	facingRight = true;
	facingUp = false;
	facingDown = false;
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