// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombie.h"

// Sets default values
AZombie::AZombie()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshZombie = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Zombie Mesh"));
	RootComponent = MeshZombie;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ZombieMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ZombieMeshAsset2(TEXT("StaticMesh'/Game/StarterContent/Architecture/Pillar_50x500.Pillar_50x500'"));
	MeshZombie->SetStaticMesh(ZombieMeshAsset.Object);

	Velocidad = 150;
}

// Called when the game starts or when spawned
void AZombie::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AZombie::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector LocalizacionObjetivo = FVector(0, 200.0, 100.0); // Ubicacion del Objeto

	// Calcula la direcci�n y distancia al objetivo
	FVector Direccion = (LocalizacionObjetivo - this->GetActorLocation()).GetSafeNormal();
	float DistanciaAlObjetivo = FVector::Dist(LocalizacionObjetivo, this->GetActorLocation());

	// Calcula el desplazamiento en este frame
	float DeltaMove = Velocidad * GetWorld()->DeltaTimeSeconds;

	if (DeltaMove > DistanciaAlObjetivo)
	{
		// Si el desplazamiento excede la distancia al objetivo, mueve directamente al objetivo
		this->SetActorLocation(LocalizacionObjetivo);
	}
	else
	{
		// Mueve el objeto en la direcci�n calculada
		this->AddActorWorldOffset(Direccion * DeltaMove);
	}


}

