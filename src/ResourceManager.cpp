#include "ResourceManager.h"


std::map<std::string, Shader> ResourceManager::m_Shaders;
std::map<std::string, Texture2D> ResourceManager::m_Textures;

Shader ResourceManager::GetShader(std::string name) {
	return m_Shaders[name];
}
Shader ResourceManager::LoadShader(const char* vert_shader_file, const char* frag_shader_file, std::string name){
	Shader shader = LoadShaderFromFile(vert_shader_file, frag_shader_file);
	m_Shaders[name] = shader;
	return shader;
}

Texture2D ResourceManager::LoadTexture(const char* file_path, bool alpha, std::string name) {
	m_Textures[name] = LoadTextureFromFile(file_path, alpha);
	return m_Textures[name];
}

Texture2D ResourceManager::GetTexture(std::string name) {
	return m_Textures[name];

}

void ResourceManager::Clear() {
	for (auto& shaders: m_Shaders) {
		LOG("Deleting shaders");
		glDeleteProgram(shaders.second.ID);
	}
	for (auto& textures : m_Textures) {
		LOG("Deleting textures");
		glDeleteTextures(1, &textures.second.texture_id);
	}
}

Shader ResourceManager::LoadShaderFromFile(const char* vert_shader_path, const char* frag_shader_path) {

	// Create ifstream objects to read file path
	std::string vertex_code;
	std::string fragment_code;
	std::ifstream vertex_shader_file;
	std::ifstream frag_shader_file;



	vertex_shader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	frag_shader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);


	try {
		vertex_shader_file.open(vert_shader_path);
		frag_shader_file.open(frag_shader_path);

		std::stringstream vertex_stream, frag_stream;
		vertex_stream << vertex_shader_file.rdbuf();
		frag_stream << frag_shader_file.rdbuf();
		vertex_shader_file.close();
		frag_shader_file.close();

		vertex_code = vertex_stream.str();
		fragment_code = frag_stream.str();
	}
	catch (std::ifstream::failure e) {
		std::cout << "SHADER FILE NOT SUCCESSFULLY READ\n";
	}
	const char* vert_code_c = vertex_code.c_str();
	const char* frag_code_c = fragment_code.c_str();

	Shader shader;
	shader.Compile(vert_code_c, frag_code_c);

	LOG("Shader successfully loaded");
	return shader;
}

Texture2D ResourceManager::LoadTextureFromFile(const char* file_path, bool alpha) {
	Texture2D texture;

	int width, height, nr_channels;
	unsigned char* data = stbi_load(file_path, &width, &height,
		&nr_channels, 0
	);

	texture.Generate(width, height, data);


	stbi_image_free(data); // free the data
	LOG("Loaded texture");
	return texture;
}
