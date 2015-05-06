#pragma once
#include "Engine.h"

class Camera
{
public:
	Camera();
	~Camera();

	void Start();
	void Stop();
	void Update();

	void ScrollLeft(int xPos);
	void ScrollRight(int xPos);
	void ResetPosition();

	void SetCameraPosition(int xPos, int yPos);

	SDL_Rect* GetView()	{ return view; }

private:
	SDL_Rect* view;

};