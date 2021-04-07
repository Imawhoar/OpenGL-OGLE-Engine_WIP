#pragma once
#include <string>
class Image;

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
	void Bind();
	Image* GetImage();
};