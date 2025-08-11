cmake_minimum_required(VERSION 3.31)
project(FirstSFMLGame)

set(CMAKE_CXX_STANDARD 26)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(SFML)

add_executable(main WIN32 src/main.cpp
        src/Game.cpp
        src/Game.h
        src/Player.cpp
        src/Player.h
        src/Enemy.cpp
        src/Enemy.h
        src/Timer.cpp
        src/Timer.h
        src/GameScene.cpp
        src/GameScene.h
        src/GameOverScene.cpp
        src/GameOverScene.h
        src/BlinkingText.cpp
        src/BlinkingText.h
        src/HPText.cpp
        src/HPText.h
        src/Heart.cpp
        src/Heart.h
)


file(COPY assets DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)