#include "Floor.h"

AFloor::AFloor()
	: AActor()
{
	R = 255;
	G = 255;
	B = 255;

	LoadBMP("floor.bmp");
}

AFloor::AFloor(int NewX, int NewY, char NewShape, bool bNewCollision = false, int NewSortOrder = 1)
	: AActor(NewX, NewY, NewShape, bNewCollision, NewSortOrder)
{
	R = 255;
	G = 255;
	B = 255;

	LoadBMP("floor.bmp");
}

AFloor::~AFloor()
{
}
