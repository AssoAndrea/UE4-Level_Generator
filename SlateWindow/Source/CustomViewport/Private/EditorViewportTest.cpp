// Fill out your copyright notice in the Description page of Project Settings.


#include "EditorViewportTest.h"


TSharedRef<class SEditorViewport> EditorViewportTest::GetViewportWidget()
{
	return SharedThis(this);
}

TSharedPtr<FExtender> EditorViewportTest::GetExtenders() const
{
	TSharedPtr<FExtender> Result(MakeShareable(new FExtender));
	return Result;
}

void EditorViewportTest::OnFloatingButtonClicked()
{
	// Nothing
}

//Just create the advnaced preview scene and initiate components
EditorViewportTest::EditorViewportTest() : PreviewScene(MakeShareable(new FAdvancedPreviewScene(FPreviewScene::ConstructionValues())))
{

}

EditorViewportTest::~EditorViewportTest()
{
	if (TypedViewportClient.IsValid())
	{
		TypedViewportClient->Viewport = NULL;
	}
}

void EditorViewportTest::Construct(const FArguments& InArgs)
{
	SEditorViewport::Construct(SEditorViewport::FArguments());
}


TSharedRef<FEditorViewportClient> EditorViewportTest::MakeEditorViewportClient()
{
	TypedViewportClient = MakeShareable(new EditorCustomClient(SharedThis(this), PreviewScene.ToSharedRef()));
	return TypedViewportClient.ToSharedRef();
}

void EditorViewportTest::BindCommands()
{
	SEditorViewport::BindCommands();
}

EVisibility EditorViewportTest::GetTransformToolbarVisibility() const
{
	return EVisibility::Visible;
}

void EditorViewportTest::OnFocusViewportToSelection()
{

}




FText EditorViewportTest::GetTitleText() const
{
	//return the title text of the viewport
	return FText::FromString("Thumbnail Generator");
}
