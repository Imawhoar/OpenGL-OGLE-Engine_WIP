#pragma once

#include <string>

class Image {
private:

	unsigned char* m_data = nullptr;
	int m_width{}, m_height{}, m_nrChannels{};
	float m_ratio{};
public:
	Image() = default;
	explicit Image(const char* src);
	explicit Image(const std::string& src);
public:
	bool LoadImage(const std::string& src);
	bool IsValid() const;
	unsigned char* GetData() const;
	int GetWidth() const;
	int GetHeight() const;
	int GetNrChannels() const;
};
