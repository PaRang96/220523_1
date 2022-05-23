#pragma once
#include "Actor.h"

class AWall : public AActor
{
public:
	AWall();
	AWall(int NewX, int NewY, char NewShape, bool bNewCollision);
	virtual ~AWall();

	virtual void Tick() override;
};

