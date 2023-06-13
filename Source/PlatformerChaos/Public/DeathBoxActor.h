// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DeathBoxActor.generated.h"

class UDeathBox;

UCLASS()
class PLATFORMERCHAOS_API ADeathBoxActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADeathBoxActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
		UDeathBox* DeathBox;
};
