#pragma once
#include "src/CommonHeaders.h"

#include "Renderer.h"

class Texture
{
public:
	Texture(const std::string& filePath);
	~Texture();

	void Bind(uint32 slot = 0) const;
	void Unbind() const;

	inline uint32 GetId() const { return m_rendererId; }
private:
	uint32 m_rendererId = 0;
	std::string m_filePath;
	ubyte* m_localBuffer = nullptr;
	int m_width = 0;
	int m_height = 0;
	int m_bpp = 0;
};

