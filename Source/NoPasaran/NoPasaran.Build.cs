// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class NoPasaran : ModuleRules
{
	public NoPasaran(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

        // GAmeplay Ability System
        //PublicDependencyModuleNames.AddRange(new string[] { "GameplayAbilities", "GameplayTags", "GameplayTasks" });
        // AI Dependencies
        //PublicDependencyModuleNames.AddRange(new string[] { "AIModule" });
        // UMG Dependencies
        //PublicDependencyModuleNames.AddRange(new string[] { "UMG" });

        PrivateDependencyModuleNames.AddRange(new string[] {
            "GameplayAbilities",
            "GameplayTags",
            "GameplayTasks",
            "AIModule",
            "UMG"
        });

        PublicIncludePaths.AddRange(new string[] {
            "NoPasaran"
        });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
