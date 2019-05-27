// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Story.h"
#include "StoryBoardComponent.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UStoryBoardComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf<UStory> EntryStoryClass;

public:	
	// Sets default values for this component's properties
	UStoryBoardComponent();

	UFUNCTION(BlueprintCallable)
	void Init();

	void Load();
	void Save();

	UFUNCTION(BlueprintCallable)
	UStory* GetStoryByClass(TSubclassOf<UStory> StoryClass);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY()
	UStory* EntryStory;

};
