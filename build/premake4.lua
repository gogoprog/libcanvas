solution "libcanvas"
    configurations { "Debug", "Release", "EmscriptenDebug", "EmscriptenRelease" }

    project "libcanvas"
        kind "ConsoleApp"
        language "C++"
        files { "../src/**/*.h", "../src/**/*.cpp" }

        configuration "*Debug"
            defines { "DEBUG" }
            flags { "Symbols" }

        configuration "*Release"
            defines { "NDEBUG" }
            flags { "Optimize" }
            linkoptions { "-O2" }

        configuration "Emscripten*"
            buildoptions { "--std=c++11" }
            targetname "libcanvas_test.html"
            linkoptions {
                "--js-library ../src/lib/libcanvas.js"
            }
        configuration {}

