// Fill out your copyright notice in the Description page of Project Settings.


#include "EndingTrigger.h"
#include <Kismet/GameplayStatics.h>
#include "../PlatformerChaosCharacter.h" // Include the header file of ACharacter


void UEndingTrigger::BeginPlay()
{
	Super::BeginPlay();
	OnComponentBeginOverlap.AddDynamic(this, &UEndingTrigger::OnEndingOverlap);
}

void UEndingTrigger::OnEndingOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->IsA(APlatformerChaosCharacter::StaticClass()))
	{
		TriggerEnd();
	}
}

void UEndingTrigger::TriggerEnd()
{
	UGameplayStatics::OpenLevel(GetWorld(), "L_Ending", true);
}
