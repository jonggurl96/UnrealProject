// Fill out your copyright notice in the Description page of Project Settings.


#include "CesiumAuthorizedWmsRasterOverlay.h"

std::unique_ptr<Cesium3DTilesSelection::RasterOverlay>
UCesiumAuthorizedWmsRasterOverlay::CreateOverlay(
	const Cesium3DTilesSelection::RasterOverlayOptions& options) {

	Cesium3DTilesSelection::WebMapServiceRasterOverlayOptions wmsOptions;
	if (MaximumLevel > MinimumLevel) {
		wmsOptions.minimumLevel = MinimumLevel;
		wmsOptions.maximumLevel = MaximumLevel;
	}
	wmsOptions.layers = TCHAR_TO_UTF8(*Layers);
	wmsOptions.tileWidth = TileWidth;
	wmsOptions.tileHeight = TileHeight;

	FString EncodedToken = TEXT("Basic ") + FBase64::Encode(AuthorizationToken);
	std::string StringToken = TCHAR_TO_UTF8(*EncodedToken);
	
	CesiumAsync::IAssetAccessor::THeader Header("Authorization", StringToken);
	std::vector<CesiumAsync::IAssetAccessor::THeader> Headers = {Header};
	
	return std::make_unique<Cesium3DTilesSelection::WebMapServiceRasterOverlay>(
		TCHAR_TO_UTF8(*this->MaterialLayerKey),
		TCHAR_TO_UTF8(*this->BaseUrl),
		Headers,
		wmsOptions,
		options);
}

