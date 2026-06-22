#include "TemporaryCharacterData.h"

UTemporaryCharacterData::UTemporaryCharacterData()
	: DisplayName(TEXT("Temporary Hero"))
	, Level(1)
	, Health(100.0f)
{
}

FString UTemporaryCharacterData::ToDebugString() const
{
	return FString::Printf(TEXT("%s / Level %d / Health %.0f"), *DisplayName, Level, Health);
}
