#pragma once

#include <glad/glad.h> // include glad to get the required OpenGL headers
#include<glm/common.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


#include "Utilities.h"


class Shader {
public:

	// Programs ID
	unsigned int ID;
	
	Shader();

	// Use this shader program
	Shader& Use();
	
	void Compile(const char* vert_code_c, const char* frag_code_c);
	
	// Declare our shader value changing functions
	void SetBool(const char* name, bool value, bool use_shader = false);
	void SetInt(const char* name, int value, bool use_shader = false);
	void SetFloat(const char* name, float value, bool use_shader = false);
	void SetVector2f(const char* name, const glm::vec2 &vector, bool use_shader = false);
	void SetVector3f(const char* name, const glm::vec3 &vector, bool use_shader = false);
	void SetMat4(const char* name, glm::mat4 matrix, bool use_shader = false);
	
	// Function to just get memory addresses of shader vars
	GLint GetLocation(const char* name) { return glGetUniformLocation(this->ID, name); }


};