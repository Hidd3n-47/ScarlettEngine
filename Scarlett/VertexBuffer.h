#pragma once
#include "src/CommonHeaders.h"

#include "Vertex.h"

NamespaceScarlettBegin

class VertexBuffer
{
public:
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;
private:
	uint32 m_rendererId;
};

NamespaceScarlettEnd