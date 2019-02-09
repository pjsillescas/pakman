// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PakmanCharacter.h"
#include "PakmanGhostCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PAKMAN_API APakmanGhostCharacter : public APakmanCharacter
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(ExposeOnSpawn = true))
	FLinearColor Color;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ToleranceRadius;

public:
	APakmanGhostCharacter();

	UFUNCTION(BlueprintCallable,BlueprintSetter)
	void SetName(const FName& NewName)
	{
		Name = NewName;
	}

	UFUNCTION(BlueprintCallable,BlueprintSetter)
	void SetColor(const FLinearColor& NewColor)
	{
		Color = NewColor;
	}

	UFUNCTION(BlueprintCallable, BlueprintSetter)
	void SetTolerance(float NewTolerance)
	{
		ToleranceRadius = NewTolerance;
	}
};
