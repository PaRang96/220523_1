#include "World.h"
#include <iostream>

using namespace std;


World::World()
{
}

World::~World()
{
	// memory
	for (auto Actor : MyActors)
	{
		delete Actor;
	}
	MyActors.clear();
}

void World::Tick()
{
	// ranged for
	for (auto Actor : MyActors)
	{
		Actor->Tick();
	}
	
	// index
	/*for (int i = 0; i < MyActors.size(); i++)
	{
		MyActors[i]->Tick();
	}*/	

	// container iterator
	/*for (vector<AActor*>::iterator iter = MyActors.begin(); iter != MyActors.end(); iter++)
	{
		(*iter)->Tick();
	}*/
}

void World::Render()
{
	for (auto Actor : MyActors)
	{
		Actor->Render();
	}

	//cout << MyActors.size() << endl;
}

void World::SpawnActor(AActor* NewActor)
{
	MyActors.push_back(NewActor);
}
