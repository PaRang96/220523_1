#include "Actor.h"
#include <Windows.h>
#include <iostream>
#include "Engine.h"
#include "World.h"

using namespace std;

AActor::AActor()
{
	X = 0;
	Y = 0;
	Shape = ' ';
	bCollision = false;
	SortOrder = 1;
}

AActor::AActor(int newX, int newY, char NewShape, bool bNewCollision, int NewSortOrder)
{
	X = newX;
	Y = newY;
	Shape = NewShape;
	bCollision = bNewCollision;
	SortOrder = NewSortOrder;
}

AActor::~AActor()
{
	SDL_FreeSurface(Image);
	SDL_DestroyTexture(Texture);
}

void AActor::LoadBMP(string FileName)
{
	// SSD image file to Memory(RAM)
	Image = SDL_LoadBMP(FileName.c_str());

	// Color Key -> erase the target color from renderer
	SDL_SetColorKey(Image, SDL_TRUE, SDL_MapRGB(Image->format, 255, 0, 255));
	SDL_SetColorKey(Image, SDL_TRUE, SDL_MapRGB(Image->format, 255, 255, 255));

	// Image file from Memory(RAM) to GPU (VRAM)
	Texture = SDL_CreateTextureFromSurface(GEngine->MyRenderer, Image);
}

void AActor::Render()
{
	COORD Pos;
	Pos.X = X;
	Pos.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

	//Type = ESpriteType::Wall;

	cout << Shape;

	if (Texture == nullptr)
	{
		SDL_SetRenderDrawColor(GEngine->MyRenderer, R, G, B, A);
		SDL_RenderFillRect(GEngine->MyRenderer, new SDL_Rect{ X * Size, Y * Size, Size, Size });
	}
	else
	{
		// draw image from GPU to screen
		SDL_RenderCopy(GEngine->MyRenderer, Texture, NULL, new SDL_Rect{ X * Size, Y * Size, Size, Size });
	}
}

void AActor::Tick()
{
}

bool AActor::PredictCollision(int PredictX, int PredictY)
{
	//GEngine->GetWorld()->MyActors;

	for (auto Actor : GEngine->GetWorld()->MyActors)
	{
		if (Actor->X == PredictX && Actor->Y == PredictY && Actor->bCollision)
		{
			return true;
		}
	}

	return false;
}
