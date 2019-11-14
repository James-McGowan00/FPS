// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MyAIController.generated.h"

UCLASS()
class ASSIGNMENT_1_API AMyAIController : public AAIController
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
	virtual void OnPossess(class APawn* InPawn) override;
	
};
