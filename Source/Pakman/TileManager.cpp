// Fill out your copyright notice in the Description page of Project Settings.

#include "TileManager.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
//#include "Runtime/Engine/Classes/World.h"

// Sets default values
ATileManager::ATileManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	XTileSize = 200;
	YTileSize = 200;

	XNTiles = 20;
	YNTiles = 20;
	
	TileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TileMesh"));

	InitializeAdjacencyMatrix();
}

void ATileManager::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	for (int i = 0; i < XNTiles; i++)
		delete[] AdjacencyMatrix[i];
	
	delete[] AdjacencyMatrix;
}

void ATileManager::InitializeAdjacencyMatrix()
{
	FVector Origin = GetActorLocation();
	
	AdjacencyMatrix = new bool*[XNTiles];
	for (int i = 0; i < XNTiles; i++)
	{
		AdjacencyMatrix[i] = new bool[YNTiles];

		for (int j = 0; j < YNTiles; j++)
		{
			int X, Y, Z;
			X = Origin.X + (2 * i - XNTiles + 1) * XTileSize / 2;
			Y = Origin.Y + (2 * j - YNTiles + 1) * YTileSize / 2;
			Z = Origin.Z + 200;

			//GetWorld()->SpawnActor()

			//AdjacencyMatrix[i][j] = false;
		}
	}
}

// Called when the game starts or when spawned
void ATileManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATileManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

