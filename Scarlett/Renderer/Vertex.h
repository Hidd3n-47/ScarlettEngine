#pragma once
#include "src/CommonHeaders.h"

NamespaceScarlettBegin

struct Color
{
	Color() : r(0), g(0), b(0), a(0) { /* Empty. */ }
	Color(ubyte r, ubyte g, ubyte b, ubyte a) : r(r), g(g), b(b), a(a) { /* Empty. */ }

	ubyte r, g, b, a;
};

struct Vertex
{
	Vertex() = default;
	Vertex(vec2 position, vec2 uv, Color color) : position(position), uv(uv), color(color) { /* Empty. */ }

	vec2	position	= vec2(0.0f);
	vec2	uv			= vec2(0.0f);

	Color	color;
};

NamespaceScarlettEnd