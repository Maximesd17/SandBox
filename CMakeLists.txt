cmake_minimum_required(VERSION 3.25)

project(SandBox
    VERSION 0.1
    DESCRIPTION 2d_platform_game
    LANGUAGES CXX)

add_executable(SandBox)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

target_include_directories(SandBox PRIVATE ./include/)

set(SB_SRC_FOLDER ./src CACHE PATH "root folder for sources")
set(SB_SRC_GAME_FOLDER ${SB_SRC_FOLDER}/Game CACHE INTERNAL "sources subfolder \"Game\"")
set(SB_SRC_SCENES_FOLDER ${SB_SRC_FOLDER}/Scenes CACHE INTERNAL "sources subfolder \"Scenes\"")
set(SB_SRC_COMPONENTS_FOLDER ${SB_SRC_FOLDER}/Components CACHE INTERNAL "sources subfolder \"Components\"")

set(SB_SOURCES PRIVATE ${SB_SRC_FOLDER}/main.cpp
    PRIVATE ${SB_SRC_FOLDER}/SandBox.cpp
    PRIVATE ${SB_SRC_FOLDER}/State.cpp
    PRIVATE ${SB_SRC_GAME_FOLDER}/Game.cpp
    PRIVATE ${SB_SRC_GAME_FOLDER}/MapGenerator.cpp
    PRIVATE ${SB_SRC_SCENES_FOLDER}/AScene.cpp
    PRIVATE ${SB_SRC_SCENES_FOLDER}/SGame.cpp
    PRIVATE ${SB_SRC_SCENES_FOLDER}/SMainGame.cpp
    PRIVATE ${SB_SRC_SCENES_FOLDER}/SMainMenu.cpp
    PRIVATE ${SB_SRC_SCENES_FOLDER}/SMenu.cpp
    PRIVATE ${SB_SRC_SCENES_FOLDER}/SSettingsMenu.cpp
    PRIVATE ${SB_SRC_COMPONENTS_FOLDER}/Button.cpp
    PRIVATE ${SB_SRC_COMPONENTS_FOLDER}/Player.cpp)

add_library(SBLib INTERFACE)

set(SB_HEADERS_FOLDER ./include)
INCLUDE_DIRECTORIES(${SB_HEADERS_FOLDER}/
    ${SB_HEADERS_FOLDER}/Components
    ${SB_HEADERS_FOLDER}/Game
    ${SB_HEADERS_FOLDER}/Scenes)
target_sources(SandBox ${SB_SOURCES})