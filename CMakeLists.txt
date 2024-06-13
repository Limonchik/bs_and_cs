cmake_minimum_required(VERSION 3.20)

project(BullsAndCows)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include)

# Add the external doctest library
add_subdirectory(external/doctest)

# Add main project sources
add_subdirectory(src)

# Add the executable
add_executable(BullsAndCows src/main.cpp)
target_link_libraries(BullsAndCows BullsAndCowsLib)

# Add the tests
enable_testing()
add_subdirectory(tests)
