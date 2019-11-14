// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponHitScan.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "Components/ArrowComponent.h"

// Sets default values
bool AWeaponHitScan::Fire_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Firing the hitscan weapon class!")));
	UWorld* const World = GetWorld();

	if (World != nullptr)
	{
		FHitResult hit(ForceInit);
		UArrowComponent* Muzzle = GetGunMuzzle();
		FVector start = ((Muzzle != nullptr) ? Muzzle->GetComponentLocation() : GetActorLocation());
		FVector end = start + (((Muzzle != nullptr) ? Muzzle->GetForwardVector() : GetActorForwardVector()) * 1000);

		const FName TraceTag("MyTraceTag");
		World->DebugDrawTraceTag = TraceTag;
		FCollisionQueryParams CollisionParams;
		CollisionParams.TraceTag = TraceTag;

		if (World->LineTraceSingleByChannel(hit, start, end, ECC_Visibility, CollisionParams))
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, hit.GetActor()->GetActorLabel());
		}

	}
	return true;
}
