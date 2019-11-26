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
}

void UMyPlayerStatUIWidget::UpdateHealthBar(float value)
{
	HealthBar->SetPercent(value);
}

