cmake_minimum_required(VERSION 3.31)
project(FirstSFMLGame)

set(CMAKE_CXX_STANDARD 26)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.1
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main src/main.cpp
        src/Game.cpp
        src/Game.h
        src/Player.cpp
        src/Player.h
        src/Enemy.cpp
        src/Enemy.h
        src/Timer.cpp
        src/Timer.h
        src/EnemyManager.cpp
        src/EnemyManager.h
        src/Scenes/GameScene.cpp
        src/Scenes/GameScene.h
)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)