#include "Texture.h"

#include <stb_image/stb_image.h>

Texture::Texture(const std::string& filePath) :
	m_filePath(filePath)
{
	stbi_set_flip_vertically_on_load(1);

	m_localBuffer = stbi_load(filePath.c_str(), &m_width, &m_height, &m_bpp, 4);
	
	glCall(glGenTextures(1, &m_rendererId));
	glCall(glBindTexture(GL_TEXTURE_2D, m_rendererId));

	glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
	glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

	glCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_localBuffer));

	glCall(glBindTexture(GL_TEXTURE_2D, 0));

	if (m_localBuffer)
	{
		stbi_image_free(m_localBuffer);
	}
}

Texture::~Texture()
{
	glCall(glDeleteTextures(1, &m_rendererId));
}

void Texture::Bind(uint32 slot) const
{
	glCall(glActiveTexture(GL_TEXTURE0 + slot));
	glCall(glBindTexture(GL_TEXTURE_2D, m_rendererId));
}

void Texture::Unbind() const
{
	glCall(glBindTexture(GL_TEXTURE_2D, 0));

}