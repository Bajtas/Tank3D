#pragma once
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <string>
#include <vector>
#include <glm\glm.hpp>
#include "TankBody.h"
#include "TankTrack.h"
#include "TankWheels.h"
#include "TankTower.h"
#include "TankSteeringWheel.h"
#include "WojtekPicture.h"

#define WheelsAmount 10 
#define WheelsFrames 41
#define TowerFrames 101
#define SteeringWheelFrames 41
#define POS_Y 0
class Tank
{
public:
	Tank();
	void draw();
	void Move(float x_position, float z_position);
	void Move(float x_position, float z_position, bool LR);
	//Kolejne elementy czo³gu
	TankBody Body[2];
	TankTrack Track;
	TankWheels Wheel[WheelsAmount][WheelsFrames];
	TankTower Tower[TowerFrames];
	TankSteeringWheel SteeringWheel[SteeringWheelFrames];
	WojtekPicture Picture;

	void Update();
	void setFall(bool is_falling);
	void LoadWheels();
	void LoadTower();
	void LoadBullet();
	void LoadSteeringWheel();
	void WheelAnimationUpdateF();
	void WheelAnimationUpdateB();
	void RotateTowerR();
	void RotateTowerL();
	void RotateSteeringWheelL();
	void RotateSteeringWheelR();
	float getY();
	static void setInsideView(bool y_n);
	bool getInsideView();
	float getXPos();
	float getZPos();

	TankBody Bullet[10];
private:
	GLuint texture;
	float r, g, b;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;
	double forward = 0;
	double left_right = 0;
	double speed = 1;

	float pos_y = 5;
	float Angle = 0;
	bool fall = true;
	float mass = 5.5;
	float gravity = 1;

	float TowerAngle = 0;

	int CounterWheel = 0;
	int CounterTower = 0;
	int CounterSteeringWheel = 1;
	int oldTimeSinceStart = 0;
	int deltaTime = 0;
	int timeSinceStart = 0;

	static bool InsideView;
};

