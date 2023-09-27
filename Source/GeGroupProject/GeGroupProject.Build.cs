// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GeGroupProject : ModuleRules
{
	public GeGroupProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
