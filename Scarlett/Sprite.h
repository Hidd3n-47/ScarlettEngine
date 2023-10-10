#pragma once

#include "src/CommonHeaders.h"

#include "Renderer.h"
#include "VertexBufferLayout.h"

NamespaceScarlettBegin

class Sprite
{
public:
	Sprite() { }
	~Sprite();
	void Init(Renderer* renderer, Shader* shader, float x, float y, float width, float height);
	void Draw();
private:
	float m_x		= 0;
	float m_y		= 0;
	float m_width	= 0;
	float m_height	= 0;
	uint32 m_vboId	= 0;

	VertexArray m_vertexArray;
	IndexBuffer* m_indexBuffer = nullptr;
	VertexBuffer* m_vertexBuffer = nullptr;
	VertexBufferLayout m_vertexBufferLayout;

	Renderer* m_renderer;
	Shader* m_shader;
};

NamespaceScarlettEnd
