// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorCustomClient.h"
#include "Components/Viewport.h"
#include "Widgets/SViewport.h"
#include "Editor/AdvancedPreviewScene/Public/AdvancedPreviewScene.h"
#include "Editor/AdvancedPreviewScene/Public/AdvancedPreviewSceneModule.h"
#include "SLevelViewport.h"
#include "SEditorViewport.h"
#include "Editor/UnrealEd/Public/SCommonEditorViewportToolbarBase.h"
#include "SlateFwd.h"
#include "UObject/GCObject.h"
#include "SEditorViewport.h"


/**
 * 
 */
class CUSTOMVIEWPORT_API EditorViewportTest : public SEditorViewport, public ICommonEditorViewportToolbarInfoProvider
{
public:

	//Constructor and destructor
	//SThumbnailViewport();

	SLATE_BEGIN_ARGS(EditorViewportTest) {}
	SLATE_END_ARGS()

	/** The scene for this viewport. */
	TSharedPtr<FAdvancedPreviewScene> PreviewScene;


	//Toolbar interface
	virtual TSharedRef<class SEditorViewport> GetViewportWidget() override;
	virtual TSharedPtr<FExtender> GetExtenders() const override;
	virtual void OnFloatingButtonClicked() override;



	EditorViewportTest();
	~EditorViewportTest();
	/*
	* Construct this viewport widget
	*
	* @param	inArgs		Arguments
	*/
	void Construct(const FArguments& InArgs);

	virtual TSharedRef<FEditorViewportClient> MakeEditorViewportClient() override;

	void BindCommands() override;
	EVisibility GetTransformToolbarVisibility() const;
	void OnFocusViewportToSelection() override;
	/*
	*	Get the viewport client
	*
	*	@return the viewport client
	*/
	TSharedPtr<class EditorCustomClient> GetViewportClient() { return TypedViewportClient; };



	//Shared ptr to the client
	TSharedPtr<class EditorCustomClient> TypedViewportClient;

protected:
	FText GetTitleText() const;
};
