// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Fireable.h"
#include "WeaponBase.generated.h"

UCLASS()
class ASSIGNMENT_1_API AWeaponBase : public AActor, public IFireable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponBase();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		bool Fire();
	virtual bool Fire_Implementation() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Root;

	UPROPERTY(VisibleDefaultsOnly)
		class USkeletalMeshComponent* GunMesh;

	UPROPERTY(VisibleDefaultsOnly)
		class UArrowComponent* GunMuzzle;

public:
	FORCEINLINE class UArrowComponent* GetGunMuzzle() const {return GunMuzzle;}

};
