// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Components/SceneComponent.h"
#include "Components/BillboardComponent.h"
#include "Log.h"
#include "rust_plugin/src/lib.rs.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Value = 51;
	// RootComponent = ObjectInitializer.CreateDefaultSubject<USceneComponent>(this, TEXT("RootComponent"));
	// Sprite = ObjectInitializer.CreateDefaultSubject<UBillboardComponent>(this, TEXT("Sprite"));
	// Sprite->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
    int num = rust_plugin::translate::add5(3);
    FString msg = FString::FromInt(num);
    auto msg2 = rust_plugin::translate::_t("this is the message");
    FString msg3 = FString(msg2.c_str());
    GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, *msg);
    GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, *msg3);
	UE_LOG(LogNexus, Log, TEXT("%s: on play, num is %d, value is %d"), *GetName(), num, Value);
    UE_LOG(LogNexus, Log, TEXT("%s"), *msg3);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

