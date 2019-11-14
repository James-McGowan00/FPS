// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "AICharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"

void AMyAIController::BeginPlay()
{
	Super::BeginPlay();
}

void AMyAIController::OnPossess(class APawn* InPawn)
{
	Super::OnPossess(InPawn);

	AAICharacter* AI = Cast<AAICharacter>(InPawn);

	if (AI)
	{
		RunBehaviorTree(AI->_behaviourTree);
	}
}

