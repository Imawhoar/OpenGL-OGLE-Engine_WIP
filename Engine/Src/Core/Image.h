#pragma once

class Image {
private:

	unsigned char* m_data = nullptr;
	int m_width{}, m_height{}, m_nrChannels{};
	float m_ratio;
public:
	Image() {}
	explicit Image(const char* src);

public:
	bool LoadImage(const char* src);
	bool IsValid();
	unsigned char* GetData() const;
	int GetWidth() const;
	int GetHeight() const;
	int GetNrChannels() const;
};
