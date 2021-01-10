
#include "StartSpectatingPlayerController.h"
#include "GameFramework/SpectatorPawn.h"
#include "GameFramework/PlayerState.h"

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

	PlayerState->SetIsSpectator(true);
	ChangeState(NAME_Spectating);
	Client_StartSpectating();
}

void AStartSpectatingPlayerController::StartPlaying()
{
	if (!HasAuthority())
		return;

	PlayerState->SetIsSpectator(false);
	ChangeState(NAME_Playing); 
	ClientGotoState(NAME_Playing);
}

void AStartSpectatingPlayerController::Client_StartSpectating_Implementation()
{
	if (PlayerCameraManager)
		SetSpawnLocation(PlayerCameraManager->GetCameraLocation());

	ChangeState(NAME_Spectating);
}
