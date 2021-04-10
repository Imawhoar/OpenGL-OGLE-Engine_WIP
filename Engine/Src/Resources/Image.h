#pragma once

#include "Resource.h"
#include <string>

namespace OGLE
{
	class Image : public Resources::Resource {
	private:

		unsigned char* m_data = nullptr;
		int m_width{}, m_height{}, m_nrChannels{};
		float m_ratio{};
	public:
		Image() = default;
		Image(const std::string& src);
		explicit Image(const char* src);
	public:
		bool LoadImage(const std::string& src);
		bool IsValid() const;
		
		unsigned char* GetData() const;
		int GetWidth() const;
		int GetHeight() const;
		int GetNrChannels() const;
	};
}
