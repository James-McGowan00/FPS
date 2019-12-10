// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBase.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "Engine/Engine.h"

// Sets default values
AWeaponBase::AWeaponBase()
{
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneComponent"));
	RootComponent = Root;

	GunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun"));
	GunMesh->SetupAttachment(Root);

	GunMuzzle = CreateDefaultSubobject<UArrowComponent>(TEXT("GunMuzzle"));
	GunMuzzle->SetupAttachment(GunMesh);
}

// Called when the game starts or when spawned
void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}

bool AWeaponBase::Fire_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Firing the weapon base class")));
	return true;
}
