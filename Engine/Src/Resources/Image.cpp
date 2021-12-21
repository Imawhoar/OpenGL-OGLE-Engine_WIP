#include "Image.h"

#include "stb_image.h"

namespace OGLE
{
	Image::Image() {}

	Image::Image(const std::string& src)
	{
		if (!LoadImage(src))
			std::cout << "[ERROR -> Image] could not load image!";

		m_ratio = static_cast<float>(m_width) / m_height;
	}


	bool Image::LoadImage(const std::string& src)
	{
		stbi_set_flip_vertically_on_load(true);
		m_data = stbi_load(src.c_str(), &m_width, &m_height, &m_nrChannels, 0);
		return m_data;
	}

	bool Image::IsValid() const
	{
		return m_data;
	}

	unsigned char* Image::GetData() const
	{
		return m_data;
	}

	int Image::GetWidth() const
	{
		return m_width;
	}

	int Image::GetHeight() const
	{
		return m_height;
	}

	int Image::GetNrChannels() const
	{
		return m_nrChannels;
	}
}
