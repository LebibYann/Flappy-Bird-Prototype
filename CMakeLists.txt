cmake_minimum_required(VERSION 3.25)
project(FlappyBird)

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

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

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
