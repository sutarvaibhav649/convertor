cmake_minimum_required(VERSION 3.22)

project(
    convertor
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

# 1. Static Library (core application logic, NO main.cpp)
add_library(${PROJECT_NAME} STATIC
    src/cli/command_handler.cpp
    src/category/category_type.cpp
    src/category/unit_parser.cpp
    src/convertor/unit_convertor.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC include)

# 2. Executable Target
add_executable(convertor_cli
    src/main.cpp
)

# 3. Link library to executable (inherits include directories automatically via PUBLIC)
target_link_libraries(convertor_cli PRIVATE ${PROJECT_NAME})


# ==============================================================================
# 3. Testing Setup (GoogleTest via FetchContent)
# ==============================================================================
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# For Windows MSVC runtime compatibility
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Create Test Executable
add_executable(unit_tests
    tests/test_unit_convertor.cpp
    tests/test_unit_parser.cpp
)

# Link your core library and GoogleTest
target_link_libraries(unit_tests PRIVATE ${PROJECT_NAME} gtest_main)

# Register with CTest
include(GoogleTest)
gtest_discover_tests(unit_tests)