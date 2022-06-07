#include "Player.h"
#include "Engine.h"

APlayer::APlayer()
	: AActor()
{
}

APlayer::APlayer(int NewX, int NewY, char NewShape, bool bNewCollision, int NewSortOrder = 5)
	: AActor(NewX, NewY, NewShape, bNewCollision, NewSortOrder)
{
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	int KeyCode = Engine::GetKeyCode();

	switch (KeyCode)
	{
	case 'w':
	case 'W':
		Y--;
		break;
	case 's':
	case 'S':
		Y++;
		break;
	case 'a':
	case 'A':
		X--;
		break;
	case 'd':
	case 'D':
		X++;
		break;
	case 27:
		break;
	}
}

