#include "Goal.h"

AGoal::AGoal()
	: AActor()
{
	R = 255;
	G = 255;
	B = 0;
	LoadBMP("coin.bmp");
}

AGoal::AGoal(int NewX, int NewY, char NewShape, bool bNewCollision, int NewSortOrder = 3)
	: AActor(NewX, NewY, NewShape, bNewCollision, NewSortOrder)
{
	R = 255;
	G = 255;
	B = 0;
	LoadBMP("coin.bmp");
}

AGoal::~AGoal()
{
}

void AGoal::Tick()
{
}
