#include "Engine.h"
#include <iostream>
#include "Shader.h"

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
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };

    unsigned int VBO;
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    Shader* sh = new Shader("res/shaders/test.shader");
    sh->Bind();

    while (!glfwWindowShouldClose(Window::window->glfw_window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        sh->Bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);
        sh->UnBind();

        glfwSwapBuffers(Window::window->glfw_window);
        glfwPollEvents();
    }
}

void Engine::cleanup()
{
    glfwTerminate();
}
