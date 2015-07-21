#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <cstring>

#include <glm/glm.hpp>

// Uwaga! Dzia�a tylko dla plik�w wyeksportowanych z tekstur�!

class Loader
{
public:
	static bool loadOBJ(const char * path,
		std::vector<glm::vec3> & out_vertices,
		std::vector<glm::vec2> & out_uvs,
		std::vector<glm::vec3> & out_normals
		);
};

