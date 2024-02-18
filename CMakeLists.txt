cmake_minimum_required(VERSION 3.14)

project(connectX VERSION 1.0.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
include_directories("${PROJECT_BINARY_DIR}/include")
add_subdirectory(include)
add_subdirectory(src)
add_executable(connectX app/main.cpp)
target_link_libraries(connectX connectX_lib)

install(TARGETS connectX DESTINATION "${CMAKE_CURRENT_LIST_DIR}/bin")
