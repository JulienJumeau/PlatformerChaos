// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "DeathBox.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERCHAOS_API UDeathBox : public UBoxComponent
{
	GENERATED_BODY()

public:
	UDeathBox();
	
protected:
	UFUNCTION()
		void OnDeathBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:
	UFUNCTION()
		void ResetLevel();

};
