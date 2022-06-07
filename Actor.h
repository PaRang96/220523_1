#pragma once
#include "SpriteType.h"
// express oneself on the 2D vector
// check and deal with collision
class AActor
{
public:
	AActor();
	AActor(int NewX, int NewY, char NewShape, bool bNewCollision = false, int NewSortOrder = 1);
	virtual	~AActor();
	char Shape;

	ESpriteType Type;

	int X;
	int Y;

	bool bCollision;

	int SortOrder;

	virtual void Render();
	virtual void Tick();

	static bool Compare(AActor* First, AActor* Second)
	{
		return First->SortOrder < Second->SortOrder;
	}

	bool PredictCollision(int PredictX, int PredictY);
};

