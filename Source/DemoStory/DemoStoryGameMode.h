// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DemoStoryGameMode.generated.h"

UCLASS(minimalapi)
class ADemoStoryGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ADemoStoryGameMode();

	void BeginPlay() override;

public:
	UFUNCTION(Exec)
	void DbgInitGameProgress();
};



