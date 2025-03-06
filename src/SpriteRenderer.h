#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "ResourceManager.h"
// purpose: Handles creating one single sprite, and it renders that sprite itself.
class SpriteRenderer {
public:
	SpriteRenderer(Shader& shader);
	~SpriteRenderer();

	void DrawSprite(Texture2D& texture, glm::vec2 pos, glm::vec2 size = glm::vec2(10.0f, 0.0f),
		float rotation = 0.0f, glm::vec3 color = glm::vec3(1.0f));

private:
	Shader shader;
	unsigned int quadvao; // TODO: What is this? I think its supposed to be the vao object that this sprite holds

	void InitRenderData();



};
