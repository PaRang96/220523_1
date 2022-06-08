#include "Monster.h"

AMonster::AMonster()
	: AActor()
{
	R = 0;
	G = 255;
	B = 255;
	LoadBMP("slime.bmp");
}

AMonster::AMonster(int NewX, int NewY, char NewShape, bool bNewCollision, int NewSortOrder = 5)
	: AActor(NewX, NewY, NewShape, bNewCollision, NewSortOrder)
{
	R = 0;
	G = 255;
	B = 255;
	LoadBMP("slime.bmp");
}

AMonster::~AMonster()
{
}

void AMonster::Tick()
{
}
