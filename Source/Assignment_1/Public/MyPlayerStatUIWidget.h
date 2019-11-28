// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseWidget.h"
#include "MyPlayerStatUIWidget.generated.h"

class UProgressBar;
class UTextBlock;

UCLASS(Abstract)
class ASSIGNMENT_1_API UMyPlayerStatUIWidget : public UBaseWidget
{
	GENERATED_BODY()
		
private:
	UPROPERTY(meta = (BindWidget))
		UProgressBar* HealthBar;

	UPROPERTY(meta = (BindWidget))
		UProgressBar* StaminaBar;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* Ammo;
public:
	virtual void NativeConstruct() override;
	void UpdateHealthBar(float value);
	void UpdateStaminaBar(float value);
	void UpdateAmmo(int value);
};
