// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerStatUIWidget.h"
#include "Components/ProgressBar.h"

void UMyPlayerStatUIWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (HealthBar)
	{
		HealthBar->SetPercent(1); 
	}

	if (StaminaBar)
	{
		StaminaBar->SetPercent(1);
	}

}

void UMyPlayerStatUIWidget::UpdateHealthBar(float value)
{
	HealthBar->SetPercent(value);
}

void UMyPlayerStatUIWidget::UpdateStaminaBar(float value)
{
	StaminaBar->SetPercent(value);
}

void UMyPlayerStatUIWidget::UpdateAmmo(int value)
{
	Ammo;
}
