#pragma once
#include <GL\freeglut.h>
#include <vector>
#include <glm\glm.hpp>
#include <string>
#include "TextureHandler.h"
#include "Loader.h"
class TankTrack
{
public:
	TankTrack(string Path);
	TankTrack();
	void loadModel(const char *Path);
	void setTexture(string Path);
	void draw();
private:
	GLuint texture;
	float r, g, b;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;
};

