// Fill out your copyright notice in the Description page of Project Settings.


#include "Attributes.h"
#include "Kismet/GameplayStatics.h"
#include "MyPlayerStatUIWidget.h"
#include "Assignment_1HUD.h"
#include "Engine/Engine.h"

// Sets default values for this component's properties
UAttributes::UAttributes()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
	_MaxHealth = 100;
	_CurrentHealth = _MaxHealth;
	_MaxStamina = 100;
	_CurrentStamina = _MaxStamina;

}


// Called when the game starts
void UAttributes::BeginPlay()
{
	Super::BeginPlay();


	_Hud = Cast<AAssignment_1HUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());

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

	_Hud->GetActiveStatsWidget()->UpdateHealthBar(_CurrentHealth / _MaxHealth);
}

void UAttributes::RecoverHealth()
{
	if (_CurrentHealth < 100)
	{
		_CurrentHealth = _CurrentHealth + 15;

		_Hud->GetActiveStatsWidget()->UpdateHealthBar(_CurrentHealth / _MaxHealth);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Health Full")));
	}
	
	if (_CurrentHealth > _MaxHealth)
	{
		_CurrentHealth = _MaxHealth;
	}

}