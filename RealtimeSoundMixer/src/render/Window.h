#pragma once

#include <iostream>

//the graphics includes
#include <GL/glew.h>
#include "GLDebug.h"

#include "GUIRenderer.h"

#include "GLFW/glfw3.h" // Will drag system OpenGL headers

class Window {
public:
	GLFWwindow* window;
	GUIRenderer* guiRenderer;
	int display_w, display_h;

public:
	Window(const int width, const int height, const char* title);
	~Window();
	void mainLoop(void (*onUpdate)());
	void clear() const;
};
