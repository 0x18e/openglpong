#include "App.h"


int App::InitGL() {

	if (!glfwInit()) {
		LOG("Could not initialize glfw");
		return -1;
	}

	// Specify window hints
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_Window.Init();
	glfwMakeContextCurrent(m_Window.GetWindow());
	// now we need to load the opengl function
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		LOG("Could not load glad functions");
		return -1;
	}

}

void App::Run() {
	

	this->InitGL();



	while (!glfwWindowShouldClose(m_Window.GetWindow())) {
	
		InputHandler::GetHandler().HandleInput(m_Window.GetWindow());

		glfwPollEvents();
		m_Window.SwapBuffers();
	}
	ResourceManager::Clear();
	
}
