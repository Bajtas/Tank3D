#include "WojtekPicture.h"



WojtekPicture::WojtekPicture() : r(1), g(1), b(1)
{



}
GLuint WojtekPicture::texture;
void WojtekPicture::loadModel(const char *Path) {
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;

	bool res = Loader::loadOBJ(Path, vertices, uvs, normals);

	this->vertices_size = vertices.size();

	glGenBuffersARB(1, &vertexbuffer);
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, vertexbuffer);
	glBufferDataARB(GL_ARRAY_BUFFER_ARB, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW_ARB);


	glGenBuffersARB(1, &uvbuffer);
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, uvbuffer);
	glBufferDataARB(GL_ARRAY_BUFFER_ARB, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW_ARB);

}

WojtekPicture::WojtekPicture(string Path) : r(1), g(1), b(1) {
	TextureHandler::setTexture(texture, Path);
}

void WojtekPicture::setTexture(std::string Path) {
	TextureHandler::setTexture(texture, Path);
}

void WojtekPicture::draw() {
	glTranslatef(0, -0.2, 0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, vertexbuffer);
	glVertexPointer(3, GL_FLOAT, 0, 0);
	glEnableClientState(GL_VERTEX_ARRAY);

	glBindBufferARB(GL_ARRAY_BUFFER_ARB, uvbuffer);
	glTexCoordPointer(2, GL_FLOAT, 0, 0);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glDrawArrays(GL_TRIANGLES, 0, vertices_size);
}
