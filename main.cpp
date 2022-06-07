#include "Engine.h"
#include "SDL.h"

using namespace std;

int main()
{
	Engine* MyEngine = new Engine;

	//MyEngine->Initialize();
	MyEngine->Load("Level102.map");
	MyEngine->Run();
	//MyEngine->Terminate();

	delete MyEngine;
	MyEngine = nullptr;

	return 0;
}