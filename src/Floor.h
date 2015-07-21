#pragma once
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <string>
#include "TextureHandler.h"
#include "Cube.h"
#include "Tank.h"

#define POS_Y 0
class Floor
{
public:
	Floor();
	Floor(string Path);
	void draw();
	void setTexture(std::string Path);
	void Collision(Cube &obj);
	void Collision(Tank &obj);
private:
	GLuint Texture;
	float r, g, b;
};

