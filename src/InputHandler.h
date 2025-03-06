#pragma once
#include "Utilities.h"
#include <GLFW/glfw3.h>
#include <vector>

struct ButtonInputs {
	int up = 0;
	int down= 1;
};

class InputHandler {
private:
	
	static InputHandler m_InputHandler;
	ButtonInputs m_buttonInputs;
	InputHandler() {};
	~InputHandler() {};
public:
	void HandleInput(GLFWwindow* window);
	
	static InputHandler &GetHandler() {
		return m_InputHandler;
	}

};