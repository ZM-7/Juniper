workspace "Juniper"
	architecture "x64"
	startproject "Sandbox"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Juniper"
	location "Juniper"
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

	buildoptions
	{
		"/utf-8"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"JP_PLATFORM_WINDOWS",
			"JP_BUILD_DLL"
		}

		postbuildcommands
		{
			"{MKDIR} ../bin/" .. outputdir .. "/Sandbox/",
			"{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/"
		}


	filter "configurations:Debug"
		defines "JP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "JP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "JP_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
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
		"Juniper/vendor/spdlog/include",
		"Juniper/src"
	}

	buildoptions
	{
		"/utf-8"
	}

	links
	{
		"Juniper"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"JP_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "JP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "JP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "JP_DIST"
		optimize "On"