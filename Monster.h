#pragma once
#include "Actor.h"

class AMonster :
    public AActor
{
public:
    AMonster();
    AMonster(int NewX, int NewY, char NewShape, bool bNewCollision, int NewSortOrder);
    virtual ~AMonster();

    virtual void Tick() override;
};

