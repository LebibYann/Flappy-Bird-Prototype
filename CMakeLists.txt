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

# include(FetchContent)
# FetchContent_Declare(SFML
#     GIT_REPOSITORY https://github.com/SFML/SFML.git
#     GIT_TAG 2.6.x)
# FetchContent_MakeAvailable(SFML)
add_subdirectory("./lib/GraphicEngine/")
add_subdirectory("./lib/GameEngine/")
add_subdirectory("./lib/SfmlGraphic/")
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

set(SFML_VERSION 2.6.1)
find_package(sfml ${SFML_VERSION} QUIET)
if (NOT sfml_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        sfml
        DOWNLOAD_EXTRACT_TIMESTAMP OFF
        URL https://github.com/SFML/SFML/archive/refs/tags/${SFML_VERSION}.tar.gz
    )
    FetchContent_GetProperties(sfml)
    if (NOT sfml_POPULATED)
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(sfml)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
        add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
    endif()
    target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)
endif()



target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDES})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_link_options(${PROJECT_NAME} PRIVATE -g3 -g)

target_link_libraries(${PROJECT_NAME} PRIVATE GameEngine)
target_link_libraries(${PROJECT_NAME} PRIVATE GraphicEngine)
target_link_libraries(${PROJECT_NAME} PRIVATE SfmlGraphic)
