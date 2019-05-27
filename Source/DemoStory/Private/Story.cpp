// Fill out your copyright notice in the Description page of Project Settings.

#include "Story.h"
#include "Engine.h"

void UStory::Init(UStoryBoardComponent* InStoryBoard)
{
	StoryBoard = InStoryBoard;

	BlueprintInit();

	for (auto& SubStory : SubStories)
	{
		SubStory->Init(StoryBoard);
	}
}

void UStory::Activate()
{
	BlueprintActivate();

	for (auto& SubStory : SubStories)
	{
		SubStory->Activate();
	}
}

void UStory::AddSubStory(UStory* SubStory)
{
	SubStory->Parent = this;
	SubStories.Add(SubStory);
}

void UStory::StartSubStory(UStory* SubStory)
{
	AddSubStory(SubStory);
	SubStory->Init(StoryBoard);
	SubStory->Activate();
}

void UStory::RemoveFromParent()
{
	Parent->RemoveSubStory(this);
}

void UStory::RemoveSubStory(UStory* SubStory)
{
	SubStories.Remove(SubStory);
}

UStory* UStory::GetStoryByClass(TSubclassOf<UStory> StoryClass)
{
	if (this->GetClass() == StoryClass)
	{
		return this;
	}
	for (auto& SubStory : SubStories)
	{
		UStory* RetStory = SubStory->GetStoryByClass(StoryClass);
		if (RetStory)
		{
			return RetStory;
		}
	}
	return nullptr;
}

void UStory::DbgPrintStatus(const FString& Prefix)
{
	FString SubPrefix = Prefix + TEXT("  ");
	for (auto& SubStory : SubStories)
	{
		SubStory->DbgPrintStatus(SubPrefix);
	}
	BlueprintDbgStatus();
	if (GEngine)
	{
		FString Msg = Prefix + GetName();
		GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Yellow, *Msg);
	}
}
