#include "Actor.h"
#include <Windows.h>
#include <iostream>
#include "Engine.h"
#include "World.h"

using namespace std;

AActor::AActor()
{
	X = 0;
	Y = 0;
	Shape = ' ';
	bCollision = false;
	SortOrder = 1;
}

AActor::AActor(int newX, int newY, char NewShape, bool bNewCollision, int NewSortOrder)
{
	X = newX;
	Y = newY;
	Shape = NewShape;
	bCollision = bNewCollision;
	SortOrder = NewSortOrder;
}

AActor::~AActor()
{
}

void AActor::Render()
{
	COORD Pos;
	Pos.X = X;
	Pos.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

	Type = ESpriteType::Wall;

	cout << Shape;
}

void AActor::Tick()
{
}

bool AActor::PredictCollision(int PredictX, int PredictY)
{
	//GEngine->GetWorld()->MyActors;

	for (auto Actor : GEngine->GetWorld()->MyActors)
	{
		if (Actor->X == PredictX && Actor->Y == PredictY && Actor->bCollision)
		{
			return true;
		}
	}

	return false;
}
