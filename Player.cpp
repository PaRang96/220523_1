#include "Player.h"
#include "Engine.h"
#include "World.h"
#include "Goal.h"

APlayer::APlayer()
	: AActor()
{
}

APlayer::APlayer(int NewX, int NewY, char NewShape, bool bNewCollision, int NewSortOrder = 4)
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
		Y = (PredictCollision(X, Y - 1) == false) ? Y - 1 : Y;
		break;
	case 's':
	case 'S':
		Y = (PredictCollision(X, Y + 1) == false) ? Y + 1 : Y;
		break;
	case 'a':
	case 'A':
		X = (PredictCollision(X - 1, Y) == false) ? X - 1 : X;
		break;
	case 'd':
	case 'D':
		X = (PredictCollision(X + 1, Y) == false) ? X + 1 : X;
		break;
	}

	if (IsGoal())
	{
		GEngine->QuitGame();
	}
}

bool APlayer::IsGoal()
{
	for (auto Actor : GEngine->GetWorld()->MyActors)
	{
		if (Actor->X == X && Actor->Y == Y)
		{
			AGoal* Goal = dynamic_cast<AGoal*>(Actor);
			if (Goal != nullptr)
			{
				return true;
			}
		}
	}
	
	return false;
}

