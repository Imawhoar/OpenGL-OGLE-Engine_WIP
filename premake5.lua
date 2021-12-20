include "Dependencies.lua"

workspace "OGLE"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "Engine/ThirdParty/GLFW"
	include "Engine/ThirdParty/Glad"
group ""

include "Engine"

