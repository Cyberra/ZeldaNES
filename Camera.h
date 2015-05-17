#pragma once

#include "Engine.h"

/////////////////////////////////////////////////////////////////////////////////////
//Camera
//The camera is used to represent a part of the game world & to scroll between rooms.
/////////////////////////////////////////////////////////////////////////////////////


class Camera
{
public:
	Camera();
	~Camera();

	void Start();
	void Stop();
	void Update();

	//Scrolls the camera toward one of the 4 possible directions.
	void ScrollLeft(int xPos);
	void ScrollRight(int xPos);
	void ScrollUp(int yPos);
	void ScrollDown(int yPos);

	//Resets/Sets the camera's position
	void ResetPosition();
	void SetCameraPosition(int xPos, int yPos);

	SDL_Rect* GetView()	{ return view; }

private:
	SDL_Rect* view;

};