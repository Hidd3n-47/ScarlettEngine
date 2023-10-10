#pragma once
#include "src/CommonHeaders.h"

#include "VertexBuffer.h"

NamespaceScarlettBegin

class VertexBufferLayout;

class VertexArray
{
public:
	VertexArray();
	~VertexArray();

	void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

	void Bind() const;
	void Unbind() const;
private:
	uint32 m_rendererId;
};

NamespaceScarlettEnd