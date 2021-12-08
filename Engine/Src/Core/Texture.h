#pragma once
#include <string>
#include "Texture.h"

namespace OGLE
{

	class Image;
	class Texture {
	private:
		Image* m_imageData{};
		bool m_isInitialized = false;
		unsigned int m_textureBufferId{};

	public:

		Texture();

		Texture(Image* image);

		Texture(const std::string& src);

		void AttachImage(Image* img);

		void InitTexture();
	public:
		void Bind() const;

		void Unbind() const;

		[[nodiscard]] auto* GetImage() const;

		[[nodiscard]] bool GetIsInitialized() const;
	};


}
