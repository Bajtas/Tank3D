#include "Tank.h"

Tank::Tank() : r(1), g(1), b(1)
{

}

void Tank::LoadTower() {
	string str = "";
	string Path;

	for (int i = 1;i < TowerFrames;i++) {
			Path = "Assets/Animation/Tower/Tiger_tower_000";
			str = "";
			if (i < 10)
			{
				str += std::to_string(0);
				str += std::to_string(0);
				str += std::to_string(i);
			}
			else if (i < 100 || i == 10) {
				str += std::to_string(0);
				str += std::to_string(i);
			}
			else if(i >= 100)
				str = std::to_string(i);
			Path += str;
			Path += ".obj";
			const char *chr = Path.c_str();
			Tower[i - 1].loadModel(chr);
	}
	Tower[0].setTexture("Assets/Textures/dark_metal.jpg");
}

void Tank::LoadWheels() {
	string str="";
	string Path;
	string str2 = "";
	for (int j = 0;j < WheelsAmount;j++) {
		str2 = "Assets/Animation/Wheels/Wheel";
		str = std::to_string(j+1);
		str2 += str;
		str2 += "_0000";
		for (int i = 1;i < WheelsFrames ;i++) {
			Path = str2;
			str = "";
			if (i < 10)
			{
				str += std::to_string(0);
				str += std::to_string(i);
			}
			else
				str = std::to_string(i);
			Path += str;
			Path += ".obj";
			const char *chr = Path.c_str();
			Wheel[j][i-1].loadModel(chr);
		}
		
	}
	Wheel[0][0].setTexture("Assets/Textures/dark_metal.jpg");
}

void Tank::LoadSteeringWheel() {
	string str = "";
	string Path;
	for (int i = 1; i < SteeringWheelFrames; i++) {
			Path = "Assets/Animation/SteeringWheel/SteeringWheel_0000";
			str = "";
			if (i < 10)
			{
				str += std::to_string(0);
				str += std::to_string(i);
			}
			else
				str = std::to_string(i);
			Path += str;
			Path += ".obj";
			const char *chr = Path.c_str();
			SteeringWheel[i].loadModel(chr);
	}
	SteeringWheel[0].setTexture("Assets/Textures/rubber.jpg");
}


void Tank::Move(float x_position, float z_position){
	forward = z_position;
	left_right = x_position;
}
float Tank::getXPos(){
	return left_right;
}
float Tank::getZPos(){
	return forward;
}
void Tank::Move(float x_position, float z_position, bool LR) {
	forward = z_position;
	left_right = x_position;
	if (LR == true)
		this->Angle += 0.687;
	if (LR == false)
		this->Angle -= 0.687;
}

void Tank::draw() {
	glPushMatrix();
	
	glTranslatef(left_right, pos_y, forward);
	glRotatef(Angle + 270, 0, 1, 0);
	if (InsideView) {
		
		Body[1].draw();
		SteeringWheel[CounterSteeringWheel].draw();
		glPushMatrix();
		glTranslatef(0, 0.22, 0);
		Picture.draw();
		glPopMatrix();
	}
	else {
		Body[0].draw();
	}
	Track.draw();
	int timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	deltaTime = timeSinceStart - oldTimeSinceStart;
	oldTimeSinceStart = timeSinceStart;
	for (int i = 0;i < WheelsAmount;i++)
		Wheel[i][CounterWheel].draw();
	if (InsideView)
		glTranslatef(0, 0.05, 0);
	Tower[CounterTower].draw();
	glPopMatrix();
}

void Tank::setFall(bool is_falling){
	fall = is_falling;
}

void Tank::Update(){
	if (fall){
		pos_y-=0.01*mass*gravity;
	}
}
void Tank::RotateTowerR() {
	if (CounterTower < TowerFrames - 2)
		CounterTower++;
	else
		CounterTower = 0;
}

void Tank::RotateTowerL() {
	if (CounterTower > 0)
		CounterTower--;
	else
		CounterTower = TowerFrames - 2;
}

void Tank::RotateSteeringWheelL() {
	if (CounterSteeringWheel < SteeringWheelFrames - 2)
		CounterSteeringWheel++;
	else
		CounterSteeringWheel = 1;
}

void Tank::RotateSteeringWheelR() {
	if (CounterSteeringWheel > 1)
		CounterSteeringWheel--;
	else
		CounterSteeringWheel = SteeringWheelFrames - 2;
	cout << "Licznik -> " << CounterSteeringWheel<<endl;
}

void Tank::WheelAnimationUpdateF() {
	if (this->deltaTime > 2) {
		if (CounterWheel < WheelsFrames-2)
			CounterWheel++;
		else
			CounterWheel = 0;
	}
}
void Tank::WheelAnimationUpdateB() {
	if (this->deltaTime > 2) {
		if (CounterWheel > 0 )
			CounterWheel--;
		else
			CounterWheel = WheelsFrames-2;
	}
}

float Tank::getY(){
	return pos_y;
}

void Tank::setInsideView(bool y_n) {
	InsideView = y_n;
}
bool Tank::getInsideView(){
	return InsideView;
}
bool Tank::InsideView;












/*void Tank::Collision(Cube &obj) {
	if (obj.getY() < POS_Y) {
		obj.setFall(false);
	}
	else
		obj.setFall(true);
		}*/