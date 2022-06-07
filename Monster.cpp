#include "Monster.h"

AMonster::AMonster()
	: AActor()
{
}

AMonster::AMonster(int NewX, int NewY, char NewShape, bool bNewCollision, int NewSortOrder = 5)
	: AActor(NewX, NewY, NewShape, bNewCollision, NewSortOrder)
{
}

AMonster::~AMonster()
{
}

void AMonster::Tick()
{
}
