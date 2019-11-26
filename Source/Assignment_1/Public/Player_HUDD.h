// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyPlayerStatUIWidget.h"
#include "Assignment_1HUD.h"
#include "Player_HUDD.generated.h"

class UMyPlayerStatUIWidget;

UCLASS()
class ASSIGNMENT_1_API APlayer_HUDD : public AAssignment_1HUD
{
	GENERATED_BODY()


public:
	APlayer_HUDD();

	virtual void DrawHUD() override;

	void DrawStats();
	FORCEINLINE UMyPlayerStatUIWidget* GetActiveStatsWidget() const { return _ActiveStatWidget; }

private:

	class UTexture2D* CrosshairTex;

	UPROPERTY(EditDefaultsOnly, Category = "Gun Widgets")
	TAssetSubclassOf<UMyPlayerStatUIWidget> _StatWidget;

	UMyPlayerStatUIWidget* _ActiveStatWidget;
};
