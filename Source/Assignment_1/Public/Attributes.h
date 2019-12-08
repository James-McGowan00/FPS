// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Attributes.generated.h"

class AAssignment_1HUD;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASSIGNMENT_1_API UAttributes : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAttributes();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	
	int GetMaxHealth() { return _MaxHealth; }
	int GetCurrentHealth() { return _CurrentHealth; }

	UFUNCTION(BlueprintCallable)
	void TakeDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	UFUNCTION(BlueprintCallable)
		void RecoverHealth();


	UPROPERTY(BlueprintReadOnly)
		float _CurrentHealth;
private:
	UPROPERTY(EditAnywhere, Category = "Stats")
		float _MaxHealth;

protected:
	UPROPERTY()
		AAssignment_1HUD* _Hud;
};
