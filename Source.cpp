
#include "Libraries.h"
#include "ZeldaNES.h"


#define SCREEN_LENGTH 2000
#define SCREEN_HEIGHT 1000

int main(int argc, char* args[])
{
	// Initialize the engine
	Engine::GetInstance()->Init(SCREEN_LENGTH, SCREEN_HEIGHT);

	ZeldaNES* zeldaNES = new ZeldaNES();

	Engine::GetInstance()->Run();

	delete zeldaNES;

	return 0;
}
