#include <iostream>
#include <fstream>
#include <conio.h>
#include <algorithm>

#include "Engine.h"
#include "Floor.h"
#include "Goal.h"
#include "Wall.h"
#include "Player.h"
#include "Monster.h"
#include "World.h"

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
			case ' ':
				MyWorld->SpawnActor(new AFloor(X, Y, ' ', false, 1));
				break;
			case 'P':
				MyWorld->SpawnActor(new APlayer(X, Y, 'P', true, 5));
				break;
			case 'G':
				MyWorld->SpawnActor(new AGoal(X, Y, 'G', false, 3));
				break;
			case 'M':
				MyWorld->SpawnActor(new AMonster(X, Y, 'M', true, 4));
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
		MyWorld->Render();
	}
}

void Engine::Terminate()
{
	delete MyWorld;
	MyWorld = nullptr;
}

void Engine::Input()
{
	Engine::KeyCode = _getch();
}
