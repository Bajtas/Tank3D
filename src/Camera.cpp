#include "Camera.h"

Camera::Camera(float x, float y, float z) : cam_x_pos(x), cam_y_pos(y), cam_z_pos(z), target_z_pos(z-1)
{
	setSpeed(DEFAULT_SPEED);
}
Camera::Camera() : cam_x_pos(0), cam_y_pos(0.5), cam_z_pos(0), angle(0), target_x_pos(0), target_z_pos(-1){
	setSpeed(DEFAULT_SPEED);
}
//ustawianie pozycji kamery
void Camera::setPosition(float x, float y, float z) {
	this->cam_x_pos = x;
	this->cam_y_pos = y;
	this->cam_z_pos = z;
}
//ustawianie szybkoœci obrotu/przybli¿ania kamery
void Camera::setSpeed(float speed) {
	this->speed = speed;
}
void Camera::Update(Key key) {
	switch (key) {
		case Q:
		case LEFT_ARROW:
			angle -= 0.04f*speed;
			target_x_pos = sin(angle);
			target_z_pos = -cos(angle);
			break;
		case E:
		case RIGHT_ARROW:
			angle += 0.04f*speed;
			target_x_pos = sin(angle);
			target_z_pos = -cos(angle);
			break;
		case UP_ARROW:
			cam_x_pos += target_x_pos * speed;
			cam_z_pos += target_z_pos * speed;
			break;
		case DOWN_ARROW:
			cam_x_pos -= target_x_pos * speed;
			cam_z_pos -= target_z_pos * speed;
			break;
	}
}
float Camera::getAngle() {
	return angle;
}
void Camera::Start() {
	if (InsideCam) // widok z kokpitu
		glTranslatef(0.3, increment, -0.31);
	else
		glTranslatef(0, 0, -10); // widok z 3 osoby
	gluLookAt(cam_x_pos, cam_y_pos, cam_z_pos+horizontal_view,
		cam_x_pos + target_x_pos, 0, cam_z_pos + target_z_pos,
		rotated_view, 1, 0); // Funkcja obs³uguj¹ca kamere
}
void Camera::setRotateView(bool y){
	if (y){
		rotated_view += 0.1;
	}
	else
		rotated_view -= 0.1;
}

float Camera::getTargetZPos(){
	return cam_z_pos + target_z_pos;
}
void Camera::setHorizontalView() {
	BtCounter++;
	this->horizontal_view = 5;
	
	if (BtCounter % 2 == 0)
	{
		this->horizontal_view = 0;
		this->inside_view = 0;
	}
	
}
void Camera::setInsideView() {
	BtCounter2++;
	this->inside_view = 0.4;
	InsideCam = true;

	Tank::setInsideView(true);
	if (BtCounter2 % 2 == 0)
	{
		InsideCam = false;
		cam_y_pos = 0.5;
		this->horizontal_view = 0;
		this->inside_view = 0;
		this->target_z_pos = -1;
		Tank::setInsideView(false);
	}
	cam_y_pos -= inside_view;
}
float Camera::getTargetXPos(){
	return cam_x_pos + target_x_pos;
}