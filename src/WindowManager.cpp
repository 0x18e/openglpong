#include "WindowManager.h"



WindowManager::WindowManager() {
}


WindowManager::~WindowManager() {
	glfwDestroyWindow(this->m_pWindow);
	LOG("Destroyed window");
}
void Frame_Buffersize_Callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);

}

void WindowManager::Init() {

	// Create the window
	// Assume opengl is already initialized with glfw
	this->m_nWidth = 800;
	this->m_nHeight = 600;
	this->m_pszWindowTitle = "Pong";
	this->m_pWindow = glfwCreateWindow(m_nWidth, m_nHeight, m_pszWindowTitle.c_str(), nullptr, nullptr);
	
	glfwSetFramebufferSizeCallback(this->m_pWindow, Frame_Buffersize_Callback);
}

void WindowManager::SwapBuffers() {
	glfwSwapBuffers(this->m_pWindow);
}


