workspace "TBRNKEngine"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "TBRNKEngine/vendor/GLFW/include"

include "TBRNKEngine/vendor/GLFW"

project "TBRNKEngine"
	location "TBRNKEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "tbrnkpch.h"
	pchsource "TBRNKEngine/src/tbrnkpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TBRNK_PLATFORM_WINDOWS",
			"TBRNK_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "TBRNK_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "TBRNK_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "TBRNK_DIST"
		symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"TBRNKEngine/vendor/spdlog/include",
		"TBRNKEngine/src"
	}

	links
	{
		"TBRNKEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TBRNK_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "TBRNK_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "TBRNK_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "TBRNK_DIST"
		symbols "On"