#include "Libraries.h"
#include "ZeldaNES.h"
#include "Camera.h"
#include "TitleScreen.h"

int main(int argc, char* args[])
{
	// Initializes the engine
	 cEngine->Init(SCREEN_LENGTH, SCREEN_HEIGHT);
	//cEngine->Init(800, 750, RESOLUTION_NTSC); 
	
	ZeldaNES* zeldaNES = new ZeldaNES();
	

	
	cEngine->Run();

	cEngine->ClearComponents();
	return 0;
}
