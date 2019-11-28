 // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Assignment_1Projectile.h"
#include "WeaponBase.h"
#include "WeaponProjectile.generated.h"

UCLASS()
class ASSIGNMENT_1_API AWeaponProjectile : public AWeaponBase
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, Category = "Projectiles")
		TSubclassOf<AAssignment_1Projectile> _Projectile;

public:	
	// Called every frame
	virtual bool Fire_Implementation() override;

};
