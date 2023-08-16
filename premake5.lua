workspace "Ash"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Ash"
	location "Ash"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ahpch.h"
	pchsource "Ash/src/ahpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AH_PLATFORM_WINDOWS",
			"AH_BUILD_DLL"
		}

		postbuildcommands 
		{
			"{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\" > nul"
		}


	filter "configurations:Debug"
		defines "AH_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AH_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "AH_DIST"
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
		"Ash/vendor/spdlog/include",
		"Ash/src"
	}

	links
	{
		"Ash"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AH_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "AH_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AH_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "AH_DIST"
		symbols "On"