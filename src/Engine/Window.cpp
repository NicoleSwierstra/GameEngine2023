#include "Window.h"
#include <iostream>

Window* Window::window;

Window::Window(std::string name, int window_width, int window_height, std::string iconpath)
{
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);

    glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

    window_name = name;

    //checks if not 0
    if (window_width && window_height) {
        this->window_width = window_width;
        this->window_height = window_height;
    }
    else {
        this->window_width = mode->width;
        this->window_height = mode->height;
    }

    _Window_Definitions::typical_resolutions[9][0] = this->window_width;
    _Window_Definitions::typical_resolutions[9][1] = this->window_height;

    frame_aspect = this->window_width / this->window_height;

    glfw_window = glfwCreateWindow(this->window_width, this->window_height, window_name.c_str(), NULL, NULL);

    // TODO: STBI IMAGE LIBRARY LOAD ICON
    if (iconpath.length() > 1) {
        //glfwSetWindowIcon(glfw_window, 1, new)
    }

    glfwMakeContextCurrent(glfw_window);
}

Window* Window::Create(std::string name, int window_width, int window_height, std::string iconpath)
{
    if (window != nullptr)
        return window;
        
    window = new Window(name, window_width, window_height, iconpath);
    
    if (!window->glfw_window)
    {
        std::cout << "GLFW WINDOW FAILED TO CREATE" << std::endl;
        delete window;
        glfwTerminate();
        return nullptr;
    }

    return window;
}