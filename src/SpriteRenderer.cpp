#include "SpriteRenderer.h"

void SpriteRenderer::InitRenderData() {

	unsigned int VBO;
	float vertices[] = {
		// positions // texture coordinates
		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f , 0.0f, 0.0f,

		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f
	};
	glGenVertexArrays(1, &this->quadvao);
	glGenBuffers(1, &VBO);
	
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0); // this is for the positions
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1); // layout location texcoords
	glBindVertexArray(0);

}

void SpriteRenderer::DrawSprite(Texture2D& texture, glm::vec2 pos, glm::vec2 size,
	float rotation, glm::vec3 color) {
	
	shader.Use(); // Use our current shader for this sprite

	// Create the model
	glm::mat4 model = glm::mat4(1.0f);

	// translate the model to its position
	model = glm::translate(model, glm::vec3(0.5 * size.x, 0.5 * size.y, 0.0f));
	model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 0.0, 1.0f)); // This rotates the sprite
	// about the z axis which is jut around the center really
	model = glm::translate(model, glm::vec3(-0.5 * size.x, -0.5 * size.y, 0.0f));


	model = glm::scale(model, glm::vec3(size, 1.0f));

	



}


