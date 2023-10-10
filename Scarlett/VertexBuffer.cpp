#include "VertexBuffer.h"

#include "Renderer.h"

NamespaceScarlettBegin

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
	glCall(glGenBuffers(1, &m_rendererId));
	glCall(glBindBuffer(GL_ARRAY_BUFFER, m_rendererId));
	glCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer()
{
	glCall(glDeleteBuffers(1, &m_rendererId));
}

void VertexBuffer::Bind() const
{
	glCall(glBindBuffer(GL_ARRAY_BUFFER, m_rendererId));
}

void VertexBuffer::Unbind() const
{
	glCall(glBindBuffer(GL_ARRAY_BUFFER, 0));

}

NamespaceScarlettEnd