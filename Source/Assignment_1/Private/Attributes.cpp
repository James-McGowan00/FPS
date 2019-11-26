// Fill out your copyright notice in the Description page of Project Settings.


#include "Attributes.h"
// Sets default values for this component's properties
UAttributes::UAttributes()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
	_MaxHealth = 100;
	_CurrentHealth = _MaxHealth;
	_MaxStamina = 600;
	_CurrentStamina = _MaxStamina;

}


// Called when the game starts
void UAttributes::BeginPlay()
{
	Super::BeginPlay();

	// ...

	AActor* Owner = GetOwner();
	if(Owner)
	{
		Owner->OnTakeAnyDamage.AddDynamic(this, &UAttributes::TakeDamage);
	}
	
}


void UAttributes::RecoverStanima(float DeltaTime)
{

}

void UAttributes::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage <= 0)
	{
		return;
	}

	_CurrentHealth = FMath::Clamp(_CurrentHealth - Damage, 0.0f, _MaxHealth);

	
	
}

void UAttributes::RecoverHealth()
{
	_CurrentHealth += 25;

}