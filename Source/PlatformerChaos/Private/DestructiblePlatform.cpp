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
	OnMyEvent.Broadcast();
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Destroyed")));

	//if (GeometryCollectionComponent)haos 
	//{
	//	GeometryCollectionComponent->InitializationFields.Empty();
	//	//GeometryCollectionComponent->ObjectType = EObjectStateTypeEnum::Chaos_Object_Dynamic;
	//	GeometryCollectionComponent->SetDynamicState(Chaos::EObjectStateType::Dynamic);
	//	//GeometryCollectionComponent->
	//}

	//// Assuming you have a reference to the ChaosSolverActor associated with the GeometryCollectionComponent
	//AChaosSolverActor* ChaosSolverActor = GeometryCollectionComponent->ChaosSolverActor;
	//
	////FVector SpawnLocation = FVector(0.0f, 0.0f, 0.0f); // Set the desired spawn location
	////FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f); // Set the desired spawn rotation
	////FTransform SpawnTransform(SpawnRotation, this->GetActorLocation());
	//AActor* SpawnedFieldActor = GetWorld()->SpawnActor<AActor>(FieldActor, this->GetActorTransform());

	//if (ChaosSolverActor)
	//{
	//}
}
