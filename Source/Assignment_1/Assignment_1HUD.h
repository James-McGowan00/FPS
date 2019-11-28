// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Assignment_1HUD.generated.h"

class UMyPlayerStatUIWidget;

UCLASS()
class AAssignment_1HUD : public AHUD
{
	GENERATED_BODY()

public:
	AAssignment_1HUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

	void DrawStats();
	FORCEINLINE UMyPlayerStatUIWidget* GetActiveStatsWidget() const { return _ActiveStatWidget; }

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

	UPROPERTY(EditDefaultsOnly, Category = "Gun Widgets")
	TAssetSubclassOf<UMyPlayerStatUIWidget> _StatWidget;

	UMyPlayerStatUIWidget* _ActiveStatWidget;

};

