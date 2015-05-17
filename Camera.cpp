#include "Camera.h"

const float LEFT_SCROLLING = 45 / 100.0f;
const float RIGHT_SCROLLING = 55 / 100.0f;
const float UP_SCROLLING = 50 / 100.0f;
const float DOWN_SCROLLING = 50 / 100.0f;

const point<int> DEFAULT_RESOLUTION = RESOLUTION_NTSC;

Camera::Camera()
{
	view = new SDL_Rect();
	view->x = 0;
	view->y = 0;
	view->w = DEFAULT_RESOLUTION.x;
	view->h = DEFAULT_RESOLUTION.y;
}

Camera::~Camera()
{
	delete(view);
	view = nullptr;

}

void Camera::Start()
{
}

void Camera::Stop()
{
}

void Camera::Update()
{


}

void Camera::SetCameraPosition(int x, int y)
{
	view->x = x;
	view->y = y;
}

void Camera::ScrollLeft(int xPos)
{
	SetCameraPosition((int)(xPos - view->w * LEFT_SCROLLING), view->y);
}

void Camera::ScrollRight(int xPos)
{
	SetCameraPosition((int)(xPos - view->w * RIGHT_SCROLLING), view->y);
}

void Camera::ScrollUp(int yPos)
{
	SetCameraPosition((int)(yPos - view->w * RIGHT_SCROLLING), view->y);
}

void Camera::ScrollDown(int yPos)
{
	SetCameraPosition((int)(yPos - view->w * RIGHT_SCROLLING), view->y);
}

void Camera::ResetPosition()
{
	view->x = 0;
	view->y = 0;
}