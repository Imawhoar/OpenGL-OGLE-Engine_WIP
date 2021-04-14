#pragma once
#include "glad/glad.h"
#include "Resources/Image.h"

#include <string>

namespace OGLE
{

	class Texture {
	private:
		Image* m_image;
		unsigned int m_textureID{};

	private:
		void InitializeTexture() {

			glGenTextures(1, &m_textureID);
			glBindTexture(GL_TEXTURE_2D, m_textureID);
			// set the texture wrapping parameters
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

			// set texture filtering parameters
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}
	public:
		Texture(Image* image) {
			InitializeTexture();
			m_image = image;
			if (m_image->IsValid()) {
				if (m_image->GetNrChannels() == 4)
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_image->GetWidth(), m_image->GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, m_image->GetData());
				else if (m_image->GetNrChannels() == 3)
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_image->GetWidth(), m_image->GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, m_image->GetData());

				glGenerateMipmap(GL_TEXTURE_2D);
			}
		}
		explicit Texture(const std::string& src) {
			InitializeTexture();
			m_image = new Image(src);

			if (m_image->IsValid()) {
				if (m_image->GetNrChannels() == 4)
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_image->GetWidth(), m_image->GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, m_image->GetData());
				else if (m_image->GetNrChannels() == 3)
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_image->GetWidth(), m_image->GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, m_image->GetData());
				glGenerateMipmap(GL_TEXTURE_2D);
			}
		}

	public:
		void Bind() const {
			glBindTexture(GL_TEXTURE_2D, m_textureID);
		}
		[[nodiscard]] auto* GetImage() const {
			return m_image;
		}
	};
}