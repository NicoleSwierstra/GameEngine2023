cmake_minimum_required(VERSION 3.0.0)
project(GameEngine VERSION 0.1.0)

include(CTest)
enable_testing()

add_compile_definitions(GLEW_STATIC)

add_executable(GameEngine src/main.cpp src/Engine/Engine.cpp src/Engine/Window.cpp src/Engine/Shader.cpp)

set_property(TARGET GameEngine PROPERTY CXX_STANDARD 20)

target_include_directories(GameEngine PUBLIC 
    C:/Users/smart/source/libs/glfw-3.3.6.bin.WIN64/glfw-3.3.6.bin.WIN64/include/
    C:/Users/smart/source/libs/GLEW/include/
    src/
    src/vendor/glm
)
target_link_directories(
    GameEngine
    PUBLIC
    C:/Users/smart/source/libs/glfw-3.3.6.bin.WIN64/glfw-3.3.6.bin.WIN64/lib-vc2022/
    C:/Users/smart/source/libs/GLEW/glew-2.1.0-win32/glew-2.1.0/lib/Release/x64/
)
target_link_libraries(GameEngine glfw3.lib opengl32.lib glew32s.lib)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
