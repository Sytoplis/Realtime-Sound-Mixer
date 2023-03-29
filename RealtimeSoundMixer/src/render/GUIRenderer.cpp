#include "GUIRenderer.h"

GUIRenderer::GUIRenderer(GLFWwindow* window) : io_ptr(nullptr) {
	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	io_ptr = &ImGui::GetIO();


	io_ptr->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
	io_ptr->ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
	io_ptr->ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows


	// Setup Dear ImGui style
	ImGui::StyleColorsDark();

	//NOTE: leftout some stuff

	// Setup Platform/Renderer backends
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);
}

GUIRenderer::~GUIRenderer() {
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}


void GUIRenderer::Draw() {
	{
		ImGui::Begin("Parameters");                          // Create a window called "Parameters" and append into it.
		ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too
		float stackFloat = 0.5f;
		ImGui::SliderFloat("Slider", &stackFloat, 0.0f, 1.0f, "%.5f");
		ImGui::Spacing();

		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		ImGui::End();
	}
}

void GUIRenderer::Render() {
	if (io_ptr == nullptr) {
		std::cerr << "ERROR: GUIRenderer has not been initialized properly before calling Render" << std::endl;
		return;
	}

	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	Draw();

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	
	// Update and Render additional Platform Windows
	// (Platform functions may change the current OpenGL context, so we save/restore it to make it easier to paste this code elsewhere.
	//  For this specific demo app we could also call glfwMakeContextCurrent(window) directly)
	if (io_ptr->ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		GLFWwindow* backup_current_context = glfwGetCurrentContext();
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
		glfwMakeContextCurrent(backup_current_context);
	}
}