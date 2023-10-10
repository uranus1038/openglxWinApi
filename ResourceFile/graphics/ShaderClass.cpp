
#include "ShaderClass.h"
#include "../Engin/UMISystem.cpp"
using namespace UMISystem;
std::string getFileShader(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	else{
		UMISystem::Console::Log("Load Shader Failed");
		return "failed";
	}
}

Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
	std::string vertexCode = getFileShader(vertexFile);
	std::string fragmentCode = getFileShader(fragmentFile);
	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

}

void Shader::Activate()
{
	glUseProgram(ID);
}

void Shader::Delete()
{
	glDeleteProgram(ID);
}