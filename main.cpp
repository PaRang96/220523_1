#include "Engine.h"
#include "SDL.h"

#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")

using namespace std;

//int main()
//{
//	Engine* MyEngine = new Engine;
//
//	//MyEngine->Initialize();
//	MyEngine->Load("Level102.map");
//	MyEngine->Run();
//	//MyEngine->Terminate();
//
//	delete MyEngine;
//	MyEngine = nullptr;
//
//	return 0;
//}

int SDL_main(int argc, char* argv[])
{
	// initializing hardware
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_Log("SDL_INIT_ERROR");
		return -1;
	}

	// create window
	SDL_Window* MyWindow = SDL_CreateWindow("Maze", 100, 100, 800, 600, SDL_WINDOW_OPENGL);
	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);


	SDL_Event MyEvent;

	bool bRunning = true;

	int X = 0;

	while (bRunning)
	{
		SDL_PollEvent(&MyEvent);

		switch (MyEvent.type)
		{
		case SDL_QUIT:
			bRunning = false;
			break;
		case SDL_KEYDOWN:
			SDL_Log("Press Key");
			break;
		}

		// tasks for gpu
		SDL_SetRenderDrawColor(MyRenderer, 0xff, 0x00, 0x00, 0xff);
		SDL_RenderClear(MyRenderer);

		// draw rect
		SDL_SetRenderDrawColor(MyRenderer, 0xff, 0xff, 0x00, 0xff);
		
		if (X > 300)
		{
			X = X - 100;
		}
		else
		{
			X++;
		}
		SDL_RenderFillRect(MyRenderer, new SDL_Rect{ X,1,100,100 });


		// start tasks
		SDL_RenderPresent(MyRenderer);
	}

	SDL_DestroyRenderer(MyRenderer);

	SDL_DestroyWindow(MyWindow);

	SDL_Quit();

	return 0;
}