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

project "TBRNKEngine"
	location "TBRNKEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
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