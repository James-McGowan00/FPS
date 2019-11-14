// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponBase.h"
#include "WeaponHitScan.generated.h"

UCLASS()
class ASSIGNMENT_1_API AWeaponHitScan : public AWeaponBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	virtual bool Fire_Implementation() override;


};
