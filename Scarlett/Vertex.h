#pragma once
#include "src/CommonHeaders.h"

NamespaceScarlettBegin

struct Vec2
{
	Vec2() : x(0.0f), y(0.0f) { /* Empty. */ }
	Vec2(float x, float y) : x(x), y(y) { /* Empty. */ }

	union { float x, u; };
	union { float y, v; };
};

struct Color
{
	Color() : r(0), g(0), b(0), a(0) { /* Empty. */ }
	Color(ubyte r, ubyte g, ubyte b, ubyte a) : r(r), g(g), b(b), a(a) { /* Empty. */ }

	ubyte r, g, b, a;
};

struct Vertex
{
	Vertex() = default;
	Vertex(Vec2 position, Color color, Vec2 uv) : position(position), color(color), uv(uv) { /* Empty. */ }

	Vec2	position;
	Color	color;
	Vec2	uv;
};

NamespaceScarlettEnd