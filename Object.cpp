#include "Object.h"

Object::Object()
	: Animation()
{
}

Object::Object(Texture::ID id, int nbFrame, int animSpeed, point<int> src, point<int> size)
	: Animation(id, nbFrame, animSpeed, src, size)
{
}

Object::~Object()
{
}