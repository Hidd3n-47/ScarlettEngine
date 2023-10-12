#include "VertexBuffer.h"

#include "Renderer.h"

NamespaceScarlettBegin

VertexBuffer::VertexBuffer()
{
	glCall(glGenBuffers(1, &m_rendererId));
	glCall(glBindBuffer(GL_ARRAY_BUFFER, m_rendererId));
}

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
	VertexBuffer();
	glCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW));
}

VertexBuffer::~VertexBuffer()
{
	glCall(glDeleteBuffers(1, &m_rendererId));
}

void VertexBuffer::Bind() const
{
	glCall(glBindBuffer(GL_ARRAY_BUFFER, m_rendererId));
}

void VertexBuffer::BufferData(const void* data, uint32 size)
{
	Bind();
	glCall(glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW));
	glCall(glBufferSubData(GL_ARRAY_BUFFER, 0, size, data));
}

void VertexBuffer::Unbind() const
{
	glCall(glBindBuffer(GL_ARRAY_BUFFER, 0));

}

NamespaceScarlettEnd