#version 330 core

layout(location = 0)in vec2 vertexPosition;
layout(location = 1)in vec4 color;
layout(location = 2)in vec2 texCoord;

out vec2 v_TexCoord;
out vec4 vertColor;

void main()
{
    gl_Position = vec4(vertexPosition, 0.0, 1.0);
	vertColor = color; 
	v_TexCoord = texCoord;
}