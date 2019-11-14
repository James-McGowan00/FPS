// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_LocatePlayer.h"
#include "Kismet/GameplayStatics.h"
#include "Assignment_1Character.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTT_LocatePlayer::UBTT_LocatePlayer(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	NodeName = "Locate Player";
	bNotifyTick = true;
	BlackboardKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UBTT_LocatePlayer, BlackboardKey));

}

EBTNodeResult::Type UBTT_LocatePlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAssignment_1Character* player = Cast<AAssignment_1Character>(UGameplayStatics::GetPlayerCharacter(this, 0));
	OwnerComp.GetBlackboardComponent()->SetValueAsVector(BlackboardKey.SelectedKeyName, player->GetActorLocation());
	return EBTNodeResult::Succeeded;
}

FString UBTT_LocatePlayer::GetStaticDescription() const
{
	FString KeyDesc("invalid");
		if (BlackboardKey.SelectedKeyType == UBlackboardKeyType_Vector::StaticClass())
		{
			KeyDesc = BlackboardKey.SelectedKeyName.ToString();
		}

		return FString::Printf(TEXT("%s: %s"), *Super::GetStaticDescription(), *KeyDesc);
}
