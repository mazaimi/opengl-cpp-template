cmake_minimum_required(VERSION 3.10...3.25)
project(MyProject VERSION 1.0)
add_executable(MyProject src/main.cpp)

set(OpenGL_GL_PREFERENCE "GLVND")

find_package(OpenGL REQUIRED)
target_link_libraries(MyProject PUBLIC OpenGL::GL)

add_subdirectory(libs/MyLib)
add_subdirectory(external/glfw)


target_include_directories(MyProject PUBLIC libs/MyLib external/glfw/include)
target_link_libraries(MyProject PUBLIC MyLib glfw OpenGL::GL)
