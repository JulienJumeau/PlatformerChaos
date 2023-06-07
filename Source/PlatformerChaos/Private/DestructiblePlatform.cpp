// Fill out your copyright notice in the Description page of Project Settings.


#include "DestructiblePlatform.h"
#include "../PlatformerChaosCharacter.h" // Include the header file of ACharacter
#include "GeometryCollection/GeometryCollectionComponent.h" 

void ADestructiblePlatform::BeginPlay()
{
	Super::BeginPlay();
	GeometryCollectionComponent->OnComponentHit.AddDynamic(this, &ADestructiblePlatform::OnComponentHit);
}

void ADestructiblePlatform::OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (!OtherActor || !OtherActor->IsA(APlatformerChaosCharacter::StaticClass()))
	{
		return;
	}

	FVector characterLocation = OtherActor->GetActorLocation();
	FVector characterUp = Cast<APlatformerChaosCharacter>(OtherActor)->GetActorUpVector();

	FVector Direction = (Hit.ImpactPoint - characterLocation).GetSafeNormal();
	float DotProduct = FVector::DotProduct(Direction, characterUp);

	if (DotProduct < -0.5f)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Hit From above")));
		GetWorldTimerManager().SetTimer(MyTimerHandle, this, &ADestructiblePlatform::ChaosDestroy, ChaosDestroyTimer, false);
		GeometryCollectionComponent->OnComponentHit.RemoveDynamic(this, &ADestructiblePlatform::OnComponentHit);
	}
}

void ADestructiblePlatform::ChaosDestroy()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Destroyed")));
}
