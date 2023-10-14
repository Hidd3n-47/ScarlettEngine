#pragma once
#include "src/CommonHeaders.h"

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "VertexBufferLayout.h"


#define ASSERT(x) if(!(x)) __debugbreak();
#define glCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();

bool GLLogCall(const char* function, const char* file, int line);

NamespaceScarlettBegin

class Batch
{
public:
	Batch(ubyte offset, ubyte verts, ubyte texture) : offset(offset), numVerts(verts), texture(texture) { /* Empty. */ }
	ubyte offset;
	ubyte numVerts;
	ubyte texture;
private:

};

struct Glyph
{
	Glyph(ubyte texture, float depth, const Vertex verts[4]) : texture(texture), depth(depth) { vertex[0] = verts[0]; vertex[1] = verts[1];
	vertex[2] = verts[2];
	vertex[3] = verts[3];
	}

	ubyte texture;
	float depth;
	Vertex vertex[4];
};

class Renderer
{
public:
	Renderer();
	~Renderer();
	void Init();

	void AddSprite(vec4 destRect, vec4 uvRect, ubyte texture, float depth, Color color);
	void CreateBatches();

	void Clear() const;
	inline void Draw(const Shader& shader) { Draw(m_vertexArray, *m_indexBuffer, shader); }
	void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const; 
private:
	VertexArray m_vertexArray;
	IndexBuffer* m_indexBuffer = nullptr;
	VertexBuffer* m_vertexBuffer = nullptr;
	VertexBufferLayout* m_vertexBufferLayout = nullptr;

	std::vector<Glyph*> m_glyphs;
	std::vector<Batch> m_batches;

};

NamespaceScarlettEnd