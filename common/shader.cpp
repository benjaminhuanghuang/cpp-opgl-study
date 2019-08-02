#include "Shader.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <exception>

using namespace std;

Shader::Shader(const char *vertexPath, const char *fragementPath)
{
	ifstream vertexFile;
	ifstream fragementFile;
	stringstream vertextSStream;
	stringstream fragementSStream;

	vertexFile.open(vertexPath);
	fragementFile.open(fragementPath);

	vertexFile.exceptions(ifstream::failbit || ifstream::badbit);
	fragementFile.exceptions(ifstream::failbit || ifstream::badbit);

	try
	{
		if (!vertexFile.is_open() || !fragementFile.is_open())
			throw "Open file error";

		vertextSStream << vertexFile.rdbuf();
		fragementSStream << fragementFile.rdbuf();

		vertexString = vertextSStream.str();
		fragementString = fragementSStream.str();

		vertexSource = vertexString.c_str();
		fragementSource = fragementString.c_str();

		GLint vertexId = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexId, 1, &vertexSource, NULL);
		glCompileShader(vertexId);
		checkCompileErrors(vertexId);

		GLint fragementId = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragementId, 1, &fragementSource, NULL);
		glCompileShader(fragementId);
		checkCompileErrors(fragementId);

		ID = glCreateProgram();
		glAttachShader(ID, vertex);
		glAttachShader(ID, fragement);
		glLinkProgram(ID);
		checkLinkErrors(ID);

		glDeleteShader(vertex);
		glDeleteShader(fragement);
	}
	catch (const std::exception &ex)
	{
		printf(ex.what());
	}
}

void Shader::use()
{
	glUseProgram(ID);
}

void Shader::checkCompileErrors(GLint id)
{
	int success;
	char log[512];

	glGetShaderiv(id, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(id, 512, NULL, log);
		cout << "shader compile error: " << log;
	}
}

void Shader::checkLinkErrors(GLint id)
{
	int success;
	char log[512];

	glGetProgramiv(id, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(id, 512, NULL, log);
		cout << "Program link error: " << log;
	}
}