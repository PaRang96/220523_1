#include "World.h"

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
	system("cls");

	for (auto Actor : MyActors)
	{
		Actor->Render();
	}
}

void World::SpawnActor(AActor* NewActor)
{
	MyActors.push_back(NewActor);
}
