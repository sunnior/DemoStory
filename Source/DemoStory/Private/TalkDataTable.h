// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TalkDataTable.generated.h"

UENUM(BlueprintType)
enum ETalkDataJumpType
{
	OnFinish,
	OnComplete,
	OnReject,
	OnAccept
};

USTRUCT(BlueprintType)
struct FTalkDataJumpRule
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TEnumAsByte<ETalkDataJumpType> JumpType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int JumpIndex;
};

USTRUCT(BlueprintType)
struct FTalkData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText Content;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Time;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bNeedAnswer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<class UStory> AssignStory;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FTalkDataJumpRule> JumpRules;
};

/**
 * 
 */
UCLASS(BlueprintType)
class UTalkDataTable : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FTalkData> TalkList;
	
};
