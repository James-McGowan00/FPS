// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupSpawner.h"
#include "PickUpBase.h"
#include "Components/BoxComponent.h"
#include "Assignment_1Character.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "Engine/Engine.h"
#include "Components/InterpToMovementComponent.h"

// Sets default values
APickupSpawner::APickupSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


	_BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	RootComponent = _BaseMesh;

	_BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	_BoxCollision->InitBoxExtent(FVector(75.0f, 75.0f, 100.0f));
	_BoxCollision->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));
	_BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &APickupSpawner::OnBoxBeginOverlap);
	_BoxCollision->SetupAttachment(RootComponent);

	_SpawnLocation = CreateDefaultSubobject<USceneComponent>(TEXT("SpawnLocation"));
	_SpawnLocation->SetRelativeLocation(FVector(0.0f, 0.0f, 160.0f));
	_SpawnLocation->SetupAttachment(RootComponent);


	_RotatingMove = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotatingMovement"));
	_RotatingMove->RotationRate.Yaw = 45.0f;

	_InterpMove = CreateDefaultSubobject<UInterpToMovementComponent>(TEXT("InterpMovement"));
	_InterpMove->BehaviourType = EInterpToBehaviourType::PingPong;


	_InterpMove->SetUpdatedComponent(_SpawnLocation);
	_RotatingMove->SetUpdatedComponent(_SpawnLocation);


	_SpawnDelay = 5.0f;

}

// Called when the game starts or when spawned
void APickupSpawner::BeginPlay()
{
	Super::BeginPlay();


	for (auto elem : _Pickups)
	{
		_TotalSpawnRatio += elem.Value;
	}

	SpawnPickup();

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(_SpawnLocation->GetComponentLocation()));
	
}

void APickupSpawner::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (_CurrentPickUP != nullptr && OtherActor->IsA(AAssignment_1Character::StaticClass()))
	{
		_CurrentPickUP->OnActivate(OtherActor);

		// Play Particle
		// Play sound
		// Other effects

		_CurrentPickUP->Destroy();
		_CurrentPickUP = nullptr;

		FTimerHandle _TimeHandle;
		GetWorldTimerManager().SetTimer(_TimeHandle, this, &APickupSpawner::SpawnPickup, _SpawnDelay, false);
	}
}

void APickupSpawner::SpawnPickup()
{
	if (_CurrentPickUP == nullptr)
	{
		float spawnValue = FMath::FRandRange(0.0f, _TotalSpawnRatio);
		float currentValue = 0.0f;

		for (auto elem : _Pickups)
		{
			currentValue += elem.Value;
			if (spawnValue < currentValue)
			{
				_CurrentPickUP = GetWorld()->SpawnActor<APickUpBase>(elem.Key);
				_CurrentPickUP->SetActorLocation(_SpawnLocation->GetComponentLocation());
				_CurrentPickUP->AttachToComponent(_SpawnLocation, FAttachmentTransformRules::KeepWorldTransform);
				return;

			}

		}
	}
}

