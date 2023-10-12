#include "IndexBuffer.h"

#include "Renderer.h"

IndexBuffer::IndexBuffer()
{
	ASSERT(sizeof(uint32) == sizeof(GLuint));

	glCall(glGenBuffers(1, &m_rendererId));
	glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererId));
}

IndexBuffer::IndexBuffer(const uint32* data, uint32 count) :
	m_count(count)
{
	ASSERT(sizeof(uint32) == sizeof(GLuint));

	glCall(glGenBuffers(1, &m_rendererId));
	glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererId)); 
	glCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32), data, GL_DYNAMIC_DRAW));
}

IndexBuffer::~IndexBuffer()
{
	glCall(glDeleteBuffers(1, &m_rendererId));
}

void IndexBuffer::Bind() const
{
	glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererId));
}

void IndexBuffer::BufferData(const uint32* data, uint32 count)
{
	m_count = count;
	Bind();
	glCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32), nullptr, GL_DYNAMIC_DRAW));
	glCall(glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, count * sizeof(uint32), data));
}

void IndexBuffer::Unbind() const
{
	glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));

}