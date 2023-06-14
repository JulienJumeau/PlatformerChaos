// Fill out your copyright notice in the Description page of Project Settings.


#include "EndingFlag.h"
#include "EndingTrigger.h"

AEndingFlag::AEndingFlag()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	EndingTrigger = CreateDefaultSubobject<UEndingTrigger>("EndingTrigger");
	EndingTrigger->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);
}
