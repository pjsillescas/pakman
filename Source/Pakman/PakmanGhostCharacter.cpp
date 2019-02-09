// Fill out your copyright notice in the Description page of Project Settings.

#include "PakmanGhostCharacter.h"

#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstanceDynamic.h"

APakmanGhostCharacter::APakmanGhostCharacter()
{
	Color = FColor::Red;
	//SetColor(Color);
	Name = "Ghost";

}

void APakmanGhostCharacter::SetColor(const FLinearColor& NewColor)
{
	Color = NewColor;
	USkeletalMeshComponent* Mesh = this->GetMesh();
	
	UMaterialInstanceDynamic* Material = Mesh->CreateDynamicMaterialInstance(0,Mesh->GetMaterial(0));
	Material->SetVectorParameterValue("BodyColor",Color);
	Mesh->SetMaterial(0, Material);
}