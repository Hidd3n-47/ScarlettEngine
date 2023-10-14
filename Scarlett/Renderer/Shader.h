#pragma once

#include <string>
#include <unordered_map>

class Shader
{
public:
	Shader(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath);
	~Shader();

	void Bind() const;
	void Unbind() const;

	// Set uniforms.
	void SetUniform1i(const std::string& name, int i0);
	void SetUniform4f(const std::string& name, float f0, float f1, float f2, float f3);
private:
	std::string m_vertexFilePath;
	std::string m_fragmentFilePath;
	unsigned int m_rendererId;
	std::unordered_map<std::string, int> m_uniformLocationCache;

	std::string ParseShader(const std::string& filepath);
	void CreateShaders(const std::string& vertex, const std::string frag);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	int GetUniformLocation(const std::string& name);
};

