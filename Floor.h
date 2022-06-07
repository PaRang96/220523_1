#pragma once
#include "Actor.h"

class AFloor : public AActor
{
public:
	AFloor();
	AFloor(int NewX, int NewY, char NewShape, bool bNewCollision, int NewSortOrder);
	virtual	~AFloor();

	void Render() override;
};

