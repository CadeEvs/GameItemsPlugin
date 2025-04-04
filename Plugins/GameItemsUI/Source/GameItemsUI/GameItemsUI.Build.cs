﻿// Copyright Bohdon Sayre, All Rights Reserved.

using UnrealBuildTool;

public class GameItemsUI : ModuleRules
{
	public GameItemsUI(ReadOnlyTargetRules Target) : base(Target)
	{
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"GameItems",
			"GameplayTags",
			"ModelViewViewModel",
			"UMG",
		});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"CoreUObject",
			"Engine",
			"Slate",
			"SlateCore",
		});
	}
}