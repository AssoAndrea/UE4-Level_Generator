// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorCustomClient.h"
#include "EditorViewportTest.h"

EditorCustomClient::EditorCustomClient(const TSharedRef<EditorViewportTest>& InThumbnailViewport, const TSharedRef<FAdvancedPreviewScene>& InPreviewScene)
	: FEditorViewportClient(nullptr, &InPreviewScene.Get(), StaticCastSharedRef<SEditorViewport>(InThumbnailViewport))
	, ViewportPtr(InThumbnailViewport)
{

	AdvancedPreviewScene = static_cast<FAdvancedPreviewScene*>(PreviewScene);

	// Enable RealTime
	SetRealtime(true);

	// Hide grid, we don't need this.
	DrawHelper.bDrawGrid = false;
	DrawHelper.bDrawPivot = false;
	DrawHelper.AxesLineThickness = 5;
	DrawHelper.PivotSize = 5;
	AdvancedPreviewScene->SetFloorVisibility(false);

	//Initiate view
	SetViewLocation(FVector(75, 75, 75));
	SetViewRotation(FVector(-75, -75, -75).Rotation());

	EngineShowFlags.SetScreenPercentage(true);

	// Set the Default type to Ortho and the XZ Plane
	ELevelViewportType NewViewportType = LVT_Perspective;
	SetViewportType(NewViewportType);

	// View Modes in Persp and Ortho
	SetViewModes(VMI_Lit, VMI_Lit);



	//Allow post process materials...
	EngineShowFlags.SetPostProcessMaterial(true);
	EngineShowFlags.SetPostProcessing(true);


	//Set that the mask is enabled for screenshots so it records transparency in the output



}

void EditorCustomClient::Tick(float DeltaSeconds)
{
	FEditorViewportClient::Tick(DeltaSeconds);

	// Tick the preview scene world.
	if (!GIntraFrameDebuggingGameThread)
	{
		if (AdvancedPreviewScene)
			AdvancedPreviewScene->GetWorld()->Tick(LEVELTICK_All, DeltaSeconds);
	}
}
