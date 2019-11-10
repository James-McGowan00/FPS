// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUpBase.generated.h"

class USphereComponent;

UCLASS()
class ASSIGNMENT_1_API APickUpBase : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* SphereComp;
	
public:	
	// Sets default values for this actor's properties
	APickUpBase();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void NotifyActorBeginOverlap(AActor* OtherActor);

	UFUNCTION(BlueprintImplementableEvent, Category = "Pickup")
	void OnActivate(AActor* pickedUpBy);

};
