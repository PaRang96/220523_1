#include "Wall.h"

AWall::AWall()
	: AActor()
{
}

AWall::AWall(int NewX, int NewY, char NewShape, bool bNewCollision, int NewSortOrder = 2)
	:AActor(NewX, NewY, NewShape, bNewCollision, NewSortOrder)
{
}


AWall::~AWall()
{
}

void AWall::Tick()
{
}
