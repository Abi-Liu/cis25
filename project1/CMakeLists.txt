cmake_minimum_required(VERSION 3.30)
project(project)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(main src/main.cpp src/person.cpp src/phonebook.cpp)


# ---------- Google Test Setup ----------
include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

# Prevent GoogleTest from overriding compiler/linker flags
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

# Add test executable
add_executable(tests
        test/person_test.cpp
        test/phonebook_test.cpp
        test/pr_test.cpp
        src/person.cpp
        src/phonebook.cpp
)

target_link_libraries(
        tests
        gtest
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)