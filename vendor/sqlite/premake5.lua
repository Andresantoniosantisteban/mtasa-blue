project "sqlite"
	language "C++"
	kind "StaticLib"
	targetname "sqlite"

	disablewarnings { "4996" }
	
	vpaths { 
		["Headers/*"] = "**.h",
		["Sources/*"] = "*.c",
		["*"] = "premake5.lua"
	}
	
	files {
		"premake5.lua",
		"*.h",
		"*.c"
	}
	