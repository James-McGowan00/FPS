// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerStatUIWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UMyPlayerStatUIWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (HealthBar)
	{
		HealthBar->SetPercent(1); 
	}
}

void UMyPlayerStatUIWidget::UpdateHealthBar(float value)
{
	HealthBar->SetPercent(value);
}


void UMyPlayerStatUIWidget::UpdateAmmo(int value)
{
	FString text = FString::FromInt(value);
	FText bullet = FText::FromString(text);
	Ammo->SetText(bullet);
}
