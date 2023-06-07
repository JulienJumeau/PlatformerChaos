// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GeometryCollection/GeometryCollectionActor.h"
#include "DestructiblePlatform.generated.h"

/**
 *
 */
UCLASS()
class PLATFORMERCHAOS_API ADestructiblePlatform : public AGeometryCollectionActor
{
	GENERATED_BODY()

public:
	ADestructiblePlatform() = default;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
		void ChaosDestroy();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom | Chaos Destruction")
		float ChaosDestroyTimer = 2.0f;

	FTimerHandle MyTimerHandle;
};
