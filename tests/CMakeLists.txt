include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.4.0 # Replace with the required version
)
FetchContent_MakeAvailable(Catch2)

# target_link_libraries(your_test_target PRIVATE Catch2::Catch2WithMain)

include_directories(${PROJECT_SOURCE_DIR}/include)

# list(APPEND CMAKE_PREFIX_PATH $ENV{CATCH2_PATH})

# find_package(Catch2 3 REQUIRED)

add_executable(tests 
    tests.cpp
    ${PROJECT_SOURCE_DIR}/src/Strategy.cpp
    ${PROJECT_SOURCE_DIR}/src/Player.cpp
)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)