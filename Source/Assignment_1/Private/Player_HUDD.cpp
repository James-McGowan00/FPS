// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_HUDD.h"

void APlayer_HUDD::DrawStats()
{
	_ActiveStatWidget = CreateWidget<UMyPlayerStatUIWidget>(GetOwningPlayerController(), _StatWidget.LoadSynchronous());

	if (_ActiveStatWidget != nullptr)
	{
		_ActiveStatWidget->AddToViewport(0);
	}
}