// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Story.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class UStory : public UObject
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStoryBoardComponent* StoryBoard;
public:
	void Init(class UStoryBoardComponent* InStoryBoard);
	UFUNCTION(BlueprintImplementableEvent)
	void BlueprintInit();

	void Activate();
	UFUNCTION(BlueprintImplementableEvent)
	void BlueprintActivate();

	UFUNCTION(BlueprintCallable)
	void AddSubStory(UStory* SubStory);

	UFUNCTION(BlueprintCallable)
	void StartSubStory(UStory* SubStory);

	UFUNCTION(BlueprintCallable)
	void RemoveFromParent();

	void RemoveSubStory(UStory* SubStory);

	UFUNCTION(BlueprintCallable)
	UStory* GetStoryByClass(TSubclassOf<UStory> StoryClass);

private:
	UPROPERTY()
	TArray<UStory*> SubStories;

	UStory* Parent;

public:
	void DbgPrintStatus(const FString& Prefix);

	UFUNCTION(BlueprintImplementableEvent)
	void BlueprintDbgStatus();
};
