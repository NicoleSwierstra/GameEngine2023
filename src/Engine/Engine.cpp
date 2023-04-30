#include "Engine.h"
#include <iostream>
#include "Shader.h"
#include "Mesh.h"
#include <vector>
#include "gtc/matrix_transform.hpp"
#include "gtx/euler_angles.hpp"

int Engine::run(){
    if(!init()) return -1;
    program();
    cleanup();
    return 0;
}

int Engine::init()
{
    /* Initialize the library */
    if (!glfwInit())
        return 0;

    Window::Create("New window");

    if (glewInit() != GLEW_OK) {
        std::cout << "GLEW error" << std::endl;
        return 0;
    }

    return 1;
}

void Engine::program()
{
    std::vector<glm::vec3> buffer = {
        glm::vec3(-1.0f, -1.0f, -1.0f),
        glm::vec3(-1.0f, -1.0f,  1.0f),
        glm::vec3( 1.0f, -1.0f,  1.0f),
        glm::vec3( 1.0f, -1.0f, -1.0f),
        glm::vec3( 0.0f,  0.7f,  0.0f)
    };
    std::vector<glm::vec2> texCoords = {
        glm::vec2(0.0f, 0.0f),
        glm::vec2(0.0f, 1.0f),
        glm::vec2(1.0f, 0.0f),
        glm::vec2(1.0f, 1.0f),
        glm::vec2(0.5f, 0.5f),
    };
    std::vector<unsigned int> ebo = {
        0, 1, 2,
        1, 3, 2,
        0, 1, 4,
        1, 2, 4,
        2, 3, 4,
        3, 0, 4
    };

    glm::mat4 proj = glm::perspective(glm::radians(90.0f), (float)16/(float)9, 0.1f, 100.0f);
    glm::mat4 view = glm::rotate(glm::mat4(1.0f), 0.4f, glm::vec3(1.0f, 0.0f, 0.0f));
    view = glm::translate(view, glm::vec3(0.0f, -2.0f, -4.0f));
    glm::mat4 trans = glm::eulerAngleYXZ(0.0f, 0.0f, 0.0f);

    Mesh* m = new Mesh(buffer, ebo, texCoords);
    Shader* sh = new Shader("res/shaders/test2.shader");
    m->AddShader(sh, &proj, &view, { {"trans", &trans, UNIFORM_MAT4} }, 0, GL_TRIANGLES, false);

    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(Window::window->glfw_window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        const float h = glfwGetTime() * 10.0f;
        trans = glm::eulerAngleYXZ(h, 0.0f, 0.0f);
        m->Render();

        glfwSwapBuffers(Window::window->glfw_window);
        glfwPollEvents();
    }
}

void Engine::cleanup()
{
    glfwTerminate();
}
