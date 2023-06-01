// Fill out your copyright notice in the Description page of Project Settings.


#include "PlaneTrack.h"

// Sets default values
APlaneTrack::APlaneTrack()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SplineTrack = CreateDefaultSubobject<USplineComponent>("SplineTrack");

	SplineTrack->SetDrawDebug(true);

	SplineTrack->SetUnselectedSplineSegmentColor(FLinearColor(1.f, 0.f, 0.f));
}


// Called when the game starts or when spawned
void APlaneTrack::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlaneTrack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlaneTrack::LoadSplineTrackPoints()
{
	if(this->AricraftsRawDataTable != nullptr && this->CesiumGeoReference != nullptr)
	{
		int32 PointIndex = 0;
		for (auto& row : this->AricraftsRawDataTable->GetRowMap())
		{
			// 좌표 분할
			FAircraftRawData* Point = reinterpret_cast<FAircraftRawData*>(row.Value);
			double PointLatitude = Point->Latitude;
			double PointLongitude = Point->Longitude;
			double PointHeight = Point->Height;

			// UE 내의 위치 계산 후 SplineComponnet에 Point 추가
			glm::dvec3 UECoords = this->CesiumGeoReference->TransformLongitudeLatitudeHeightToUnreal(glm::dvec3(PointLongitude, PointLatitude, PointHeight));
			FVector SplinePointPosition = FVector(UECoords.x, UECoords.y, UECoords.z);
			this->SplineTrack->AddSplinePointAtIndex(SplinePointPosition, PointIndex, ESplineCoordinateSpace::World, false);

			// 좌표계 설정 WGS84
			const CesiumGeospatial::Ellipsoid& Ellipsoid = CesiumGeospatial::Ellipsoid::WGS84;

			// 좌표계의 위도, 경도를 벡터로 표현
			glm::dvec3 upVector = Ellipsoid.geodeticSurfaceNormal(CesiumGeospatial::Cartographic(FMath::DegreesToRadians(PointLongitude),
				FMath::DegreesToRadians(PointLatitude), FMath::DegreesToRadians(PointHeight)));

			// ECEF - Earth-Centered Earth-Fixed, 지구중심고정좌표계: 지구의 중력 중심을 원점으로 하는 좌표계
			glm::dvec4 ecefUp(upVector, 0.0);

			// ecef, georeference, unreal 좌표계 변환을 캡슐화한 객체
			const GeoTransforms& GeoTransforms = this->CesiumGeoReference->GetGeoTransforms();

			// ecef -> unreal 좌표계 변환 행렬을 통해 unreal 좌표를 4차원 벡터로 저장
			const glm::dmat4& ecefToUnreal = GeoTransforms.GetEllipsoidCenteredToAbsoluteUnrealWorldTransform();
			glm::dvec4 unrealUp = ecefToUnreal * ecefUp;
			this->SplineTrack->SetUpVectorAtSplinePoint(PointIndex++, FVector(unrealUp.x, unrealUp.y, unrealUp.z), ESplineCoordinateSpace::World, false);
		}
	}
	this->SplineTrack->UpdateSpline();
}


