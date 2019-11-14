// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponProjectile.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "Components/ArrowComponent.h"

// Sets default values
bool AWeaponProjectile::Fire_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Firing the hitscan weapon class!")));
	UWorld* const World = GetWorld();

	if (World != nullptr && _Projectile != nullptr)
	{
		UArrowComponent* Muzzle = GetGunMuzzle();
		FVector SpawnLocation = ((Muzzle != nullptr) ? Muzzle->GetComponentLocation() : GetActorLocation());
		FRotator SpawnRotation = ((Muzzle != nullptr) ? Muzzle->GetComponentRotation() : GetActorRotation());

		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

		World->SpawnActor<AAssignment_1Projectile>(_Projectile, SpawnLocation, SpawnRotation, ActorSpawnParams);
	}
	return true;
}
