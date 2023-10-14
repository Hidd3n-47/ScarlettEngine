#pragma once
#include "src/CommonHeaders.h"

#include "Vertex.h"

NamespaceScarlettBegin

class VertexBuffer
{
public:
	VertexBuffer();
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	void Bind() const;
	void BufferData(const void* data, uint32 size);
	void Unbind() const;
private:
	uint32 m_rendererId = 0;
};

NamespaceScarlettEnd