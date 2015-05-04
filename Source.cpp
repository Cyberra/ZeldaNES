
#include "Libraries.h"
#include "ZeldaNES.h"


#define SCREEN_LENGTH 1280
#define SCREEN_HEIGHT 960

int main(int argc, char* args[])
{
	// Initialize the engine
	Engine::GetInstance()->Init(800, 750, RESOLUTION_NTSC);

	ZeldaNES* zeldaNES = new ZeldaNES();

	Engine::GetInstance()->Run();

	delete zeldaNES;

	return 0;
}
