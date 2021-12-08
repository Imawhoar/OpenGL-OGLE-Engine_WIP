#pragma once

#include <iostream>

namespace OGLE
{
	class Image {
	private:
		unsigned char* m_data = nullptr;
		int m_width{}, m_height{}, m_nrChannels{};
		float m_ratio{};
	public:
		Image();
		explicit Image(const std::string& src);

	public:
		bool LoadImage(const std::string& src);

		[[nodiscard]] bool IsValid() const;
		[[nodiscard]] unsigned char* GetData() const;
		[[nodiscard]] int GetWidth() const;
		[[nodiscard]] int GetHeight() const;
		[[nodiscard]] int GetNrChannels() const;
	};


}
