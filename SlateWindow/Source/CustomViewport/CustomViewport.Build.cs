// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CustomViewport : ModuleRules
{
	public CustomViewport(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				//"CustomViewport/Public"
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				//"CustomViewport/Private"
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"UnrealEd",
				"ImageWrapper",
				"Slate",
				"SlateCore",
				"AssetRegistry",
				"PropertyEditor",
				//"AdvancedPreviewScene"
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Projects",
				"InputCore",
				"UnrealEd",
				"LevelEditor",
				"CoreUObject",
				"WorkspaceMenuStructure",
				"Engine",
				"Slate",
				"SlateCore",
				"ImageWrapper",
				"DesktopWidgets",
				"AssetRegistry",
				"PropertyEditor",
				"AdvancedPreviewScene",
				"ContentBrowser",
				"EditorWidgets",
				"ProceduralWorld",
				"Paper2D"
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
