// Fill out your copyright notice in the Description page of Project Settings.

#include "ExampleGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "Assignment_1Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"


AExampleGameMode::AExampleGameMode()
{
	CurrentLevelIndex = 0;
	static ConstructorHelpers::FClassFinder<APawn> CharacterFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = CharacterFinder.Class;
}

void AExampleGameMode::BeginPlay()
{
	Super::BeginPlay();


	Controller = UGameplayStatics::GetPlayerController(this, 0);
	FInputModeGameOnly InputMode;
	Controller->SetInputMode(InputMode);
	Controller->bShowMouseCursor = false;

	CheckLevel();
}


void AExampleGameMode::CheckLevel()
{
	FString CurrentLevelName = GetWorld()->GetMapName();

	Levels.Find(CurrentLevelName, CurrentLevelIndex);

	if (CurrentLevelIndex < Levels.Num() - 1)
	{
		NextLevel = Levels[CurrentLevelIndex + 1];
	}
	else
	{
		NextLevel = CurrentLevelName;
		UE_LOG(LogTemp, Warning, TEXT("Reached the end of the level array"));
	}
}

void AExampleGameMode::LoadNextLevel()
{
	if (Levels.Contains(NextLevel))
	{
		FName LevelToLoad = FName(*NextLevel);
		UGameplayStatics::OpenLevel(this, LevelToLoad, true);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("For some reason the value of NextLevel is not in the Levels array!"))
	}
}

