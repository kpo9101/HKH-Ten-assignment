#include "TestActor.h"
#include "Engine/Engine.h"

ATestActor::ATestActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATestActor::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("ATestActor BeginPlay - Test module is working!"));

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			5.0f,
			FColor::Green,
			TEXT("Test module spawned ATestActor!")
		);
	}
}
