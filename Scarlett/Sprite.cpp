#include "Sprite.h"

NamespaceScarlettBegin

Sprite::~Sprite()
{
	if (m_vboId != 0)
	{
		glDeleteBuffers(1, &m_vboId);
	}
}

void Sprite::Init(Renderer* renderer, Shader* shader, float x, float y, float width, float height)
{
	m_renderer = renderer;
	m_shader = shader;

	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;

	/*if (m_vboId == 0)
	{
		glGenBuffers(1, &m_vboId);
	}*/

	float vertexData[12] =
	{
		x + width, y + height,
		x, y + height,
		x, y,
		x, y,
		x + width, y,
		x + width, y + height
	};

	Vertex verts[4];

	verts[0].position.x = x;
	verts[0].position.y = y;

	verts[1].position.x = x;
	verts[1].position.y = y + height;

	verts[2].position.x = x + width;
	verts[2].position.y = y + height;

	verts[3].position.x = x + width;
	verts[3].position.y = y;

	uint32 indexBuffer[6] =
	{
		0, 1, 2,
		2, 3, 0
	};

	//VertexArray va;
	m_vertexBuffer = new VertexBuffer(vertexData, sizeof(float) * 12);

	/*
		THERE IS A PROBLEM HERE DUE TO THE FACT THAT THE LAYER CANNOT HAVE MULITPLE ATTRIBUTES IN THEM. IE THE COLOR AND THE POSITION CANOT BE LIKE IN A VERTEX STRUCT THAT IS PASSED IN
		IN ORDER TO DO BENS IMPLEMENTATION WOULD HAVE TO LOOK AT CHANGING HOW LAYOUT WORKS OR STICK TO CHERNO
		EASIEST FOR NOW IS TO DO CHERNO METHOD AND SEE WHERE BEN GOES WITH HIS SPRITE BATCHING LATERR ON AND WITH TEXTURES.
	*/

	m_vertexBufferLayout.Push<float>(2); // Position
	m_vertexArray.AddBuffer(*m_vertexBuffer, m_vertexBufferLayout);

	m_indexBuffer = new IndexBuffer(indexBuffer, 6);

	/*float vertexData[12] =
	{
		x + width, y + height,
		x, y + height,
		x, y,
		x, y,
		x + width, y,
		x + width, y + height
	};*/

	/*glBindBuffer(GL_ARRAY_BUFFER, m_vboId);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);*/

	m_vertexArray.Unbind();
	m_indexBuffer->Unbind();
	m_vertexBuffer->Unbind();
}

void Sprite::Draw()
{
	/*glBindBuffer(GL_ARRAY_BUFFER, m_vboId);

	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);*/

	m_renderer->Draw(m_vertexArray, *m_indexBuffer, *m_shader);

}

NamespaceScarlettEnd