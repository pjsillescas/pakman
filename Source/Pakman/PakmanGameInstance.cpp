// Fill out your copyright notice in the Description page of Project Settings.

#include "PakmanGameInstance.h"

#include "Engine/Engine.h"

#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "UObject/ConstructorHelpers.h"
//#include "MenuSystem/MainMenu.h"
//#include "MenuSystem/InGameMenu.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"

UPakmanGameInstance::UPakmanGameInstance(const FObjectInitializer & ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance constructor"));

	static ConstructorHelpers::FClassFinder<UUserWidget> MainMenuWidgetClass(TEXT("/Game/Pakman/HUD/MainMenu"));
	if (MainMenuWidgetClass.Class != NULL)
	{
		UE_LOG(LogTemp, Warning, TEXT("Main menu class found!!"));
		MainMenuClass = MainMenuWidgetClass.Class;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Main menu class NOT found :("));
	}

	/*
	static ConstructorHelpers::FClassFinder<UUserWidget> InGameMenuWidgetClass(TEXT("/Game/Pakman/HUD/InGameMenu"));
	if (InGameMenuWidgetClass.Class != NULL)
	{
		InGameMenuClass = InGameMenuWidgetClass.Class;
	}
	*/
}

void UPakmanGameInstance::InitInGameMenu()
{
	UE_LOG(LogTemp, Warning, TEXT("initializing ingame..."));

	//InGameMenuWidget = nullptr;
}


void UPakmanGameInstance::TeardownMainMenu()
{
	/*
	if (MainMenuWidget != nullptr)
	{
		MainMenuWidget->Teardown();
		MainMenuWidget = nullptr;
	}
	*/
}

void UPakmanGameInstance::ClientTravel(const FString& Url)
{
	PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel(Url, ETravelType::TRAVEL_Absolute);
}

void UPakmanGameInstance::LoadMainMenu()
{
	ClientTravel("/Game/Pakman/Maps/MainMenuLevel");
}

void UPakmanGameInstance::StartGame()
{
	ClientTravel("/Game/Pakman/Maps/MainMap");
}

void UPakmanGameInstance::QuitGame()
{
	PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ConsoleCommand("quit", true);
}


void UPakmanGameInstance::LoadMenuWidget()
{
	MainMenuWidget = CreateWidget<UMainMenu>(this, MainMenuClass, FName("MainMenu"));
	if (!ensure(MainMenuWidget != nullptr)) return;

	UE_LOG(LogTemp,Warning,TEXT("Loading menu widget"));
	MainMenuWidget->Setup();

	MainMenuWidget->SetMenuInterface(this);
}

void UPakmanGameInstance::LoadInGameMenu()
{
	/*
	UE_LOG(LogTemp, Warning, TEXT("LoadInGame"));
	if (InGameMenuWidget == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Loading ingame..."));
		InGameMenuWidget = CreateWidget<UInGameMenu>(this, InGameMenuClass, FName("InGameMenu"));
		if (!ensure(InGameMenuWidget != nullptr)) return;

	}

	InGameMenuWidget->Setup();
	InGameMenuWidget->SetMenuInterface(this);
	*/
}
