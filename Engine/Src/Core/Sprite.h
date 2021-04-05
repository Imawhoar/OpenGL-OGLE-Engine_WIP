#pragma once

#include <vector>
#include "Transform.h"


class Texture;
class Shader;


class Sprite {
	typedef std::vector<Texture*> TextureList;
private:

	Transform m_transform;
	TextureList m_textures;
	Shader* m_shader;

	unsigned int m_vbo;
	unsigned int m_ebo;
	unsigned int m_vao;


	std::vector<float> m_vertices{
			 1.0f,  1.0f, 0.0f,   1.0f, 1.0f, // top right
			 1.0f, -1.0f, 0.0f,   1.0f, 0.0f, // bottom right
			-1.0f, -1.0f, 0.0f,   0.0f, 0.0f, // bottom left
			-1.0f,  1.0f, 0.0f,   0.0f, 1.0f  // top left
	};
	std::vector<unsigned int> m_indicies{
			0, 1, 3, // first triangle
			1, 2, 3  // second triangle
	};

public:
	Sprite(Texture* texture, Shader* shader);

public:

	const Transform& GetTransform() const;
	Transform& GetTransform();

	void SetShader(Shader* shader);
	const Shader* GetShader() const;
	Shader* GetShader();

	void RemoveTexture(Texture* shader);
	void AddTexture(Texture* texture);

	void bind();
	void draw();

};