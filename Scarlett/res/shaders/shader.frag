#version 330 core

layout(location = 0)out vec4 color;
uniform vec4 u_Color;
uniform sampler2D u_Texture;

in vec2 v_TexCoord;
in vec4 vertColor;

void main()
{
	vec4 texColor = texture(u_Texture, v_TexCoord);
    color = (texColor * vertColor) * u_Color;
}