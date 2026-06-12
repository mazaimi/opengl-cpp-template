# cmake_minimum_required(VERSION 3.10...3.25)
# project(MyProject VERSION 1.0 LANGUAGES CXX)

# set(OpenGL_GL_PREFERENCE "GLVND")
# find_package(OpenGL REQUIRED)
# find_package(GLEW REQUIRED)
# find_package(glm REQUIRED)

# add_subdirectory(libs/MyLib)
# add_subdirectory(libs/tigl)
# add_subdirectory(external/glfw)
# add_subdirectory(external/imgui)

# add_executable(${PROJECT_NAME} src/main.cpp)

# target_include_directories(${PROJECT_NAME} PRIVATE
#     libs/MyLib
#     external/glfw/include
#     external/imgui
# )

# target_link_libraries(${PROJECT_NAME} PRIVATE
#     MyLib
#     tigl
#     glfw
#     imgui
#     GLEW::GLEW
#     OpenGL::GL
#     glm::glm
# )


cmake_minimum_required(VERSION 3.10...3.25)
project(MyProject VERSION 1.0 LANGUAGES CXX)

set(OpenGL_GL_PREFERENCE "GLVND")
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED)

add_subdirectory(libs/MyLib)
add_subdirectory(libs/tigl)
add_subdirectory(external/glfw)

add_library(imgui STATIC
    external/imgui/imgui.cpp
    external/imgui/imgui_demo.cpp
    external/imgui/imgui_draw.cpp
    external/imgui/imgui_tables.cpp
    external/imgui/imgui_widgets.cpp

    # Add the backends you are using (GLFW and OpenGL3)
    external/imgui/backends/imgui_impl_glfw.cpp
    external/imgui/backends/imgui_impl_opengl3.cpp
)


target_include_directories(imgui PUBLIC
    external/imgui
    external/imgui/backends
)

# ImGui backends need to know about GLFW and OpenGL to compile
target_link_libraries(imgui PRIVATE
    glfw
    OpenGL::GL
    GLEW::GLEW
)

add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE
    libs/MyLib
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    MyLib
    tigl
    imgui
    glfw
    GLEW::GLEW
    OpenGL::GL
    glm::glm
)
