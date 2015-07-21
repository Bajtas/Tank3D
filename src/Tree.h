#pragma once
#include <GL\glew.h>
#include <vector>
#include <GL\freeglut.h>
#include <glm\glm.hpp>
#include "TextureHandler.h"
#include "Loader.h"
#include "Tank.h"
#include <math.h>
class Tree
{
public:
	Tree(string Path);
	Tree();
	void loadModel(const char *Path);
	void setTexture(string Path);
	void draw();
	void randPosition(float x, float z);
private:
	static GLuint texture;
	float r, g, b;
	GLuint vertices_size;

	GLuint VertexArrayID;
	GLuint vertexbuffer;
	GLuint uvbuffer;

	float x = 0;
	float z = 0;
};

