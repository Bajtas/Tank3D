#pragma once
#include <GL\glew.h>
#include <vector>
#include <GL\freeglut.h>
#include <glm\glm.hpp>
#include "TextureHandler.h"
#include "Loader.h"
class WojtekPicture
{
public:
	WojtekPicture(string Path);
	WojtekPicture();
	void loadModel(const char *Path);
	void setTexture(string Path);
	void draw();
private:
	static GLuint texture;
	float r, g, b;
	GLuint vertices_size;

	GLuint VertexArrayID;
	GLuint vertexbuffer;
	GLuint uvbuffer;
};

