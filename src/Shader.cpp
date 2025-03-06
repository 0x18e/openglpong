#include "Shader.h"


Shader::Shader() {
	
}

Shader& Shader::Use() {
	glUseProgram(this->ID);
	return *this;
}

void Shader::Compile(const char* vert_code_c, const char* frag_code_c) {



	// now to compile the shaders



	unsigned vertex, fragment;

	int success = 0;
	char infoLog[512];


	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vert_code_c, nullptr);

	glCompileShader(vertex);

	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertex, 512, nullptr, infoLog);
		std::cout << "cant compile vertex shader " << infoLog << '\n';
	}

	fragment = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fragment, 1, &frag_code_c, nullptr);
	glCompileShader(fragment);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertex, 512, nullptr, infoLog);
		std::cout << "cant compile fragment shader " << infoLog << std::endl;
	}


	// create shader program
	ID = glCreateProgram();

	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);

	glGetProgramiv(ID, GL_LINK_STATUS, &success);

	if (!success) {
		std::cout << "COULD NOT LINK SHADER PROGRAM " << infoLog << std::endl;
	}

	glDeleteShader(vertex);
	glDeleteShader(fragment);

}

void Shader::SetBool(const char* name, bool value, bool use_shader) {

	if (use_shader)
		this->Use();
	
	glUniform1i(GetLocation(name), value);
}

void Shader::SetFloat(const char* name, float value, bool use_shader) {
	if (use_shader)
		this->Use();

	glUniform1f(GetLocation(name), value);
}

void Shader::SetMat4(const char* name, glm::mat4 matrix, bool use_shader = false) {
	if (use_shader) this->Use();

	// putting in 1 matrix
	glUniformMatrix4fv(GetLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));

}
