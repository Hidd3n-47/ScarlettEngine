#pragma once

#include "Renderer.h"

class Texture
{
public:
	Texture(const std::string& filePath);
	~Texture();

	void Bind(unsigned int slot = 0) const;
	void Unbind() const;

private:
	unsigned int m_rendererId = 0;
	std::string m_filePath;
	unsigned char* m_localBuffer = nullptr;
	int m_width = 0;
	int m_height = 0;
	int m_bpp = 0;
};

