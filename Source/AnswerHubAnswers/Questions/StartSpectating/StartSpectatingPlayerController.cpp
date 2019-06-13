
#include "StartSpectatingPlayerController.h"
#include "GameFramework/SpectatorPawn.h"

void AStartSpectatingPlayerController::OnRep_Pawn()
{
	Super::OnRep_Pawn();

	if (GetStateName() == NAME_Spectating)
	{
		AutoManageActiveCameraTarget(GetSpectatorPawn());
	}
}

void AStartSpectatingPlayerController::StartSpectating()
{
	if (!HasAuthority())
		return;

	ChangeState(NAME_Spectating);
	Client_StartSpectating();
}

void AStartSpectatingPlayerController::StartPlaying()
{
	if (!HasAuthority())
		return;

	ChangeState(NAME_Playing); 
	ClientGotoState(NAME_Playing);
}

void AStartSpectatingPlayerController::Client_StartSpectating_Implementation()
{
	if (PlayerCameraManager)
		SetSpawnLocation(PlayerCameraManager->GetCameraLocation());

	ChangeState(NAME_Spectating);
}
