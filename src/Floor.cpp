#include "Floor.h"

Floor::Floor() : r(1), g(1), b(1)
{
}

Floor::Floor(string Path) : r(1), g(1), b(1) {
	TextureHandler::setTexture(this->Texture, Path);
}

void Floor::draw() {
	if (this->Texture != NULL) {
		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, this->Texture);
		glColor3f(r, g, b);
		glBegin(GL_QUADS);
		glTexCoord2i(1, 0);
		glVertex3f(-5.0f, 0.0f, -5.0f);
		glTexCoord2i(0, 1);
		glVertex3f(-5.0f, 0.0f, 5.0f);
		glTexCoord2i(1, 1);
		glVertex3f(5.0f, 0.0f, 5.0f);
		glTexCoord2i(0, 0);
		glVertex3f(5.0f, 0.0f, -5.0f);
		glEnd();
		glPopMatrix();
		glPushMatrix();
		for (int j = 0;j < 250;j+=10) {
			for (int i = 0;i < 10;i++) {
				glTranslatef(-10, 0, 0);
				glColor3f(r, g, b);
				glBegin(GL_QUADS);
				glTexCoord2i(1, 0);
				glVertex3f(-5.0f, 0.0f, -5.0f);
				glTexCoord2i(0, 1);
				glVertex3f(-5.0f, 0.0f, 5.0f);
				glTexCoord2i(1, 1);
				glVertex3f(5.0f, 0.0f, 5.0f);
				glTexCoord2i(0, 0);
				glVertex3f(5.0f, 0.0f, -5.0f);
				glEnd();
			}
			glPopMatrix();
			glPushMatrix();
			glTranslatef(0, 0, j);
		}
		for (int j = 0;j < 250;j += 10) {
			for (int i = 0;i < 10;i++) {
				glTranslatef(10, 0, 0);
				glColor3f(r, g, b);
				glBegin(GL_QUADS);
				glTexCoord2i(1, 0);
				glVertex3f(-5.0f, 0.0f, -5.0f);
				glTexCoord2i(0, 1);
				glVertex3f(-5.0f, 0.0f, 5.0f);
				glTexCoord2i(1, 1);
				glVertex3f(5.0f, 0.0f, 5.0f);
				glTexCoord2i(0, 0);
				glVertex3f(5.0f, 0.0f, -5.0f);
				glEnd();
			}
			glPopMatrix();
			glPushMatrix();
			glTranslatef(0, 0, j);
			glBegin(GL_QUADS);
			glTexCoord2i(1, 0);
			glVertex3f(-5.0f, 0.0f, -5.0f);
			glTexCoord2i(0, 1);
			glVertex3f(-5.0f, 0.0f, 5.0f);
			glTexCoord2i(1, 1);
			glVertex3f(5.0f, 0.0f, 5.0f);
			glTexCoord2i(0, 0);
			glVertex3f(5.0f, 0.0f, -5.0f);
			glEnd();
		}
		for (int j = 0;j < 200;j += 10) {
			for (int i = 0;i < 10;i++) {
				glTranslatef(10, 0, 0);
				glColor3f(r, g, b);
				glBegin(GL_QUADS);
				glTexCoord2i(1, 0);
				glVertex3f(-5.0f, 0.0f, -5.0f);
				glTexCoord2i(0, 1);
				glVertex3f(-5.0f, 0.0f, 5.0f);
				glTexCoord2i(1, 1);
				glVertex3f(5.0f, 0.0f, 5.0f);
				glTexCoord2i(0, 0);
				glVertex3f(5.0f, 0.0f, -5.0f);
				glEnd();
			}
			glPopMatrix();
			glPushMatrix();
			glTranslatef(0, 0, -j);
			glBegin(GL_QUADS);
			glTexCoord2i(1, 0);
			glVertex3f(-5.0f, 0.0f, -5.0f);
			glTexCoord2i(0, 1);
			glVertex3f(-5.0f, 0.0f, 5.0f);
			glTexCoord2i(1, 1);
			glVertex3f(5.0f, 0.0f, 5.0f);
			glTexCoord2i(0, 0);
			glVertex3f(5.0f, 0.0f, -5.0f);
			glEnd();
		}
		for (int j = 0;j < 200;j += 10) {
			for (int i = 0;i < 10;i++) {
				glTranslatef(-10, 0, 0);
				glColor3f(r, g, b);
				glBegin(GL_QUADS);
				glTexCoord2i(1, 0);
				glVertex3f(-5.0f, 0.0f, -5.0f);
				glTexCoord2i(0, 1);
				glVertex3f(-5.0f, 0.0f, 5.0f);
				glTexCoord2i(1, 1);
				glVertex3f(5.0f, 0.0f, 5.0f);
				glTexCoord2i(0, 0);
				glVertex3f(5.0f, 0.0f, -5.0f);
				glEnd();
			}
			glPopMatrix();
			glPushMatrix();
			glTranslatef(0, 0, -j);
			glBegin(GL_QUADS);
			glTexCoord2i(1, 0);
			glVertex3f(-5.0f, 0.0f, -5.0f);
			glTexCoord2i(0, 1);
			glVertex3f(-5.0f, 0.0f, 5.0f);
			glTexCoord2i(1, 1);
			glVertex3f(5.0f, 0.0f, 5.0f);
			glTexCoord2i(0, 0);
			glVertex3f(5.0f, 0.0f, -5.0f);
			glEnd();
		}
		glPopMatrix();
	}
	else
	{
		glPushMatrix();
		glColor3f(r, g, b);
		glBegin(GL_QUADS);
		glVertex3f(-100.0f, 0.0f, -100.0f);
		glVertex3f(-100.0f, 0.0f, 100.0f);
		glVertex3f(100.0f, 0.0f, 100.0f);
		glVertex3f(100.0f, 0.0f, -100.0f);
		glEnd();
		glPopMatrix();
	}
}

void Floor::setTexture(std::string Path) {
	TextureHandler::setTexture(this->Texture, Path);
}

void Floor::Collision(Cube &obj) {
	if (obj.getY() < POS_Y) {
		obj.setFall(false);
	}
	else
		obj.setFall(true);
}

void Floor::Collision(Tank &obj) {
	if (obj.getY() < POS_Y) {
		obj.setFall(false);
	}
	else
		obj.setFall(true);
}