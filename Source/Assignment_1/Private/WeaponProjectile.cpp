// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponProjectile.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "Components/ArrowComponent.h"
#include "MyPlayerStatUIWidget.h"
#include "Assignment_1HUD.h"

void AWeaponProjectile::BeginPlay()
{
	Super::BeginPlay();

	_MaxAmmo = 20;
	_CurrentAmmo = _MaxAmmo;

	_Hud = Cast<AAssignment_1HUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
}

// Sets default values
bool AWeaponProjectile::Fire_Implementation()
{
	if (_CurrentAmmo > 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Firing the WeaponProjectile!")));
		UWorld* const World = GetWorld();

		if (World != nullptr && _Projectile != nullptr)
		{
			UArrowComponent* Muzzle = GetGunMuzzle();
			FVector SpawnLocation = ((Muzzle != nullptr) ? Muzzle->GetComponentLocation() : GetActorLocation());
			FRotator SpawnRotation = ((Muzzle != nullptr) ? Muzzle->GetComponentRotation() : GetActorRotation());

			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

			World->SpawnActor<AAssignment_1Projectile>(_Projectile, SpawnLocation, SpawnRotation, ActorSpawnParams);

			_CurrentAmmo -= 1;
			_Hud->GetActiveStatsWidget()->UpdateAmmo(_CurrentAmmo);
		}
		return true;
	}
	else
	{
		return false;
	}
}

void AWeaponProjectile::RecoverAmmo()
{	
	_CurrentAmmo = _MaxAmmo;
	_Hud->GetActiveStatsWidget()->UpdateAmmo(_CurrentAmmo);
}
