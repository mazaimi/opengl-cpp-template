add_library(tigl STATIC
    tigl.cpp)

target_include_directories(tigl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(tigl PRIVATE
    GLEW::GLEW
    OpenGL::GL
    glm::glm
)
