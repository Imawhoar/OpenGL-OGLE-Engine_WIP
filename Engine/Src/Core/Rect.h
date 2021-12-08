#pragma once

#include "OEPCH.h"
#include "Tools/FileHandler.h"
#include "Utils/Vector.h"

#define VECTORSIZE(count, type) count * sizeof(type) 

namespace OGLE
{
	class Texture;
	struct VertexData {
		// position
		Vector3 position;
		// color
		Vector4 color;
		// texCoords
		Vector2 texChoord;
	};
	struct Mesh
	{
		std::vector<VertexData> data;
		//TODO: The engine will only render rects. Remove indices once this is implemented since its not actually necessary for any object
		std::vector<uint32> indices;

		uint32 m_vbo;
		uint32 m_ebo;
		uint32 m_vao;

		Mesh() : m_vbo(0), m_ebo(0), m_vao(0) {}

		void Initialize(float width, float height);

		void Bind() const;
	};

	class Rect {

	private:

		//TODO: Need to make all of this component based with entt-library or something.
		//It's not a good idea to have raw pointers like this
		RefPtr<Texture> m_texture{};
		Mesh m_mesh;

		Rect() = default;

	public:

		void SetTexture(Texture* texture);

		void Bind() const;

	public:
		static Rect Create();

		static Rect Create(Texture* texture);
	};
}