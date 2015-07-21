#pragma once
#include <GL\glew.h>
#include <vector>
#include <GL\freeglut.h>
#include <glm\glm.hpp>
#include "TextureHandler.h"
#include "Loader.h"
class TankTower
{
public:
	TankTower(string Path);
	TankTower();
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

