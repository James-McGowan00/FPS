// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponProjectile.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "Components/ArrowComponent.h"

// Sets default values
bool AWeaponProjectile::Fire_Implementation()
{
	_MaxAmmo = 100;
	_CurrentAmmo = _MaxAmmo;

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
	}
	return true;

}

void AWeaponProjectile::BeginPlay()
{
	Super::BeginPlay();


	//_Hud = Cast<AAssignment_1HUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
}

void AWeaponProjectile::Shoot()
{
	if (Fire)
	{
		_CurrentAmmo--;
	}
}

void AWeaponProjectile::RecoverAmmo()
{
	if (_CurrentAmmo < 100)
	{
		_CurrentAmmo = _CurrentAmmo + 10;

		//_Hud->GetActiveStatsWidget()->UpdateHealthBar(_CurrentHealth / _MaxHealth);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Ammo Full")));
	}

	if (_CurrentAmmo > _MaxAmmo)
	{
		_CurrentAmmo = _MaxAmmo;
	}
}
