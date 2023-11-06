cmake_minimum_required(VERSION 3.25)
project(R-Type)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
SET(CMAKE_CXX_FLAGS  "-g")

file(GLOB_RECURSE CPP_SOURCES CONFIGURE_DEPENDS "src/*.cpp")

set(SOURCES ${CPP_SOURCES})


set(INCLUDES "./include")
file(GLOB_RECURSE SUBFOLDERS LIST_DIRECTORIES true "${INCLUDES}/*")
foreach(SUBFOLDER ${SUBFOLDERS})
    if(IS_DIRECTORY ${SUBFOLDER})
        list(APPEND INCLUDES ${SUBFOLDER})
    endif()
endforeach()

# Display lists
message("All source files :")
foreach(SOURCE ${SOURCES})
    message("\t${SOURCE}")
endforeach()
message("All include folders :")
foreach(INCLUDE ${INCLUDES})
    message("\t${INCLUDE}")
endforeach()


add_subdirectory("./lib/GraphicEngine/")
add_subdirectory("./lib/GameEngine/")
add_subdirectory("./lib/SfmlGraphic/")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDES})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_link_options(${PROJECT_NAME} PRIVATE -g3 -g)

target_link_libraries(${PROJECT_NAME} PRIVATE GameEngine)
target_link_libraries(${PROJECT_NAME} PRIVATE GraphicEngine)
target_link_libraries(${PROJECT_NAME} PRIVATE SfmlGraphic)

if(WIN32)
    string(ASCII 27 Esc)
    set(ColourReset "${Esc}[m")
    set(Yellow "${Esc}[93m")
    set(Orange "${Esc}[33m")

    message("${Orange}")
    message("INFO: Windows being quite annoying with compatibility make sure you do the following things:\n")
    message("Use MinGW g++ compiler. You can force it by doing this command: ${Yellow}cmake -B build -G \"MinGW Makefiles\"${Orange}.")
    message("If you don't have it, here's a link to download MinGW: ${Yellow}https://winlibs.com/${Orange}.")
    message("Scrolldown to ${Yellow}release version${Orange} and download the ${Yellow}POSIX${Orange} latest one (MCF won't work).")
    message("Extract the zip file whenever you want and don't forget to ${Yellow}add the bin folder of MinGW into windows environnement variable path${Orange}.")
    message("${ColourReset}")
endif()
