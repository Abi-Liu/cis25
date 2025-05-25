cmake_minimum_required(VERSION 3.20)
project(Project3 VERSION 1.0 LANGUAGES CXX)

# ----------- Global Build Settings ------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ----------- Include Directories -------------
include_directories(${PROJECT_SOURCE_DIR}/include)

# ----------- Main Executable -----------------
add_executable(main
        src/main.cpp
        src/utils/person.cpp
        src/utils/phonebook.cpp
        src/utils/repl.cpp
)

# ----------- GoogleTest Setup ----------------
include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# ----------- Test Executable -----------------
add_executable(tests
        tests/person_test.cpp
        tests/phonebook_test.cpp
        tests/repl_test.cpp
        src/utils/person.cpp
        src/utils/phonebook.cpp
        src/utils/repl.cpp
)

target_include_directories(tests PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(tests
        gtest
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)
