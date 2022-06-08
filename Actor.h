#pragma once

#include <string>

#include "SpriteType.h"
#include "SDL.h"

using namespace std;

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

	// colour
	int R;
	int G;
	int B;
	int A = 255;

	// sprite size
	int Size = 60;

	// bmp image
	SDL_Surface* Image = nullptr;
	SDL_Texture* Texture = nullptr;
	void LoadBMP(string FileName);

	virtual void Render();
	virtual void Tick();

	static bool Compare(AActor* First, AActor* Second)
	{
		return First->SortOrder < Second->SortOrder;
	}

	bool PredictCollision(int PredictX, int PredictY);
};

