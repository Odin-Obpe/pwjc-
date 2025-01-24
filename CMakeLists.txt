cmake_minimum_required(VERSION 3.10)
project(MyApp)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(tests)

add_executable(MyApp 
    src/main.cpp
    src/Strategy.cpp
    src/Player.cpp
    src/Game.cpp
    src/inputHandler.cpp
    src/inputParser.cpp
    src/endCondition.cpp
    src/ShowResults.cpp
)