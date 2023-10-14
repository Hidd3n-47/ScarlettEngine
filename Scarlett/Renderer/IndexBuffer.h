#pragma once
#include "src/CommonHeaders.h"

class IndexBuffer
{
public:
	IndexBuffer();
	IndexBuffer(const uint32* data, uint32 count);
	~IndexBuffer();

	void Bind() const;
	void BufferData(const uint32* data, uint32 count);
	void Unbind() const;

	// Accessor.
	inline uint32 GetCount() const { return m_count; }
private:
	uint32 m_rendererId;
	uint32 m_count;
};

