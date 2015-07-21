#pragma once
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <vector>
#include <glm\glm.hpp>
#include <string>
#include "TextureHandler.h"
#include "Loader.h"
class TankSteeringWheel
{
public:
	TankSteeringWheel(string Path);
	TankSteeringWheel();
	void loadModel(const char *Path);
	static void setTexture(string Path);
	void draw();
private:
	static GLuint texture;
	float r, g, b;
	GLuint vertices_size;

	GLuint VertexArrayID;
	GLuint vertexbuffer;
	GLuint uvbuffer;
};

