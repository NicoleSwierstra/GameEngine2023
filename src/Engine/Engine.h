#pragma once

#include "Window.h"

//singleton engine class
class Engine {
public:
	static int run();
private:
	static int init();
	static void program();
	static void cleanup();
};