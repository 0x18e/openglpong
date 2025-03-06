#pragma once
#include "Utilities.h"
#include <glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/common.hpp>



class WindowManager {

private:
	
	
	int m_nWidth, m_nHeight;
	std::string m_pszWindowTitle;
	GLFWwindow* m_pWindow;

public:
	
	WindowManager();
	~WindowManager();
	void Init();
	GLFWwindow* GetWindow() { return m_pWindow; }
	void SwapBuffers();

};

