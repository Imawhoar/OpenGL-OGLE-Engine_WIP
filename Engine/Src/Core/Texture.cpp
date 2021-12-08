#include "OEPCH.h"
#include "Texture.h"

#include "Resources/Image.h"

namespace OGLE
{
	Texture::Texture() : m_isInitialized(false), m_textureBufferId(-1)
	{
	}

	Texture::Texture(Image* image) : m_imageData(image), m_isInitialized(false)
	{
		InitTexture();
	}

	Texture::Texture(const std::string& src) : m_imageData(new Image(src))
	{
		InitTexture();
	}

	void Texture::AttachImage(Image* img)
	{
		if (img)
			m_imageData = img;
		else
			std::cout << "Image does not exist or is null!\n";
	}

	void Texture::InitTexture()
	{
		glGenTextures(1, &m_textureBufferId);
		glBindTexture(GL_TEXTURE_2D, m_textureBufferId);

		// set the texture wrapping parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		// set texture wrapping to GL_REPEAT (default wrapping method)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		// set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		if (m_imageData->IsValid())
		{
			if (m_imageData->GetNrChannels() == 4)
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_imageData->GetWidth(), m_imageData->GetHeight(), 0, GL_RGBA,
					GL_UNSIGNED_BYTE, m_imageData->GetData());
			else if (m_imageData->GetNrChannels() == 3)
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_imageData->GetWidth(), m_imageData->GetHeight(), 0, GL_RGB,
					GL_UNSIGNED_BYTE, m_imageData->GetData());

			glGenerateMipmap(GL_TEXTURE_2D);

			m_isInitialized = true;
		}
	}

	void Texture::Bind() const
	{
		glBindTexture(GL_TEXTURE_2D, m_textureBufferId);
	}

	void Texture::Unbind() const
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	auto* Texture::GetImage() const
	{
		return m_imageData;
	}

	bool Texture::GetIsInitialized() const
	{
		return this->m_isInitialized;
	}
}
