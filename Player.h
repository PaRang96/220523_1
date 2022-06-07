#pragma once
#include "Actor.h"

// express oneself on the 2D vector
// check and deal with collision
// deal with keyboard input -> Tick();
class APlayer : public AActor
{
public:
	APlayer();
	APlayer(int NewX, int NewY, char NewShape, bool bNewCollision, int NewSortOrder);
	virtual ~APlayer();

	virtual void Tick() override;
};

