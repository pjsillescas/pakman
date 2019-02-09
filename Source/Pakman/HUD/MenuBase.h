// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HUD/MenuInterface.h"
#include "MenuBase.generated.h"

/**
 * 
 */
UCLASS()
class PAKMAN_API UMenuBase : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	void SetInputModeGame();
	void SetInputModeUI();

	IMenuInterface* MenuInterface;


public:
	virtual void Setup();
	virtual void Teardown();

	void SetMenuInterface(IMenuInterface* NewMenuInterface);

	FORCEINLINE IMenuInterface* GetMenuInterface() const;

};
