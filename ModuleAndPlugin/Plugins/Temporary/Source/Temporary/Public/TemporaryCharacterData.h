#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TemporaryCharacterData.generated.h"

UCLASS(BlueprintType, Blueprintable)
class TEMPORARY_API UTemporaryCharacterData : public UObject
{
	GENERATED_BODY()

public:
	UTemporaryCharacterData();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Data")
	FString DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Data")
	int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Data")
	float Health;

	UFUNCTION(BlueprintCallable, Category = "Character Data")
	FString ToDebugString() const;
};
