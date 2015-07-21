#pragma once
#include <GL\glew.h>
#include <vector>
#include <GL\freeglut.h>
#include <glm\glm.hpp>
#include "TextureHandler.h"
#include "Loader.h"
class Skybox
{
public:
	Skybox(string Path);
	Skybox();
	void loadModel(const char *Path);
	void setTexture(string Path);
	void draw();
	void Move(float x_position, float z_position);
private:
	GLuint texture;
	float r, g, b;
	GLuint vertices_size;

	GLuint VertexArrayID;
	GLuint vertexbuffer;
	GLuint uvbuffer;

	double forward = 0;
	double left_right = 0;
	double angle = 0;
};

