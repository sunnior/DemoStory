// Fill out your copyright notice in the Description page of Project Settings.

#include "StoryBoardComponent.h"
#include "Engine.h"

// Sets default values for this component's properties
UStoryBoardComponent::UStoryBoardComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UStoryBoardComponent::Init()
{
	if (EntryStoryClass)
	{
		EntryStory = NewObject<UStory>(this, EntryStoryClass);
		EntryStory->Init(this);
		EntryStory->Activate();
	}
}

UStory* UStoryBoardComponent::GetStoryByClass(TSubclassOf<UStory> StoryClass)
{
	if (EntryStory)
	{
		return EntryStory->GetStoryByClass(StoryClass);
	}
	return nullptr;
}

// Called when the game starts
void UStoryBoardComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}


// Called every frame
void UStoryBoardComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
#if !(UE_BUILD_SHIPPING)
	if (EntryStory)
	{
		EntryStory->DbgPrintStatus(TEXT("   "));
		if (GEngine)
		{
			FString Msg = GetName() + TEXT(" :");
			GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Yellow, *Msg);
		}
	}
#endif
}

