//Window class

// Pointer to glfw window
// init and cleanup functions
// Functionality for graphics settings

#pragma once
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace _Window_Definitions {
	static enum Window_Mode {
		FULLSCREEN,
		BORDERLESS,
		WINDOWED,
	};

	//defined as width,height in arrays 
	static unsigned int typical_resolutions[10][2] = {
		{ 1024,  720 }, //  3:4
		{ 1280,  720 }, // 16:9
		{ 1440, 1080 }, //  3:4
		{ 1920, 1080 }, // 16:9
		{ 2560, 1080 }, // 21:9
		{ 1920, 1440 }, //  3:4
		{ 2560, 1440 }, // 16:9
		{ 3440, 1440 }, // 21:9
		{ 3840, 2160 }, // 16:9
		{    0,    0 }  // native resolution; set in window constructor
	};
}

class Window {
private:
	Window(std::string name, int window_width, int window_height, std::string iconpath);
public:
	//singleton reference
	static Window* window;
	
	//window parameters for the OS/GLFW
	GLFWwindow* glfw_window;
	std::string window_name; //name as it appears to the OS
	int window_width, window_height; // width and height of window in pixels
	
	//graphics parameters
	_Window_Definitions::Window_Mode window_mode; // fullscreen/windowed/borderless
	int frame_width, frame_height, resolution_index; //pixels it's rendering to before window scaling
	double frame_aspect; //aspect ratio

	//can't construct
	Window() = delete;
	
	//method for creating window
	static Window* Create(std::string name, int window_width = 0, int window_height = 0, std::string iconpath = "");
};