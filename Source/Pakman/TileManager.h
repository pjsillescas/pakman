// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TileManager.generated.h"

UCLASS()
class PAKMAN_API ATileManager : public AActor
{
	GENERATED_BODY()

private:
	int XNTiles;
	int YNTiles;
	bool** AdjacencyMatrix;

	void ATileManager::InitializeAdjacencyMatrix();

public:	
	// Sets default values for this actor's properties
	ATileManager();

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float XTileSize;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float YTileSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* TileMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
