#pragma once

#include <vector>
#include "Texture.h"
#include "Resources/Shader.h"
namespace OGLE
{
	class Sprite {
		typedef std::vector<Texture*> TextureList;

	private:

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
		Sprite(Texture* texture, Shader* shader) : m_vbo(0), m_vao(0), m_ebo(0) {

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

			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), static_cast<void*>(nullptr));
			glEnableVertexAttribArray(0);

			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), reinterpret_cast<void*>(3 * sizeof(float)));
			glEnableVertexAttribArray(1);

			glBindVertexArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		}

	public:

		[[nodiscard]] const auto* GetShader() const { return m_shader; }


		void SetShader(Shader* shader) { m_shader = shader; }

		void RemoveTexture(Texture* texture)
		{
			if (m_textures.size() > 1)
				m_textures.erase(std::remove(m_textures.begin(), m_textures.end(), texture), m_textures.end());
		}
		void AddTexture(Texture* texture) {
			if (m_textures.size() < 6)
				m_textures.push_back(texture);
		}

		void Bind() {

			for (int i = 0; i < m_textures.size(); ++i) {
				glActiveTexture(GL_TEXTURE0 + i);
				m_textures[i]->Bind();
			}
			glBindVertexArray(m_vao);
		}
		void Draw() {
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
		}

	};
}