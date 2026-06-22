#include "Temporary.h"

#include "Logging/LogMacros.h"

DEFINE_LOG_CATEGORY_STATIC(LogTemporary, Log, All);

void FTemporaryModule::StartupModule()
{
	UE_LOG(LogTemporary, Log, TEXT("Temporary plugin module has started."));
}

void FTemporaryModule::ShutdownModule()
{
	UE_LOG(LogTemporary, Log, TEXT("Temporary plugin module has shut down."));
}

IMPLEMENT_MODULE(FTemporaryModule, Temporary)
