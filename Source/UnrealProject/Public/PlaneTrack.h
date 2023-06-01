// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <glm/vec3.hpp>
#include "CoreMinimal.h"
#include "CesiumGeoreference.h"
#include "CesiumGeospatial/Cartographic.h"
#include "CesiumGeospatial/Ellipsoid.h"
#include "Components/SplineComponent.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "PlaneTrack.generated.h"

USTRUCT(BlueprintType)
struct FAircraftRawData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	FAircraftRawData()
		: Longitude(0.0)
		, Latitude(0.0)
		, Height(0.0)
	{}

	UPROPERTY(EditAnywhere, Category = "FlightTracker")
	double Longitude;

	UPROPERTY(EditAnywhere, Category = "FlightTracker")
	double Latitude;

	UPROPERTY(EditAnywhere, Category = "FlightTracker")
	double Height;
};

UCLASS()
class UNREALPROJECT_API APlaneTrack : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlaneTrack();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// ==================== UPROPERTIES ==================== //
	UPROPERTY(BlueprintReadOnly, Category = "FlightTracker")
	USplineComponent* SplineTrack;

	UPROPERTY(EditAnywhere, Category = "FlightTracker")
	ACesiumGeoreference* CesiumGeoReference;

	UPROPERTY(EditAnywhere, Category = "FlightTracker")
	UDataTable* AricraftsRawDataTable;

	// ==================== UFUNCTIONS ==================== //
	UFUNCTION(BlueprintCallable, Category = "FlightTracker")
	void LoadSplineTrackPoints();
};
