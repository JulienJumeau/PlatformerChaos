// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "EndingFlag.generated.h"

class UEndingTrigger;

/**
 * 
 */
UCLASS()
class PLATFORMERCHAOS_API AEndingFlag : public AStaticMeshActor
{
	GENERATED_BODY()
public:

	AEndingFlag();

private:
	UPROPERTY(EditAnywhere)
		UEndingTrigger* EndingTrigger;
};
