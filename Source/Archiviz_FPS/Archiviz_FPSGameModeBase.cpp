// Copyright Epic Games, Inc. All Rights Reserved.


#include "Archiviz_FPSGameModeBase.h"
#include "MyPlayerController.h"
AArchiviz_FPSGameModeBase::AArchiviz_FPSGameModeBase()
{
	PlayerControllerClass = AMyPlayerController::StaticClass();
}