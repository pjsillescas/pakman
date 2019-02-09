// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "HUD/MenuInterface.h"
#include "HUD/MainMenu.h"
#include "PakmanGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PAKMAN_API UPakmanGameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()
	
private:
	TSubclassOf<class UUserWidget> MainMenuClass;
	TSubclassOf<class UUserWidget> InGameMenuClass;
	APlayerController* PlayerController;
	class UMainMenu* MainMenuWidget;
	//class UInGameMenu* InGameMenuWidget;

public:
	UPakmanGameInstance(const FObjectInitializer & ObjectInitializer);

	void InitInGameMenu();

	void TeardownMainMenu();

	void ClientTravel(const FString & Url);

	UFUNCTION(BlueprintCallable)
		void LoadMenuWidget();

	UFUNCTION(BlueprintCallable)
		void LoadInGameMenu();
	
	UFUNCTION()
	void LoadMainMenu() override;

	UFUNCTION()
	void StartGame() override;

	UFUNCTION()
	void QuitGame() override;
};
