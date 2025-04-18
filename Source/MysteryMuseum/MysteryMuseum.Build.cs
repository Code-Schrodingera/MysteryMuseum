// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MysteryMuseum : ModuleRules
{
	public MysteryMuseum(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule" });
    }
}
