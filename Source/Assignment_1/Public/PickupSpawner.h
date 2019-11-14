// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUpBase.h"
#include "PickupSpawner.generated.h"

UCLASS()
class ASSIGNMENT_1_API APickupSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UPROPERTY(EditAnywhere, Category = "Pickups")
		TMap<TSubclassOf<APickUpBase>, float> _Pickups;

	UPROPERTY(EditAnywhere, Category = "Pickups")
		float _SpawnDelay;

	float _TotalSpawnRatio;
	APickUpBase* _CurrentPickUP;

	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* _BaseMesh;

	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* _SpawnLocation;

	UPROPERTY(VisibleDefaultsOnly)
		class UBoxComponent* _BoxCollision;

	UPROPERTY(VisibleDefaultsOnly)
		class URotatingMovementComponent* _RotatingMove;

	UPROPERTY(VisibleDefaultsOnly)
		class UInterpToMovementComponent* _InterpMove;

	UFUNCTION()
		void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void SpawnPickup();


};
