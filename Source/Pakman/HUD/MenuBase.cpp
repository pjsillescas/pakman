// Fill out your copyright notice in the Description page of Project Settings.

#include "MenuBase.h"

void UMenuBase::SetInputModeGame()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	FInputModeGameOnly InputMode;
	InputMode.SetConsumeCaptureMouseDown(false);
	PlayerController->SetInputMode(InputMode);
	PlayerController->bShowMouseCursor = false;
}

void UMenuBase::SetInputModeUI()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	FInputModeUIOnly InputMode;
	InputMode.SetWidgetToFocus(this->TakeWidget());
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	PlayerController->SetInputMode(InputMode);
	PlayerController->bShowMouseCursor = true;
}

void UMenuBase::Setup()
{
	AddToViewport();

	SetInputModeUI();
}

void UMenuBase::Teardown()
{
	RemoveFromViewport();

	SetInputModeGame();
}

void UMenuBase::SetMenuInterface(IMenuInterface * NewMenuInterface)
{
	MenuInterface = NewMenuInterface;
}

IMenuInterface * UMenuBase::GetMenuInterface() const
{
	return MenuInterface;
}
