// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUD/MenuBase.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class PAKMAN_API UMainMenu : public UMenuBase
{
	GENERATED_BODY()

private:
	UPROPERTY(meta = (BindWidget))
	class UButton* ButtonNewGame;
	
	UPROPERTY(meta = (BindWidget))
	class UButton* ButtonQuitGame;

public:
	UMainMenu();

protected:
	virtual bool Initialize() override;

	void SetWidgetSwitcher(UWidget * Widget);

	UFUNCTION()
	void StartGame();

	UFUNCTION()
	void QuitGame();


};
