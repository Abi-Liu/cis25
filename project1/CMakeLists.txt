cmake_minimum_required(VERSION 3.30)
project(project)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(main main.cpp utils/person.cpp utils/phonebook.cpp)