#pragma once

#include <iostream>

#include "vendor\imgui\imgui.h"
#include "vendor\imgui\imgui_impl_glfw.h"
#include "vendor\imgui\imgui_impl_opengl3.h"

#include "GLFW/glfw3.h"

class GUIRenderer {
public:
	const char* const glsl_version = "#version 130";
private:
	ImGuiIO* io_ptr;

public:
	GUIRenderer(GLFWwindow* window);
	~GUIRenderer();

	void Draw();
	void Render();
};