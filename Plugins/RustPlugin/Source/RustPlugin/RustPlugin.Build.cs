// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class RustPlugin : ModuleRules
{
	public RustPlugin(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		Type = ModuleType.External;

        string lib = Path.Combine(PluginDirectory, "target\\release\\rust_plugin.lib");
        string includes = Path.Combine(PluginDirectory, "target\\cxxbridge");

        PublicAdditionalLibraries.Add(lib);
        PublicIncludePaths.Add(includes); 
        
        PublicSystemLibraries.Add("kernel32.lib");
        PublicSystemLibraries.Add("advapi32.lib");
        PublicSystemLibraries.Add("bcrypt.lib");
        PublicSystemLibraries.Add("ntdll.lib");
        PublicSystemLibraries.Add("userenv.lib");
        PublicSystemLibraries.Add("ws2_32.lib");
        PublicSystemLibraries.Add("msvcrt.lib");

    }
}
