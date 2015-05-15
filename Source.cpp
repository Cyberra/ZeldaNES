
#include "Libraries.h"
#include "ZeldaNES.h"
#include "Camera.h"
#include "OpeningScreen.h"

int main(int argc, char* args[])
{
	// Initialize the engine
	 cEngine->Init(SCREEN_LENGTH, SCREEN_HEIGHT);
	//cEngine->Init(800, 750, RESOLUTION_NTSC); 

	OpeningScreen* opS = new OpeningScreen();
	
	//ZeldaNES* zeldaNES = new ZeldaNES();
	

	
	cEngine->Run();

	cEngine->ClearComponents();
	return 0;
}
