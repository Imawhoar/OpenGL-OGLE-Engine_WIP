#pragma once
#define STB_IMAGE_IMPLEMENTATION

#include "Resource.h"
#include <string>
#include <stb/stb_image.h>

namespace OGLE
{
	class Image : public Resources::Resource {
	private:

		unsigned char* m_data = nullptr;
		int m_width{}, m_height{}, m_nrChannels{};
		float m_ratio{};
	public:
		Image() = default;
		Image(const std::string& src) {
			if (!LoadImage(src))
				std::cout << "[ERROR -> Image] could not load image!";

			m_ratio = static_cast<float>(m_width) / m_height;
		}
		explicit Image(const char* src) {
			if (!LoadImage(src))
				std::cout << "[ERROR -> Image] could not load image!";

			m_ratio = static_cast<float>(m_width) / m_height;
		}
	public:
		bool LoadImage(const std::string& src) {
			stbi_set_flip_vertically_on_load(true);
			m_data = stbi_load(src.c_str(), &m_width, &m_height, &m_nrChannels, 0);
			return m_data;
		}
		
		[[nodiscard]] bool IsValid() const {
			if (m_data)
				return true;
			return false;
		}
		
		[[nodiscard]] auto*GetData() const {
			return m_data;
		}
		[[nodiscard]] auto GetWidth() const {
			return m_width;
		}
		[[nodiscard]] auto GetHeight() const {
			return m_height;
		}
		[[nodiscard]] auto GetNrChannels() const {
			return m_nrChannels;
		}
	};
}
