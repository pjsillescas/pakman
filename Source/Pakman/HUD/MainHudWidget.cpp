// Fill out your copyright notice in the Description page of Project Settings.

#include "MainHudWidget.h"

void UMainHudWidget::SetResultText(const FText& Text)
{
	TextBlockResult->SetText(Text);
}
