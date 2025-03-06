#include "Texture2D.h"
#include "stb_image.h"
#include "Shader.h"
#include "Utilities.h"
#include <map>
class ResourceManager {

private:
	static std::map<std::string, Shader> m_Shaders;
	static std::map<std::string, Texture2D> m_Textures;

public:



	// all functions are static


	static Shader LoadShader(const char* vert_shader_file, const char* frag_shader_file, std::string name);
	static Shader GetShader(std::string name);
	
	static Texture2D LoadTexture(const char* file_path, bool alpha, std::string name);
	static Texture2D GetTexture(std::string name);

	static void Clear();

private:
	static Shader LoadShaderFromFile(const char* vert_shader_file, const char* frag_shader_file);
	static Texture2D LoadTextureFromFile(const char* file_path, bool alpha);
};