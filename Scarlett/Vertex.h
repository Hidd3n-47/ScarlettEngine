#pragma once
#include "src/CommonHeaders.h"

NamespaceScarlettBegin

struct Position
{
	Position() : x(0.0f), y(0.0f) { /* Empty. */ }
	float x, y;
};

struct Color
{
	Color() : r(0), g(0), b(0), a(0) { /* Empty. */ }

	ubyte r, g, b, a;
};


struct Vertex
{
	Position position;
	Color Color;
};

NamespaceScarlettEnd