// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "EndingTrigger.generated.h"

/**
 *
 */
UCLASS()
class PLATFORMERCHAOS_API UEndingTrigger : public UBoxComponent
{
	GENERATED_BODY()

public:
	UEndingTrigger() = default;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void OnEndingOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:
	UFUNCTION()
		void TriggerEnd();
};
