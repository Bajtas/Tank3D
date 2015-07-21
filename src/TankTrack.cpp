#include "TankTrack.h"

TankTrack::TankTrack() : r(1), g(1), b(1)
{
}

void TankTrack::loadModel(const char *Path) {
	bool res = Loader::loadOBJ(Path, vertices, uvs, normals);
}

TankTrack::TankTrack(string Path) : r(1), g(1), b(1) {
	TextureHandler::setTexture(this->texture, Path);
}

void TankTrack::setTexture(std::string Path) {
	TextureHandler::setTexture(this->texture, Path);
}

void TankTrack::draw() {
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < vertices.size(); i++)
	{
		glTexCoord2f(uvs[i].x, uvs[i].y);
		glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
	}
	glEnd();
}



