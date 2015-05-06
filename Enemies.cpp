#include "Enemies.h"

Enemies::Enemies()
{
}

Enemies::Enemies(Texture::ID id, int nbFrame, int frameRate, const point<int>& srcPos, const point<int>& frameSize)
	: Animation(id, nbFrame, frameRate, srcPos, frameSize)
{
}
//: Animation(Texture::ID::LinkAnims, WALK_NB_FRAME(), 0, WALK_DOWN_START_SRC(), FRAME_SIZE())

Enemies::~Enemies()
{
}
