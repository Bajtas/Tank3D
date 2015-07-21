#pragma once
#include <GL\freeglut.h>
#include <string>
#include "TextureHandler.h"

class Cube
{
public:
	Cube();
	Cube(string Path);
	void draw();
	void setPostion(float x, float y, float z);
	void setColor(float r, float g, float b);
	void setTexture(std::string Path);
	void setRotate(float angle);
	float getX();
	float getY();
	float getZ();
	void Update();
	void setFall(bool is_falling);
private:
	GLuint Texture;
	float pos_x;
	float pos_y;
	float pos_z;
	float angle;
	float gravity = 1;
	float r, g, b;
	bool ground = false;
	float mass = 1.5;
};

