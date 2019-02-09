// Fill out your copyright notice in the Description page of Project Settings.

#include "PakmanGameInstance.h"

#include "Engine/Engine.h"

#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "UObject/ConstructorHelpers.h"
//#include "MenuSystem/MainMenu.h"
//#include "MenuSystem/InGameMenu.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Engine/TargetPoint.h"
#include "PakmanGhostCharacter.h"
#include "HUD/MainHudWidget.h"

UPakmanGameInstance::UPakmanGameInstance(const FObjectInitializer & ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance constructor"));

	static ConstructorHelpers::FClassFinder<UUserWidget> MainMenuWidgetClass(TEXT("/Game/Pakman/HUD/MainMenu"));
	if (MainMenuWidgetClass.Class != NULL)
	{
		MainMenuClass = MainMenuWidgetClass.Class;
	}

	/*
	static ConstructorHelpers::FClassFinder<UUserWidget> InGameMenuWidgetClass(TEXT("/Game/Pakman/HUD/InGameMenu"));
	if (InGameMenuWidgetClass.Class != NULL)
	{
		InGameMenuClass = InGameMenuWidgetClass.Class;
	}
	*/
	
	static ConstructorHelpers::FClassFinder<APakmanGhostCharacter> GhostClass(TEXT("/Game/Pakman/PakmanGhostCharacterBP"));
	if (GhostClass.Class != NULL)
	{
		this->GhostClass = GhostClass.Class;
	}

	static ConstructorHelpers::FClassFinder<UMainHudWidget> MainHudClass(TEXT("/Game/Pakman/HUD/MainHUD"));
	if (MainHudClass.Class != NULL)
	{
		MainHud = CreateWidget<UMainHudWidget>(this, MainHudClass.Class,TEXT("MainHud"));
	}
	
	// Arrays
	GhostColors.Add(FLinearColor::Red);
	GhostColors.Add(FLinearColor::Blue);
	GhostColors.Add(FLinearColor::Green);
	GhostColors.Add(FLinearColor::Yellow);

	GhostNames.Add("Ghost 1");
	GhostNames.Add("Ghost 2");
	GhostNames.Add("Ghost 3");
	GhostNames.Add("Ghost 4");

	GhostTolerances.Add(500);
	GhostTolerances.Add(5000);
}

void UPakmanGameInstance::DisplayHUD()
{
	if (MainHud != nullptr)
	{
		MainHud->AddToViewport();
	}
}

void UPakmanGameInstance::HideHUD()
{
	if (MainHud != nullptr && MainHud->IsInViewport())
	{
		MainHud->RemoveFromViewport();
	}
}

void UPakmanGameInstance::InitInGameMenu()
{
	UE_LOG(LogTemp, Warning, TEXT("initializing ingame..."));

	//InGameMenuWidget = nullptr;
}

void UPakmanGameInstance::SetResultText(const FText& Text)
{
	MainHud->SetResultText(Text);
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

void UPakmanGameInstance::SpawnGhosts()
{
	TArray<AActor*> TargetPoints;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), TargetPoints);

	UE_LOG(LogTemp,Warning,TEXT("Found %d target points"), TargetPoints.Num());

	FActorSpawnParameters ActorSpawnParameters;
	ActorSpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	
	for (int i=0;i<TargetPoints.Num();i++)
	{
		AActor* Point = TargetPoints[i];
		FTransform Transform = Point->GetActorTransform();
		FVector Location = Transform.GetLocation();
		FRotator Rotator = Transform.GetRotation().Rotator();
		UE_LOG(LogTemp, Warning, TEXT("Spawning at %s"), *Location.ToString());
		APakmanGhostCharacter* Ghost = GetWorld()->SpawnActor<APakmanGhostCharacter>(GhostClass,Transform, ActorSpawnParameters);

		FLinearColor Color = GhostColors[i % GhostColors.Num()];
		FName Name = GhostNames[i % GhostNames.Num()];
		float Tolerance = GhostTolerances[i % GhostTolerances.Num()];

		Ghost->SetColor(Color);
		Ghost->SetName(Name);
		Ghost->SetTolerance(Tolerance);
	}
}