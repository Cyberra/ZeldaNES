#include "Link.h"

Link::Link()
	: Animation(Texture::ID::LinkAnims, WALK_NB_FRAME(), 0, WALK_DOWN_START_SRC(), FRAME_SIZE())

	, linkMaxHealth(6) // Starting Health is 3 hearts that can be taken down to a half each (3x2=6)
	, linkHealth(linkMaxHealth)
	, SPEED(100.0f)
	, attackTimer(0.0f)
	, boomerangPool(nullptr)
	, boomerang(nullptr)
	, currentRoom(nullptr)
{
	xPos = 820;
	yPos = 954;
	SetPosition((int)xPos, (int)yPos);

	//Start the animation on creation
	this->Play();
	//Make it loop
	this->SetIsLooping(true);

	collider.w = LINK_WIDTH;
	collider.h = LINK_HEIGHT;

	collider.x = (int)xPos + LINK_WIDTH / 2;
	collider.y = (int)yPos + LINK_HEIGHT / 2;
}

Link::~Link()
{
	boomerangPool = nullptr;
	currentRoom = nullptr;
}

// Get link current position
point<int> const Link::GetCurrentPos()
{
	point<int> myPosition((int)this->xPos, (int)this->yPos);
	return myPosition;
}


void Link::changeState(state newState)
{
	//////////////////////////////////////////////
	// INSERT CASES FOR EACH ANIMATION DOWN HERE
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

// Get link next position...Mainly for collision purpose
point<int> const Link::GetNextPos(const Vector2D &direction)
{
	point<int> p;

	p.x = (int)(xPos + direction.x);
	p.y = (int)(yPos + direction.y);

	return p;
}
// // Function to make link enter the room 
void Link::Enter(Level* room)
{
	currentRoom = room;
	room->SetActive(true);
	room->SetPlayer(this);
}

// Function to make link leave the room 
void Link::Leave(Level* room)
{
	room->SetPlayer(nullptr);
	room->SetActive(false);
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

	MoveBox(direction);

	//Move link left or right
	xPos += (SPEED * direction.x) * dt;

	//If link went too far to the left or right or touched a wall
	if (tm->TouchesWall(collider)) //<---This the function to check collision (TouchesWall)
	{
		//move back
		xPos -= (SPEED * direction.x) * dt;
	}

	//Move the link up or down
	yPos += (SPEED * direction.y) * dt;

	//If link went too far up or down or touched a wall
	if (tm->TouchesWall(collider))
	{
		//move back
		yPos -= (SPEED * direction.y) * dt;
	}
	SetPosition((int)xPos, (int)yPos);
}

// Move the collider
void Link::MoveBox(const Vector2D &direction)
{
	collider.x = GetNextPos(direction).x;
	collider.y = GetNextPos(direction).y;
}

// Update Everything for link!!!!!!!
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

	if (Engine::GetInstance()->GetInput()->IsKeyReleased(SDL_SCANCODE_D) ||
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