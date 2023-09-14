// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PVZ_USFX_LAB02_BDMCGameMode.generated.h"


class AZombie;
class APlant;
UCLASS(MinimalAPI)
class APVZ_USFX_LAB02_BDMCGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APVZ_USFX_LAB02_BDMCGameMode();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FTimerHandle Temporizador;

	void Spawn();

	FVector contador;


	int contador2;


	FVector localizacion;


	// Declarar un vector de objetos
	TArray<AZombie*> Zombies;


	// Declarar un mapa de objetos
	TMap<FString, APlant*> Plantas;

	float TiempoTranscurrido;

	void aumentovelocidad();

	AZombie* NuevoZombie;
};



