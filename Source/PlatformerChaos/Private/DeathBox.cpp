// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathBox.h"
#include <Kismet/GameplayStatics.h>
#include "../PlatformerChaosCharacter.h" // Include the header file of ACharacter

UDeathBox::UDeathBox()
{
	OnComponentBeginOverlap.AddDynamic(this, &UDeathBox::OnDeathBoxOverlap);
}

void UDeathBox::OnDeathBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->IsA(APlatformerChaosCharacter::StaticClass()))
	{
		ResetLevel();
	}
}

void UDeathBox::ResetLevel()
{
	UWorld* world = GetWorld();

	if (world)
	{
		FString levelName = UGameplayStatics::GetCurrentLevelName(world, true);
		UGameplayStatics::OpenLevel(GetWorld(), FName(*levelName), true);
	}
}
