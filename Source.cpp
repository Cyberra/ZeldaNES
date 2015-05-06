
#include "Libraries.h"
#include "ZeldaNES.h"
#include "OpeningScreen.h"

int main(int argc, char* args[])
{
	// Initialize the engine
	Engine::GetInstance()->Init(SCREEN_LENGTH, SCREEN_HEIGHT);


	//OpeningScreen* opS = new OpeningScreen();
	ZeldaNES* zeldaNES = new ZeldaNES();
	
	

	Engine::GetInstance()->Run();

	cEngine->ClearComponents();
	return 0;
}
