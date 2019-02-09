// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Components/TextBlock.h"
#include "MainHudWidget.generated.h"

/**
 * 
 */
UCLASS()
class PAKMAN_API UMainHudWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite,meta=(BindWidget))
	UTextBlock* TextBlockResult;

public:
	void SetResultText(const FText& Text);
};
