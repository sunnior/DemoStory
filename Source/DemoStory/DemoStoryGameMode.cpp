// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "DemoStoryGameMode.h"
#include "DemoStoryCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "SaveGameInterface.h"

ADemoStoryGameMode::ADemoStoryGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/BP_PlayerController"));
	if (PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}

void ADemoStoryGameMode::BeginPlay()
{
	Super::BeginPlay();
	DbgInitGameProgress();
}

void ADemoStoryGameMode::DbgInitGameProgress()
{
	TArray<AActor*> SaveGameObjects;
	UGameplayStatics::GetAllActorsWithInterface(GetWorld(), USaveGameInterface::StaticClass(), SaveGameObjects);
	for (auto& SaveGameObject : SaveGameObjects)
	{
		Cast<ISaveGameInterface>(SaveGameObject)->Execute_BlueprintInitProgress(SaveGameObject);
	}
}