#include "Renderer.h"

void GLClearError()
{
	//while (!glGetError());
}

bool GLLogCall(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		std::cout << "[OpenGL Error] (" << error << ") " << function << " " << file << ":" << line << std::endl;
		return false;
	}
	return true;
}

NamespaceScarlettBegin

Renderer::Renderer()
{
	m_vertexBuffer = new VertexBuffer();

	m_vertexBufferLayout = new VertexBufferLayout();
	m_vertexBufferLayout->Push<float>(2); // Position
	m_vertexBufferLayout->Push<ubyte>(4, true); // Color
	m_vertexBufferLayout->Push<float>(2); // UV

	m_indexBuffer = new IndexBuffer();
}

Renderer::~Renderer()
{
	for (int i = 0; i < m_glyphs.size(); i++)
	{
		delete m_glyphs[i];
	}

	delete m_indexBuffer;
	delete m_vertexBufferLayout;
	delete m_vertexBuffer;
}

void Renderer::Init()
{
	// Vertex Buffer.

	// Index Buffer.

	// Vertex Buffer layout.

	// Vertex Array - combines vertex and index.

	Vertex verts[8];
	verts[0].position.x = -1;
	verts[0].position.y = -1;
	verts[0].color = Color(255, 0, 0, 255);

	verts[1].position.x = -1;
	verts[1].position.y = 0;
	verts[1].color = Color(255, 0, 0, 255);

	verts[2].position.x = 0;
	verts[2].position.y = 0;
	verts[2].color = Color(255, 0, 0, 255);

	verts[3].position.x = 0;
	verts[3].position.y = -1;
	verts[3].color = Color(255, 0, 0, 255);

	verts[4].position.x = 0;
	verts[4].position.y = 0;
	verts[4].color = Color(255, 0, 0, 255);

	verts[5].position.x = 0;
	verts[5].position.y = 1;
	verts[5].color = Color(255, 0, 0, 255);

	verts[6].position.x = 1;
	verts[6].position.y = 1;
	verts[6].color = Color(255, 0, 0, 255);

	verts[7].position.x = 1;
	verts[7].position.y = 0;
	verts[7].color = Color(255, 0, 0, 255);

	uint32 indexBuffer[12] =
	{
		0, 1, 2,
		2, 3, 0,
		4, 5, 6,
		6, 7, 4
	};

	//VertexArray va;
	//m_vertexBuffer = new VertexBuffer(verts, sizeof(Vertex) * 8);
	m_vertexBuffer->BufferData(verts, sizeof(Vertex) * 8);
	m_vertexArray.AddBuffer(*m_vertexBuffer, *m_vertexBufferLayout);

	m_indexBuffer = new IndexBuffer(indexBuffer, 12);

	m_vertexArray.Unbind();
	m_indexBuffer->Unbind();
	m_vertexBuffer->Unbind();
}

void Renderer::AddSprite(Vec2 position, Vec2 dimensions, Vec2 uvBotLeft, Vec2 uvDims, ubyte texture, float depth, Color color)
{
	Vertex v[4];
	v[0] = Vertex(position, color, uvBotLeft);
	v[1] = Vertex(Vec2(position.x, position.y + dimensions.y), color, Vec2(uvBotLeft.u, uvBotLeft.v + uvDims.y));
	v[2] = Vertex(Vec2(position.x + dimensions.x, position.y + dimensions.y), color, Vec2(uvBotLeft.u + uvDims.x, uvBotLeft.v + uvDims.y));
	v[3] = Vertex(Vec2(position.x + dimensions.x, position.y), color, Vec2(uvBotLeft.u + uvDims.x, uvBotLeft.v));

	m_glyphs.push_back(new Glyph(texture, depth, v));

	// Sort the glyphs.
	std::stable_sort(m_glyphs.begin(), m_glyphs.end(), [](Glyph* g1, Glyph* g2) { return (g1->texture < g2->texture); });
}

void Renderer::Clear() const
{
	glClearDepth(1.0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
{
	shader.Bind();
	va.Bind();
	ib.Bind();

	for (int i = 0; i < m_batches.size(); i++)
	{
		// Need to bind texutre.
		// TODO (Christian): Need to fix this due to it not working with index buffer. Need to only draw n indices with that texture, however drawing all indicies
		glCall(glBindTexture(GL_TEXTURE_2D, m_batches[i].texture));
		glCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
	}


}

void Renderer::CreateBatches()
{
	std::vector<Vertex> vertices;
	std::vector<uint32> indicies;
	vertices.resize(m_glyphs.size() * 4);
	indicies.resize(m_glyphs.size() * 6);

	if (m_glyphs.empty())
	{
		return;
	}

	int offset = 0;
	int cv = 0;
	int ci = 0;
	m_batches.emplace_back(cv, 4, m_glyphs[0]->texture);
	vertices[cv++] = m_glyphs[0]->vertex[0];
	vertices[cv++] = m_glyphs[0]->vertex[1];
	vertices[cv++] = m_glyphs[0]->vertex[2];
	vertices[cv++] = m_glyphs[0]->vertex[3];

	indicies[ci++] = 0;
	indicies[ci++] = 1;
	indicies[ci++] = 2;
	indicies[ci++] = 2;
	indicies[ci++] = 3;
	indicies[ci++] = 0;
	offset += 4;

	for (int i = 1; i < m_glyphs.size(); i++)
	{
		if (m_glyphs[i]->texture != m_glyphs[i - 1]->texture)
		{
			m_batches.emplace_back(cv, 4, m_glyphs[i]->texture);
		}
		else
		{
			m_batches.back().numVerts += 4;
		}
		vertices[cv++] = m_glyphs[i]->vertex[0];
		vertices[cv++] = m_glyphs[i]->vertex[1];
		vertices[cv++] = m_glyphs[i]->vertex[2];
		vertices[cv++] = m_glyphs[i]->vertex[3];

		indicies[ci++] = 0 + i * 4;
		indicies[ci++] = 1 + i * 4;
		indicies[ci++] = 2 + i * 4;
		indicies[ci++] = 2 + i * 4;
		indicies[ci++] = 3 + i * 4;
		indicies[ci++] = 0 + i * 4;
		offset += 4;
	}

	m_vertexBuffer->BufferData(&vertices[0], sizeof(Vertex) * vertices.size());
	m_vertexArray.AddBuffer(*m_vertexBuffer, *m_vertexBufferLayout);

	m_indexBuffer->BufferData(&indicies[0], indicies.size());

	m_vertexArray.Unbind();
	m_indexBuffer->Unbind();
	m_vertexBuffer->Unbind();
}

NamespaceScarlettEnd