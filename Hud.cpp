#include "Hud.h"
#include "Link.h"
#include "Libraries.h"


Hud::Hud()
{
	
}

//Hud::Hud(Link* link)
//	:Sprite(Texture::HUD::Hud, point<int>(0, 0), point<int>(0, 0))
//	, linkHealth(link->getLinkHealth())
//	, linkMaxHealth(link->getLinkMaxHealth())
//{
//	// All Hud Elements
//	Textures->LoadTexture(Texture::HUD::Hud, "Textures/zelda-hud.png");
//	Textures->LoadTexture(Texture::HUD::RedHeart, "Textures/zelda-hud-redHeart.png");
//	Textures->LoadTexture(Texture::HUD::WhiteHeart, "Textures/zelda-hud-whiteHeart.png");
//	Textures->LoadTexture(Texture::HUD::HalfHeart, "Textures/zelda-hud-halfHeart.png");
//	Textures->LoadTexture(Texture::HUD::Sword, "Textures/zelda-hud-sword.png");
//	Textures->LoadTexture(Texture::HUD::BossMapDot, "Textures/zelda-hud-bossMap.png");
//	Textures->LoadTexture(Texture::HUD::LinkMapDot, "Textures/zelda-hud-linkMap.png");
//}


Hud::~Hud()
{
}

void Hud::Update()
{
	ShowHearts();
}

void Hud::ShowHearts()
{
	// Keeping Link Health up to date
	//linkHealth = link->getLinkHealth();
	//linkMaxHealth = link->getLinkMaxHealth();

	// Show Red Hearts & Half Hearts
	if (linkHealth % 2 == 0)
	{
		for (int i = linkHealth; i > 0; i - 2)
		{
			// Put Red Heart
			// Off set position
		}
	}
	else
	{
		for (int i = linkHealth; i > 1; i - 2)
		{
			// Put Red Heart
			// Off set position
		}
		// Put Half Heart
		// Off set position
	}

	// Show White Hearts
	int healthLost = linkMaxHealth - linkHealth;

	if (healthLost % 2 == 0)
	{
		for (int i = healthLost; i > 0; i - 2)
		{
			// Put White Heart
			// Off set position
		}
	}
}
