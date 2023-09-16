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

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Ash/vendor/GLFW/include"
IncludeDir["Glad"] = "Ash/vendor/Glad/include"
IncludeDir["ImGui"] = "Ash/vendor/imgui"
IncludeDir["glm"] = "Ash/vendor/glm"

include "Ash/vendor/GLFW"
include "Ash/vendor/Glad"
include "Ash/vendor/imgui"

project "Ash"
	location "Ash"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ahpch.h"
	pchsource "Ash/src/ahpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
		"dwmapi.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"AH_PLATFORM_WINDOWS",
			"AH_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands 
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "AH_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "AH_RELEASE"
		runtime "Release"
		symbols "On"

	filter "configurations:Dist"
		defines "AH_DIST"
		runtime "Release"
		symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

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
		"Ash/src",
		"Ash/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Ash"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"AH_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "AH_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "AH_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "AH_DIST"
		runtime "Release"
		optimize "On"