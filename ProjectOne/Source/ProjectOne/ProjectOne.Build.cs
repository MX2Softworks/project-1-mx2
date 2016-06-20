// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class ProjectOne : ModuleRules
{
	public ProjectOne(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Paper2D" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

        //comment out below lines if we start to notice slower compile times once we have more than 20+ header and source files. 
        MinFilesUsingPrecompiledHeaderOverride = 1;
        bFasterWithoutUnity = true;


        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");
        // if ((Target.Platform == UnrealTargetPlatform.Win32) || (Target.Platform == UnrealTargetPlatform.Win64))
        // {
        //		if (UEBuildConfiguration.bCompileSteamOSS == true)
        //		{
        //			DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
        //		}
        // }
    }
}
