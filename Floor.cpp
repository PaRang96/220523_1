#include "Floor.h"

AFloor::AFloor()
	: AActor()
{
}

AFloor::AFloor(int NewX, int NewY, char NewShape, bool bNewCollision = false, int NewSortOrder = 1)
	: AActor(NewX, NewY, NewShape, bNewCollision, NewSortOrder)
{
}

AFloor::~AFloor()
{
}

void AFloor::Render()
{
}
