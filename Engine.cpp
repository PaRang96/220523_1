#include <iostream>
#include <fstream>
#include <conio.h>
#include <algorithm>

#include "Actor.h"
#include "Engine.h"
#include "Floor.h"
#include "Goal.h"
#include "Wall.h"
#include "Player.h"
#include "Monster.h"
#include "World.h"

#include "SDL.h"

#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")


using namespace std;

int Engine::KeyCode = 0;
Engine* Engine::Instance = nullptr;

Engine::Engine()
{
	Instance = this;
	Initialize();
}

Engine::~Engine()
{
	Terminate();
}

void Engine::Initialize()
{
	MyWorld = new World;
	bRunning = true;

	// initializing hardware
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		SDL_Log("SDL_INIT_ERROR");
	}

	// create window
	MyWindow = SDL_CreateWindow("Maze", 100, 100, 800, 600, SDL_WINDOW_VULKAN);
	MyRenderer = SDL_CreateRenderer(MyWindow, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
}

void Engine::Load(string MapFilename)
{
	//Load
	ifstream MapFile(MapFilename);

	int Y = 0;
	while (MapFile.peek() != EOF)
	{
		char Buffer[1024] = { 0, };
		MapFile.getline(Buffer, 1024);

		// line by line
		for (size_t X = 0; X < strlen(Buffer); ++X)
		{
			char Cursor = Buffer[X];
			switch (Cursor)
			{
			case '#':
				MyWorld->SpawnActor(new AWall(X, Y, '#', true, 2));
				break;
			//case ' ':
			//	MyWorld->SpawnActor(new AFloor(X, Y, ' ', false, 1));
			//	break;
			case 'P':
				MyWorld->SpawnActor(new APlayer(X, Y, 'P', true, 4));
				break;
			case 'G':
				MyWorld->SpawnActor(new AGoal(X, Y, 'G', false, 3));
				break;
			case 'M':
				MyWorld->SpawnActor(new AMonster(X, Y, 'M', false, 5));
				break;
			}

			MyWorld->SpawnActor(new AFloor(X, Y, ' ', false, 1));
		}
		
		Y++;
	}

	// Rendering Order
	sort(MyWorld->MyActors.begin(), MyWorld->MyActors.end(), AActor::Compare);

	MapFile.close();
}

void Engine::Run()
{
	while (bRunning) // per 1 frame
	{
		Input();
		MyWorld->Tick();

		// tasks for gpu
		SDL_SetRenderDrawColor(MyRenderer, 0xff, 0x00, 0x00, 0xff);
		SDL_RenderClear(MyRenderer);

		MyWorld->Render();

		// draw rect
		//SDL_SetRenderDrawColor(MyRenderer, 0xff, 0xff, 0x00, 0xff);

		// start tasks
		SDL_RenderPresent(MyRenderer);
	}
}

void Engine::Terminate()
{
	delete MyWorld;
	MyWorld = nullptr;

	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);
	SDL_Quit();
}

void Engine::Input()
{
	//Engine::KeyCode = _getch();
	SDL_PollEvent(&MyEvent);
}
