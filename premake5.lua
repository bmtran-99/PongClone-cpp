workspace "Pong"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "PongGame"
    location "PongGame"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/".. outputdir .. "/%{prj.name}")
    objdir ("bin-int/".. outputdir .. "/%{prj.name}")

    pchheader "pong_pch.h";
    pchsource "PongGame/src/pong_pch.cpp"
    
    files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

    defines
    {
        "NDEBUG"
    }

	includedirs
	{
        "$(SolutionDir)/Dependencies/glew/include",
        "$(SolutionDir)/Dependencies/freeglut/glut/include",
        "$(SolutionDir)/Dependencies/glm"
    }
    
    links
    {
        "opengl32.lib",
        "glew32.lib",
        "freeglut.lib"
    }

    libdirs
    {
        "$(SolutionDir)/Dependencies/glew/lib/Release/x64",
        "$(SolutionDir)/Dependencies/freeglut/lib/x64"
    }

    filter "configurations:Debug"
		defines "PONG_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "PONG_RELEASE"
		runtime "Release"
		optimize "On"