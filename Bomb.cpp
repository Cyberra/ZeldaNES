#include "Bomb.h"


Bomb::Bomb()
:Sprite(Texture::ID::Bombe, point<int>(192, 64), point<int>(16, 16))
,Objects(Texture::ID::Smog, SMOG_NB_FRAME(), ANIM_DEFAULT_SPEED, SMOG_NB_POSITION(), FRAME_SIZE())
, bombX(820)
, bombY(954)
, width()
, heigth()
, SmogX()
, SmogY()
, currentTime(1)
, isPlaying(false)
, islooping(false)
{
	Visible = false;
	this->Play();
	this->SetIsLooping(true);
}
Bomb::~Bomb()
{
}
void Bomb::Update()
{
	
	
	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();
	currentTime += dt;
	if (currentTime >= 1.0f)
	{
		Show();
	}

}
void Bomb::Show()
{
	if (currentTime > 1)
	{
		Visible = true;
		Smog = new Bomb();
		Smog += domage;
		Clear();
	}
	else
	{
		currentTime = 0;
		if (!islooping)
		{
			Clear();
		}
	}
	currentTime = 0;

}
void Bomb::Clear()
{
	Visible = false;
}
void Bomb::Move()
{
}
bool Bomb::TouchesBomb()
{
	bool collect = false;
	Rectangle* rec1 = new Rectangle(box.x, box.y, box.w, box.h);
	Rectangle * rec2 = new Rectangle(this->bombX, this->bombY, this->width, this->heigth);
	Rectangle* rec3 = new Rectangle(this->SmogX, this->SmogY, this->width, this->heigth);

	if (collect= true)
	{
		if (rec1->CollidesWith(rec2))
		{
			std::cout << "BOMBE" << std::endl;
			
		}
	}
	else
	{
		if (rec1->CollidesWith(rec3))
		{
			Update();
		}
		
	}
	
	return collect;
}

