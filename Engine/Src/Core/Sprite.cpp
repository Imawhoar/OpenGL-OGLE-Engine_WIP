#include "../Resources/Image.h"
#include "../Resources/Shader.h"
#include "Texture.h"
#include "Sprite.h"
#include "glad/glad.h"

#include "algorithm"
#include "Application.h"

Sprite::Sprite(Texture* texture, Shader* shader) {


	if (texture)
		m_textures.push_back(texture);

	if (shader)
		m_shader = shader;


	glGenBuffers(1, &m_vbo);
	glGenBuffers(1, &m_ebo);
	glGenVertexArrays(1, &m_vao);

	glBindVertexArray(m_vao);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * m_vertices.size(), &m_vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * m_indicies.size(), &m_indicies[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}

void Sprite::SetShader(Shader* shader) {
	m_shader = shader;
}

void Sprite::AddTexture(Texture* texture) {
	if (m_textures.size() < 6)
		m_textures.push_back(texture);
}
void Sprite::RemoveTexture(Texture* texture) {
	if (m_textures.size() > 1)
		m_textures.erase(std::remove(m_textures.begin(), m_textures.end(), texture), m_textures.end());
}

const Transform& Sprite::GetTransform() const {
	return m_transform;
}

Transform& Sprite::GetTransform() {
	return m_transform;
}

const Shader* Sprite::GetShader() const {
	return m_shader;
}

Shader* Sprite::GetShader() {
	return m_shader;
}

void Sprite::bind() {

	for (int i = 0; i < m_textures.size(); ++i) {
		glActiveTexture(GL_TEXTURE0 + i);
		m_textures[i]->Bind();
	}
	glBindVertexArray(m_vao);
}

void Sprite::draw() {
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}