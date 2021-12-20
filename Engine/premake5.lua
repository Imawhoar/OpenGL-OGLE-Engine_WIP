
-- premake5.lua
project "Engine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "OEPCH.h"
	pchsource "src/OEPCH.cpp"

	files
	{
		"src/**.h",
		"src/**.cpp",
		"%{wks.location}/ThirdParty/stb_image/**.h",
		"%{wks.location}/ThirdParty/stb_image/**.cpp",
		"%{wks.location}/ThirdParty/glm/glm/**.hpp",
		"%{wks.location}/ThirdParty/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	includedirs
	{
		"src",
		"%{IncludeDir.glfw}",
		"%{IncludeDir.glad}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.entt}",
	}

	links
	{
		"GLFW",
		"Glad",
		"opengl32.lib"
	}


	filter "system:windows"
		systemversion "latest"

		defines
		{
		}

	filter "configurations:Debug"
		defines "OE_DEBUG"
		runtime "Debug"
		symbols "on"


	filter "configurations:Release"
		defines "OE_RELEASE"
		runtime "Release"
		optimize "on"


