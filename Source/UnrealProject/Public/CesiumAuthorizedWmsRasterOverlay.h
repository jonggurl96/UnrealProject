// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CesiumWebMapServiceRasterOverlay.h"
#include "Cesium3DTilesSelection/WebMapServiceRasterOverlay.h"
#include "Misc/Base64.h"
#include "CesiumAuthorizedWmsRasterOverlay.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Cesium), meta = (BlueprintSpawnableComponent))
class UNREALPROJECT_API UCesiumAuthorizedWmsRasterOverlay : public UCesiumWebMapServiceRasterOverlay
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Cesium")
	FString AuthorizationToken;

protected:
	virtual std::unique_ptr<Cesium3DTilesSelection::RasterOverlay> CreateOverlay(
		const Cesium3DTilesSelection::RasterOverlayOptions& options = {})
		override;
	
};
