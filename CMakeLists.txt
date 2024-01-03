cmake_minimum_required(VERSION 3.14)

project(connect4 VERSION 1.0.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
include_directories("${PROJECT_BINARY_DIR}/include")
add_subdirectory(include)
add_subdirectory(src)
add_executable(connect4 main.cpp)
target_link_libraries(connect4 connect4_lib)

install(TARGETS connect4 DESTINATION "${CMAKE_CURRENT_LIST_DIR}/bin")
