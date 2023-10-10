#include "Shader.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include <gl/glew.h>

#include "Renderer.h"

Shader::Shader(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath) :
	m_vertexFilePath(vertexShaderFilePath),
	m_fragmentFilePath(fragmentShaderFilePath),
	m_rendererId(0)
{
	std::string vertexShader = ParseShader(m_vertexFilePath);
	std::string fragmentShader = ParseShader(m_fragmentFilePath);

	CompileShader(GL_VERTEX_SHADER, vertexShader);

	CreateShaders(vertexShader, fragmentShader);
}

Shader::~Shader()
{
	glCall(glDeleteProgram(m_rendererId));
}

void Shader::Bind() const
{
	glCall(glUseProgram(m_rendererId));
}
void Shader::Unbind() const
{
	glCall(glUseProgram(0));

}

void Shader::SetUniform1i(const std::string& name, int i0)
{
	glCall(glUniform1i(GetUniformLocation(name), i0));
}

void Shader::SetUniform4f(const std::string& name, float f0, float f1, float f2, float f3)
{
	glCall(glUniform4f(GetUniformLocation(name), f0, f1, f2, f3));
}

std::string Shader::ParseShader(const std::string& file)
{
	std::ifstream fin(file);
	std::stringstream ss;
	std::string line;
	while (getline(fin, line))
	{
		ss << line << '\n';
	}

	return ss.str();
}

unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();

	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to complie " << (type == GL_VERTEX_SHADER ? "Vertex" : "Fragment") << " Shader." << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}

	return id;
}

void Shader::CreateShaders(const std::string& vertex, const std::string frag)
{
	m_rendererId = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertex);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, frag);

	glAttachShader(m_rendererId, vs);
	glAttachShader(m_rendererId, fs);

	glLinkProgram(m_rendererId);
	glValidateProgram(m_rendererId);

	glDeleteShader(vs);
	glDeleteShader(fs);
}

int Shader::GetUniformLocation(const std::string& name)
{
	if (m_uniformLocationCache.find(name) != m_uniformLocationCache.end())
	{
		return m_uniformLocationCache[name];
	}

	glCall(int location = glGetUniformLocation(m_rendererId, name.c_str()));

	if (location == -1)
	{
		std::cout << "Warning: uniform '" << name << "' doesn't exits." << std::endl;
	}

	m_uniformLocationCache[name] = location;

	return location;
}
