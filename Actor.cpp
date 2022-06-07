#include "Actor.h"
#include <Windows.h>
#include <iostream>

using namespace std;

AActor::AActor()
{
	X = 0;
	Y = 0;
	Shape = ' ';
	bCollision = false;
}

AActor::AActor(int newX, int newY, char NewShape, bool bNewCollision)
{
	X = newX;
	Y = newY;
	Shape = NewShape;
	bCollision = bNewCollision;
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
