#include "Wall.h"

AWall::AWall()
	: AActor()
{
	R = 0;
	G = 255;
	B = 0;
	LoadBMP("wall.bmp");
}

AWall::AWall(int NewX, int NewY, char NewShape, bool bNewCollision, int NewSortOrder = 2)
	:AActor(NewX, NewY, NewShape, bNewCollision, NewSortOrder)
{
	R = 0;
	G = 255;
	B = 0;
	LoadBMP("wall.bmp");
}


AWall::~AWall()
{
}

void AWall::Tick()
{
}
