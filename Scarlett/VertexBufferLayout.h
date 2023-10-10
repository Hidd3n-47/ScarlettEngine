#pragma once
#include "src/CommonHeaders.h"

#include "Renderer.h"

NamespaceScarlettBegin

struct VertexBufferElement
{
	uint32	type;
	uint32	count;
	ubyte	normalized;

	static uint32 GetSizeOfType(uint32 type)
	{
		switch (type)
		{
		case GL_FLOAT:			return 4;
		case GL_UNSIGNED_INT:	return 4;
		case GL_UNSIGNED_BYTE:	return 1;
		}

		assert(true);
		return 0;
	}
};

class VertexBufferLayout
{
public:
	VertexBufferLayout() { }

	template<typename T>
	void Push(unsigned int count, ubyte normalize = 0)
	{
		assert(true);
	}

	template<>
	void Push<float>(unsigned int count, ubyte normalize)
	{
		m_elements.push_back({ GL_FLOAT, count, normalize });
		m_stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
	}

	template<>
	void Push<uint32>(unsigned int count, ubyte normalize)
	{
		m_elements.push_back({ GL_FLOAT, count, normalize });
		m_stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
	}

	template<>
	void Push<ubyte>(unsigned int count, ubyte normalize)
	{
		m_elements.push_back({ GL_UNSIGNED_BYTE, count, normalize });
		m_stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
	}

	inline unsigned int GetStride() const { return m_stride; }
	inline const std::vector<VertexBufferElement> GetElements() const& { return m_elements; }
private:
	std::vector<VertexBufferElement> m_elements;
	unsigned int m_stride = 0;
};

NamespaceScarlettEnd