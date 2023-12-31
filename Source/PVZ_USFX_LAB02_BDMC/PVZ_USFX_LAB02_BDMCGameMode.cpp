// Copyright Epic Games, Inc. All Rights Reserved.

#include "PVZ_USFX_LAB02_BDMCGameMode.h"
#include "PVZ_USFX_LAB02_BDMCPawn.h"
#include "Spawns.h"
#include "Zombie.h"
#include "Plant.h"
#include "Sol.h"
#include "Math/UnrealMathUtility.h"
#include "Engine/Engine.h"
#include "Jugador.h"


APVZ_USFX_LAB02_BDMCGameMode::APVZ_USFX_LAB02_BDMCGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = APVZ_USFX_LAB02_BDMCPawn::StaticClass();

	contador = FVector(0, 0, 0);
	localizacion = FVector(400.0, 200.0, 100.0);
	contador2 = 0;

	TiempoTranscurrido = 0.0f;
}
void APVZ_USFX_LAB02_BDMCGameMode::BeginPlay()
{
	// Definici�n de un objeto de tipo World
	UWorld* const World = GetWorld();

	ASpawns* Spawn1 = GetWorld()->SpawnActor<ASpawns>(ASpawns::StaticClass(), FVector(0, 0, 0), FRotator::ZeroRotator);
	// 
	//AZombie* Zombie1 = GetWorld()->SpawnActor<AZombie>(AZombie::StaticClass(), FVector(400.0, 200.0, 100.0), FRotator::ZeroRotator);



	//World->GetTimerManager().SetTimer(Temporizador, this, &APVZ_USFX_LAB02GameModeBase::Spawn, 2, true);

	//Aparici�n de los soles
	ASol* Sol1 = GetWorld()->SpawnActor<ASol>(ASol::StaticClass(), FVector(-400, -50, 160), FRotator::ZeroRotator);
	//ASol* Sol2 = GetWorld()->SpawnActor<ASol>(ASol::StaticClass(), FVector(-450, -50, 160), FRotator::ZeroRotator);

	//Definiendo la posici�n de los zombies
	FVector SpawnLocationZombie = FVector(-800.0f, 400.0f, 160.0f);

	// Genera 5 zombies
	for (int i = 0; i < 5; i++) {
		// Define una posici�n temporal para el zombie en X
		SpawnLocationZombie.X += 100;
		// Aparicion de los zombies


		NuevoZombie = GetWorld()->SpawnActor<AZombie>(AZombie::StaticClass(), SpawnLocationZombie, FRotator::ZeroRotator);

		NuevoZombie->Velocidad = FMath::FRandRange(0.1, 0.5);

		Zombies.Add(NuevoZombie);
	}
	//Definiendo la posici�n de las plantas
	FVector SpawnLocationPlant = FVector(-800.0f, -600.0f, 160.0f);
	FVector SpawnLocationPlantTemp = SpawnLocationPlant;

	// Genera 5 plantas
	for (int i = 0; i < 5; i++)
	{
		//Define una posicion temporal para la planta en X
		SpawnLocationPlantTemp.X += 100;
		for (int j = 0; j < 2; j++)
		{

			// Define una posici�n temporal para la planta en Y
			SpawnLocationPlantTemp.Y += 80;

			// Genera un nombre para la planta
			FString NombrePlanta = FString::Printf(TEXT("Planta%d"), i + 1);

			// Crea una nueva instancia de APlant en el mundo
			APlant* NuevaPlanta = GetWorld()->SpawnActor<APlant>(APlant::StaticClass(), SpawnLocationPlantTemp, FRotator::ZeroRotator);

			// Asigna un valor aleatorio a la energ�a de la planta
			NuevaPlanta->energia = FMath::FRandRange(0.0, 10.0);

			// Muestra un mensaje en la consola
			UE_LOG(LogTemp, Warning, TEXT("Energ�a de %s: %i"), *NombrePlanta, NuevaPlanta->energia);

			// Muestra un mensaje en la pantalla
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Energ�a de %s: %i"), *NombrePlanta, NuevaPlanta->energia));

			// Agrega la planta al contenedor de plantas
			Plantas.Add(NombrePlanta, NuevaPlanta);

			// Coloca la planta en una posici�n diferente
			//NuevaPlanta->SetActorLocation(FVector(i * 100, 0, 0));


		}
		// Define una posici�n temporal para la planta en Y

		SpawnLocationPlantTemp.Y = SpawnLocationPlant.Y;
	}



	World->GetTimerManager().SetTimer(Temporizador, this, &APVZ_USFX_LAB02_BDMCGameMode::aumentovelocidad, 1, true);


}


void APVZ_USFX_LAB02_BDMCGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//TiempoTranscurrido += DeltaTime;

	//if (TiempoTranscurrido > 2.0f) {
	//	// Iterar sobre el vector de objetos
	//	for (int i = 0; i < Zombies.Num(); i++) {
	//		Zombies[i]->Velocidad = FMath::FRand() * 2.0f;

	//		//Zombies[i]->MovementSpeed += i * 1.0f;
	//	}
	//	TiempoTranscurrido = 0.0f;
	//}

}

void APVZ_USFX_LAB02_BDMCGameMode::Spawn()
{
	contador2++;

	contador = contador + FVector(100, 0, 0);
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Este es un mensaje")));


	AZombie* Zombie1 = GetWorld()->SpawnActor<AZombie>(AZombie::StaticClass(), localizacion, FRotator::ZeroRotator);



	localizacion.X = localizacion.X + contador2 * 100;
	localizacion.Y = localizacion.Y + contador2 * 100;
	//localizacion = localizacion + contador;




}

void APVZ_USFX_LAB02_BDMCGameMode::aumentovelocidad()
{
	for (int i = 0; i < Zombies.Num(); i++)
	{
		Zombies[i]->Velocidad = +FMath::FRandRange(0, 0.2);
	}

}
