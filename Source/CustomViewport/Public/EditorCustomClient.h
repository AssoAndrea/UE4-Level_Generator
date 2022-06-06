// Copyright (c) Panda Studios Comm. V.  - All Rights Reserves. Under no circumstance should this could be distributed, used, copied or be published without written approved of Panda Studios Comm. V. 

#pragma once

#include "CoreMinimal.h"
#include "Editor/AdvancedPreviewScene/Public/AdvancedPreviewScene.h"
#include "EditorViewportTest.h"



class EditorCustomClient: public FEditorViewportClient
{
public:
	/** Pointer back to the Editor Viewport */
	TWeakPtr<class EditorViewportTest> ViewportPtr;

	//Constructor and destructor
	EditorCustomClient(const TSharedRef<EditorViewportTest>& InThumbnailViewport, const TSharedRef<FAdvancedPreviewScene>& InPreviewScene);

	/** Stored pointer to the preview scene in which the static mesh is shown */
	FAdvancedPreviewScene* AdvancedPreviewScene;

	virtual void Tick(float DeltaSeconds) override;
};
