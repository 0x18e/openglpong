#include "InputHandler.h"

void InputHandler::HandleInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true); // say that the window can get closed
	}
}

InputHandler InputHandler::m_InputHandler;
