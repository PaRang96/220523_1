#pragma once

// express oneself on the 2D vector
// check and deal with collision
class AActor
{
public:
	AActor();
	AActor(int NewX, int NewY, char NewShape, bool bNewCollision = false);
	virtual	~AActor();
	char Shape;

	int X;
	int Y;

	bool bCollision;

	virtual void Render();
	virtual void Tick();
};

