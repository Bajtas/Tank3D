#pragma once
#include "Tank.h"
#include <GL\freeglut.h>
#include <glm/glm.hpp>

#define DEFAULT_SPEED 0.3
class Camera
{
public:
	enum Key {LEFT_ARROW, RIGHT_ARROW, UP_ARROW, DOWN_ARROW, Q, E};
	Camera(float x, float y, float z);
	Camera();

	void setSpeed(float speed);
	void setPosition(float x, float y, float z);
	void Update(Key key);
	void Start();
	float getTargetXPos();
	float getTargetZPos();
	float getAngle();
	void setHorizontalView();
	void setInsideView();




	float increment = -1.1;
	void setRotateView(bool y);
private:
	float angle; // k¹t obrotu kamery
	float speed; // szybkoœæ kamery
	
	//pozycja kamery
	float cam_x_pos;
	float cam_y_pos;
	float cam_z_pos;
	//pozycja obiektu
	float target_z_pos;
	float target_x_pos;

	//obrót kamery
	float x_rot;
	float y_rot;
	float z_rot;

	float horizontal_view=0;
	float inside_view=0;
	int BtCounter = 0;
	int BtCounter2 = 0;
	float rotated_view = 0;
	
	bool rotatedview = false;
	bool InsideCam = false;
	
};

