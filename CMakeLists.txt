cmake_minimum_required(VERSION 3.5)
project(MyProject VERSION 1.0)
add_executable(MyProject src/main.cpp)

add_subdirectory(libs/MyLib)

target_include_directories(MyProject PUBLIC libs/MyLib)
target_link_libraries(MyProject PUBLIC MyLib)
