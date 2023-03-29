#include "Window.h"

static void glfw_error_callback(int error, const char* description)
{
	fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}


Window::Window(const int width, const int height, const char* title) : window(nullptr), /*renderer(nullptr),*/ guiRenderer(nullptr), display_w(width), display_h(height) {
	// Setup window
	glfwSetErrorCallback(glfw_error_callback);
	if (!glfwInit()) {
		std::cerr << "ERROR: glfw could not be initialized; " << __LINE__ << std::endl;
		return;
	}

	// GL 3.0
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);


	// Create window with graphics context
	window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (window == NULL) {
		std::cerr << "ERROR: window could not be created; " << __LINE__ << std::endl;
		return;
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // Enable vsync

	//Creating ojs on heap because the initialization needs to be after Window and the destruction needs to be before Window
	//NOTE: on the stack the creation is before window and the destruction is after window
	
	//renderer = new Renderer(vertCount, vecSize);
	guiRenderer = new GUIRenderer(window);
}

Window::~Window() {
	//delete renderer;
	delete guiRenderer;

	glfwDestroyWindow(window);
	glfwTerminate();
}



void Window::mainLoop(void (*onUpdate)()) {
	// Main loop
	while (!glfwWindowShouldClose(window))
	{
		// Poll and handle events (inputs, window resize, etc.)
		// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
		// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
		// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
		// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
		glfwPollEvents();

		int old_w = display_w, old_h = display_h;
		glfwGetFramebufferSize(window, &display_w, &display_h);
		//if (old_w != display_w || old_h != display_h)
			//=> on size change

		onUpdate();

		clear();
		//renderer->Render(display_w, display_h, vPos);
		guiRenderer->Render();
		
		glfwSwapBuffers(window);
	}
}

void Window::clear() const {
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}