#pragma once
#include "stb_image.h"
#include "glad/glad.h"
#include "Utilities.h"

class Texture2D {

	// This holds all the important data a texture needs
	int n_channel;
	int m_nWidth;
	int m_nHeight;
	

public:
	unsigned int texture_id;
	Texture2D();
	~Texture2D();

	void Generate(unsigned int width, unsigned int height, unsigned char* data);

	void Bind() const;


};