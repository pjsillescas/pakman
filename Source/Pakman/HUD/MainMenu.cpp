// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"

#include "Components/Button.h"


UMainMenu::UMainMenu()
{
	/*
	static ConstructorHelpers::FClassFinder<UUserWidget> ServerTextBlockWidgetClass(TEXT("/Game/MenuSystem/WBPServerTextBlock"));
	if (ServerTextBlockWidgetClass.Class != NULL)
	{
		ServerTextBlockClass = ServerTextBlockWidgetClass.Class;
	}
	*/

}

bool UMainMenu::Initialize()
{
	bool IsInitialized = Super::Initialize();

	if (IsInitialized)
	{
		if (!ensure(ButtonNewGame != nullptr)) return false;
		ButtonNewGame->OnClicked.AddDynamic(this, &UMainMenu::StartGame);

		if (!ensure(ButtonQuitGame != nullptr)) return false;
		ButtonQuitGame->OnClicked.AddDynamic(this, &UMainMenu::QuitGame);
	}

	return IsInitialized;
}

void UMainMenu::SetWidgetSwitcher(UWidget* Widget)
{
	/*
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(Widget != nullptr)) return;

	MenuSwitcher->SetActiveWidget(Widget);
	*/
}
void UMainMenu::StartGame()
{
	Teardown();
	MenuInterface->StartGame();
}

void UMainMenu::QuitGame()
{
	if (MenuInterface != nullptr)
	{
		MenuInterface->QuitGame();
	}
}
