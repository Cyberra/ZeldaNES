#include "Bomb.h"

// il contient la position de la texture de la bombe et de la fumer
Bomb::Bomb()
:Object()
, bombX()
, bombY()
, width()
, heigth()
, smogX()
, smogY()
, currentTime(1)

{
	bombe = new Sprite(Texture::ID::Bombe, point<int>(192, 64), point<int>(16, 16));
	smog = new Animation(Texture::ID::Smog, SMOG_NB_FRAME(), ANIM_DEFAULT_SPEED, SMOG_NB_POSITION(), FRAME_SIZE());
}

Bomb::~Bomb()
{
}
// ici permet de crée un délais pour utilser la bombe
void Bomb::Update()
{
	
	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();
	currentTime += dt;
	// si le currentTime est plus grand ou égal à  
	if (currentTime >= 1.0f)
	{
		// il entre dans la fonction  show
		Show();
	}
	

}
void Bomb::Show( )
{
	bombX = 820;
	bombY = 954;
	smogX = (float)bombX;
	smogY = (float)bombY;
	// current time est plus grand que  1
	if (currentTime >= 1)
	{
		 //qui soit visible, on créée une bombe et une fumer qui donne 5 de dommage
		Visible = true;
		bombe = new Bomb();
		
		sprite->SetPosition(bombX, bombY);
		smog = new Bomb();
		smog += domage;
		//entre dans la fonction clear
		Clear();
	}
	else
	{   // si current time est plus petit 1 
		currentTime <= 1;
		if (!islooping)
		{   //entre dans la fonction clear
			Clear();
		}
	}
	currentTime = 0;

}
void Bomb::Clear()
{
	//on le mais visible est egal à false
	Visible = false;
	// on deplace bombe et Smog de 1000 par x
	bombX += 1000;
	smogX += 1000;
}
void Bomb::Move()
{
}
bool Bomb::TouchesBomb()
{
	// on crée les v rectangle pour la bombe et la fumer
	bool collect = false;
	inventaire = 1;
	Rectangle* rec1 = new Rectangle((float)box.x, (float)box.y, (float)box.w, (float)box.h);
	Rectangle * rec2 = new Rectangle((float)this->bombX, (float)this->bombY, (float)this->width, (float)this->heigth);
	Rectangle* rec3 = new Rectangle((float)this->smogX, (float)this->smogY, (float)this->width, (float)this->heigth);
	// si c'est un collectable
	if (collect= true)
	{    /// si on entre en collision avec la bombe
		if (rec1->CollidesWith(rec2))
		{// on rajoute une bombe dans l'inventaire
			inventaire + 1;
		}
	}
	else
	{  // colectable est false
		return collect;
	}
	return collect;
}

