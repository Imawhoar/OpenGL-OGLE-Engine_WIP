#pragma once
#include "glad/glad.h"
#include "../Resources/Image.h"

#include <string>

namespace OGLE
{

	class Texture {
	private:
		Image* m_image;
		unsigned int m_textureID{};

	private:
		void InitializeTexture();
	public:
		explicit Texture(Image* image);
		explicit Texture(const std::string& src);

	public:
		void Bind() const;
		Image* GetImage() const;
	};
}