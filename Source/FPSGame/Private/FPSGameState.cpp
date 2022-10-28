// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSGameState.h"
#include "FPSPlayerController.h"


void AFPSGameState::MulticastMissionComplete_Implementation(APawn* InstigatorPawn, bool bMissionSuccess)
{
	for (TPlayerControllerIterator<AFPSPlayerController>::ServerAll It(GetWorld()); It; ++It)
	{
		AFPSPlayerController* PC = *It;
		if (PC && PC->IsLocalController())
		{
			PC->OnMissionCompleted(InstigatorPawn, bMissionSuccess);

			// Disable Input
			APawn* MyPawn = It->GetPawn();
			if(MyPawn)
			{
				MyPawn->DisableInput(nullptr);
			}
		}
	}
}
