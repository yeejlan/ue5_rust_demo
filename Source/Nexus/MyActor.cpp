// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Components/SceneComponent.h"
#include "Components/BillboardComponent.h"
#include "Log.h"
#include "rust/cxx.h"
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
    rust::String msg2 = rust_plugin::translate::_t("假装这是翻译后的message");
    FString msg3 {UTF8_TO_TCHAR(msg2.c_str())};
    GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, *msg);
    GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, *msg3);
	UE_LOG(LogNexus, Log, TEXT("%s: 正在运行, num is %d, value is %d"), *GetName(), num, Value);
    UE_LOG(LogNexus, Log, TEXT("%s"), *msg3);
    bool isTrue = rust_plugin::feelout::return_bool(true);
    UE_LOG(LogNexus, Log, TEXT("bool result: %d"), isTrue);
    try{
        rust::String ok_result = rust_plugin::feelout::return_result_ok();
        UE_LOG(LogNexus, Log, TEXT("Got ok result: %s"), UTF8_TO_TCHAR(ok_result.c_str()));
        rust::String err_result = rust_plugin::feelout::return_result_error();
        UE_LOG(LogNexus, Log, TEXT("Got ok result: %s"), UTF8_TO_TCHAR(err_result.c_str()));
    }catch (rust::Error e) {
        UE_LOG(LogNexus, Log, TEXT("Got error result: %s"), UTF8_TO_TCHAR(e.what()));
    }
    //auto this_never_work = rust_plugin::feelout::a_panicked_function();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

