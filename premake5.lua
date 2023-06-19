workspace "Ether"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Ether"
	location "Ether"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "On"
	systemversion "latest"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	defines
	{
		"ET_PLATFORM_WINDOWS",
		"ET_BUILD_DLL"
	}

	filter "configurations:Debug"
		defines "ET_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "ET_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ET_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "On"
	systemversion "latest"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Ether/vendor/spdlog/include",
		"Ether/src"
	}

	links
	{
		"Ether"
	}

	defines
	{
		"ET_PLATFORM_WINDOWS"
	}

	postbuildcommands
    {
        "{COPY} ../bin/" .. outputdir .. "/Ether/*.dll ../bin/" .. outputdir .. "/Sandbox"
    }

	filter "configurations:Debug"
		defines "ET_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "ET_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ET_DIST"
		optimize "On"