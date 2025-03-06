#pragma once
#include "Utilities.h"
#include <glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/common.hpp>

#include "WindowManager.h"
#include "InputHandler.h"
#include "ResourceManager.h"



class App {

public:
	
	int InitGL(void);
	WindowManager m_Window;
	// Base window handler

	// Some shader functionality
	// our shader class would be here


public:
	void Run(void);


};