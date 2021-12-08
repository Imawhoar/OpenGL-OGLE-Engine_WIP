#include "Rect.h"
#include "Texture.h"

namespace OGLE
{
	void Mesh::Initialize(float width, float height)
	{
		float ratio = width / height;

		VertexData v1{};
		v1.position = { 1 * ratio,1,0 };
		v1.texChoord = { 1, 1 };
		v1.color = { 1,1,1,1 };

		VertexData v2{};
		v2.position = { 1 * ratio,-1,0 };
		v2.texChoord = { 1, 0 };
		v2.color = { 1,1,1,1 };

		VertexData v3{};
		v3.position = { -1 * ratio,-1,0 };
		v3.texChoord = { 0, 0 };
		v3.color = { 1,1,1,1 };

		VertexData v4{};
		v4.position = { -1 * ratio,1,0 };
		v4.texChoord = { 0, 1 };
		v4.color = { 1,1,1,1 };

		std::vector<VertexData> vertices = { v1, v2, v3, v4 };
		std::vector<uint32> indices = {
			0, 1, 3,
			1, 2, 3
		};

		this->data = vertices;
		this->indices = indices;

		glCreateBuffers(1, &m_vbo);
		glCreateVertexArrays(1, &m_vao);

		glBindVertexArray(m_vao);

		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
		glBufferData(GL_ARRAY_BUFFER, VECTORSIZE(data.size(), VertexData), &data[0], GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, VECTORSIZE(indices.size(), uint32), &indices[0], GL_STATIC_DRAW);

		// vertex Positions
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)0);

		// vertex color
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)offsetof(VertexData, color));

		// vertex texture coords
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)offsetof(VertexData, texChoord));

		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	void Mesh::Bind() const
	{
		glBindVertexArray(m_vao);
	}

	void Rect::SetTexture(Texture* texture)
	{
		if (texture) {
			m_texture = RefPtr<Texture>(texture);
		}
	}


	void Rect::Bind() const
	{
		glActiveTexture(GL_TEXTURE0);
		m_texture->Bind();
		m_mesh.Bind();
	}

	Rect Rect::Create()
	{
		Rect rect;
		//THIS IS NOT HOW WE SHOULD CREATE NEW TEXTURES
		//TODO: NEED TO MAKE A PROPER ASSETSHANDLER
		rect.m_texture = std::make_shared<Texture>(FileHandler::GetResourcePath("square.png"));
		return rect;
	}

	Rect Rect::Create(Texture* texture)
	{
		Rect rect;
		rect.m_texture = RefPtr<Texture>(texture);

		return rect;
	}
}
