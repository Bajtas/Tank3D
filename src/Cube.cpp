#include "Cube.h"

Cube::Cube() : r(1), g(1), b(1), angle(0)
{
}
Cube::Cube(string Path): angle(0){
	TextureHandler::setTexture(this->Texture, Path);
}

void Cube::setRotate(float angle) {
	this->angle = angle;
}

void Cube::draw() {
	if (this->Texture != NULL)
	{
		glBindTexture(GL_TEXTURE_2D, this->Texture);
		glPushMatrix();
		glColor3f(1, 1, 1);
		glRotatef(angle, 0, 1, 0);
		glTranslatef(pos_x, pos_y, pos_z);
		glBegin(GL_QUADS);
		//przednia
		glTexCoord2i(1, 1); glVertex3f(0, 0, 0);
		glTexCoord2i(1, 0); glVertex3f(0, 1, 0);
		glTexCoord2i(0, 0); glVertex3f(1, 1, 0);
		glTexCoord2i(0, 1); glVertex3f(1, 0, 0);

		//dolna
		glTexCoord2i(1, 1); glVertex3f(0, 0, 0);
		glTexCoord2i(1, 0); glVertex3f(1, 0, 0);
		glTexCoord2i(0, 0); glVertex3f(1, 0, -1);
		glTexCoord2i(0, 1); glVertex3f(0, 0, -1);

		//lewa
		glTexCoord2i(1, 1); glVertex3f(0, 0, 0);
		glTexCoord2i(1, 0); glVertex3f(0, 0, -1);
		glTexCoord2i(0, 0); glVertex3f(0, 1, -1);
		glTexCoord2i(0, 1); glVertex3f(0, 1, 0);

		//gorna
		glTexCoord2i(1, 1); glVertex3f(0, 1, 0);
		glTexCoord2i(1, 0); glVertex3f(0, 1, -1);
		glTexCoord2i(0, 0); glVertex3f(1, 1, -1);
		glTexCoord2i(0, 1); glVertex3f(1, 1, 0);

		//prawa
		glTexCoord2i(1, 1); glVertex3f(1, 0, 0);
		glTexCoord2i(1, 0); glVertex3f(1, 1, 0);
		glTexCoord2i(0, 0); glVertex3f(1, 1, -1);
		glTexCoord2i(0, 1); glVertex3f(1, 0, -1);

		//tylna
		glTexCoord2i(1, 1); glVertex3f(0,0,-1);
		glTexCoord2i(1, 0); glVertex3f(0, 1, -1);
		glTexCoord2i(0, 0); glVertex3f(1, 1, -1);
		glTexCoord2i(0, 1); glVertex3f(1, 0, -1);
		glEnd();
		glPopMatrix();
	}
	else {
		glPushMatrix();
		glTranslatef(pos_x, pos_y, pos_z);
		glColor3f(r, g, b);
		glRotatef(angle, 0, 1, 0);
		glBegin(GL_QUADS);
		//przednia
		glVertex3f(0, 0, 0);
		glVertex3f(0, 1, 0);
		glVertex3f(1, 1, 0);
		glVertex3f(1, 0, 0);

		//dolna
		glVertex3f(0, 0, 0);
		glVertex3f(1, 0, 0);
		glVertex3f(1, 0, -1);
		glVertex3f(0, 0, -1);

		//lewa
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, -1);
		glVertex3f(0, 1, -1);
		glVertex3f(0, 1, 0);

		//gorna
		glVertex3f(0, 1, 0);
		glVertex3f(0, 1, -1);
		glVertex3f(1, 1, -1);
		glVertex3f(1, 1, 0);

		//prawa
		glVertex3f(1, 0, 0);
		glVertex3f(1, 1, 0);
		glVertex3f(1, 1, -1);
		glVertex3f(1, 0, -1);

		//tylna
		glVertex3f(0, 0, -1);
		glVertex3f(0, 1, -1);
		glVertex3f(1, 1, -1);
		glVertex3f(1, 0, -1);

		glEnd();
		glPopMatrix();
	}
}

void Cube::setTexture(std::string Path) {
	TextureHandler::setTexture(this->Texture, Path);
}

void Cube::setPostion(float x, float y, float z) {
	pos_x = x;
	pos_y = y;
	pos_z = z;
}

void Cube::setColor(float r, float g, float b) {
	this->r = r;
	this->g = g;
	this->b = b;
}

void Cube::setFall(bool is_falling) {
	this->ground = is_falling;
}
void Cube::Update() {
	if (!this->ground)
		return;
	else
	{
		pos_y -= 0.01*mass*gravity;
		glBindTexture(GL_TEXTURE_2D, this->Texture);
		glPushMatrix();
		glColor3f(1, 1, 1);
		glRotatef(angle, 0, 1, 0);
		glTranslatef(pos_x, pos_y, pos_z);
		glBegin(GL_QUADS);
		//przednia
		glTexCoord2i(1, 1); glVertex3f(0, 0, 0);
		glTexCoord2i(1, 0); glVertex3f(0, 1, 0);
		glTexCoord2i(0, 0); glVertex3f(1, 1, 0);
		glTexCoord2i(0, 1); glVertex3f(1, 0, 0);

		//dolna
		glTexCoord2i(1, 1); glVertex3f(0, 0, 0);
		glTexCoord2i(1, 0); glVertex3f(1, 0, 0);
		glTexCoord2i(0, 0); glVertex3f(1, 0, -1);
		glTexCoord2i(0, 1); glVertex3f(0, 0, -1);

		//lewa
		glTexCoord2i(1, 1); glVertex3f(0, 0, 0);
		glTexCoord2i(1, 0); glVertex3f(0, 0, -1);
		glTexCoord2i(0, 0); glVertex3f(0, 1, -1);
		glTexCoord2i(0, 1); glVertex3f(0, 1, 0);

		//gorna
		glTexCoord2i(1, 1); glVertex3f(0, 1, 0);
		glTexCoord2i(1, 0); glVertex3f(0, 1, -1);
		glTexCoord2i(0, 0); glVertex3f(1, 1, -1);
		glTexCoord2i(0, 1); glVertex3f(1, 1, 0);

		//prawa
		glTexCoord2i(1, 1); glVertex3f(1, 0, 0);
		glTexCoord2i(1, 0); glVertex3f(1, 1, 0);
		glTexCoord2i(0, 0); glVertex3f(1, 1, -1);
		glTexCoord2i(0, 1); glVertex3f(1, 0, -1);

		//tylna
		glTexCoord2i(1, 1); glVertex3f(0, 0, -1);
		glTexCoord2i(1, 0); glVertex3f(0, 1, -1);
		glTexCoord2i(0, 0); glVertex3f(1, 1, -1);
		glTexCoord2i(0, 1); glVertex3f(1, 0, -1);
		glEnd();
		glPopMatrix();
	}
}
float Cube::getX() { return pos_x; }
float Cube::getY() { return pos_y; }
float Cube::getZ() { return pos_z; }