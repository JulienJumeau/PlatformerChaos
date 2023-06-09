// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GeometryCollection/GeometryCollectionActor.h"
#include "Field/FieldSystemActor.h"
#include "DestructiblePlatform.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMyEventDelegate);
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

	UFUNCTION()
		void ShakePlatform();

	FTimerHandle MyTimerHandle;
	FTimerHandle ShakeTimerHandle;
	bool MustShake;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom | Chaos Destruction")
		float ChaosDestroyTimer = 2.0f;

	UPROPERTY(BlueprintAssignable, Category = "Custom | Chaos Destruction")
		FMyEventDelegate OnDestructionTimerEnd;

	UPROPERTY(EditDefaultsOnly, Category = "Custom | Chaos Destruction")
		TSubclassOf<AActor> FieldActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom | Shaking")
		float ShakeIntensity = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom | Shaking")
		float ShakeRate = 0.3f;
};
