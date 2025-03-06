#include "Texture2D.h"

Texture2D::Texture2D() {
	LOG("Creating texture");

	glGenTextures(1, &this->texture_id); // Create our texture


}

Texture2D::~Texture2D() {
	glDeleteTextures(1, &this->texture_id);
}

void Texture2D::Generate(unsigned int width, unsigned int height,unsigned char * data) {
	
}

void Texture2D::Bind() const {
	glBindTexture(GL_TEXTURE_2D, this->texture_id); // bind the current texture to be the texture that gets drawn
}
