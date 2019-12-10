// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Assignment_1Character.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerStart.h"

#include "ExampleGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT_1_API AExampleGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AExampleGameMode();
	void LoadNextLevel();

private:
	void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Levels")
		TArray<FString> Levels;

	FString NextLevel;
	int32 CurrentLevelIndex;

	void CheckLevel();

	APlayerController* Controller;
	APawn* Player;
	TArray<AActor> PlayerStartArray;
};
