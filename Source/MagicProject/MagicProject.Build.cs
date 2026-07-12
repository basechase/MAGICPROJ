// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MagicProject : ModuleRules
{
	public MagicProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
            "GameplayAbilities",
			"GameplayTags",
			"GameplayTasks"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"MagicProject",
			"MagicProject/Variant_Platforming",
			"MagicProject/Variant_Platforming/Animation",
			"MagicProject/Variant_Combat",
			"MagicProject/Variant_Combat/AI",
			"MagicProject/Variant_Combat/Animation",
			"MagicProject/Variant_Combat/Gameplay",
			"MagicProject/Variant_Combat/Interfaces",
			"MagicProject/Variant_Combat/UI",
			"MagicProject/Variant_SideScrolling",
			"MagicProject/Variant_SideScrolling/AI",
			"MagicProject/Variant_SideScrolling/Gameplay",
			"MagicProject/Variant_SideScrolling/Interfaces",
			"MagicProject/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
