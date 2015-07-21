#pragma once
#include <GL/glew.h>
#include <iostream>
#include <stdio.h>
//----------------------
#include <GL/freeglut.h>
#include <SOIL.h>
#include <glm/glm.hpp>
#include <time.h>
//-----------KLASY----------
#include "TextureHandler.h"
#include "Camera.h"
#include "Loader.h"
//---------MODELE--------------
#include "Cube.h"
#include "Floor.h"
#include "Tank.h"
#include "Grass.h"
#include "Tree.h"
#include "Skybox.h"

/* KOLORKI */
#define YELLOW 1.0f, 1.0f, 0.5f, 1.0f // ZOLTY
#define PINK 0.97f, 0.24f, 0.71f, 1.0f // ROZOWY
#define BLACK 0.0f, 0.0f, 0.0f, 0.0f // CZARNY
#define WHITE 1.0f, 1.0f, 1.0f, 1.0f // BIA£Y
//--------------------------------------------------------------//
// Szerokoœæ, wysokoœæ okna
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

using namespace std;

Camera FreeCamera; // Klasa kamery
Cube WoodenBox[5]; // Skrzynki
Floor Terrain; // Pod³oga
Tank Player; // Czo³g i wszystkie jego elementy sk³adowe
Grass grass[50]; // trawa
Tree tree[50]; // drzewa
Skybox sky[2]; // skyboxy , 1 - dzieñ, 2 - noc

float Zoom = 1; // zmienna s³u¿¹ca do przybli¿ania/oddalania
bool ChangeSky = false; // zmienna do zmiany nieba na dzien/noc

// Pozycja œwiat³a na scenie
float posLight0[4] = { -1.0f, 1.0f, 1.0f, 0.0f };
float ambLight0[4] = { 1.8f, 1.8f, 1.8f, 1.5f };
float difLight0[4] = { 0.5f, 0.5f, 0.5f, 1.0f };

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(WHITE);
	glLoadIdentity();
    gluPerspective(45.0f*Zoom, 1, 0.1, 1000.0); // * Zoom, przybli¿a lub oddala
	glMatrixMode(GL_MODELVIEW); 
	// Ustawienia dotycz¹ce œwiat³a
	glPushMatrix();
	glLightfv(GL_LIGHT0, GL_POSITION, posLight0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambLight0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, difLight0);
	glEnable(GL_LIGHT0);
	glPopMatrix();
	FreeCamera.Start();

	// Po kliknieciu F1 zmiana nieba na noc
	if (ChangeSky)
		sky[1].draw();
	else
		sky[0].draw();

	// Rysowanie skrzynek
	for (int i = 0; i < 5; i++) {
		WoodenBox[i].draw();
		WoodenBox[i].Update();
		Terrain.Collision(WoodenBox[i]); // Kolizja skrzynki z pod³og¹
	}
	//Rysowanie pod³ogi
	Terrain.draw();
	for (int i = 0; i < 50; i++){
		grass[i].draw();
		tree[i].draw();
	}
	Player.draw(); // Rysowania gracza (czo³gu)
	Player.Update();
	Terrain.Collision(Player);
	

	glutPostRedisplay();
	glutSwapBuffers();
}

void processKeys(unsigned char key, int x, int y) {
	switch (key) {
	case 27: // Wyjscie klawisz ESC
		exit(0);
		break;
	case 'q': // Obrót sam¹ kamer¹
		FreeCamera.Update(Camera::Q);
		break;
	case 'a': // Obrót wie¿yczki
		Player.RotateTowerR();
		break;
	case 'd': // Obrót wie¿yczki
		Player.RotateTowerL();
		break;
	case 'e': // Obrót sam¹ kamer¹
		FreeCamera.Update(Camera::E);
		break;
	case '+': // Przyblizenie
		Zoom -= 0.1;
		break;
	case '-': // Oddalenie
		Zoom += 0.1;
		break;
	case 'o': // Przyblizenie
		FreeCamera.setRotateView(true);
		break;
	case 'p': // Oddalenie
		FreeCamera.setRotateView(false);
		break;
	}

}
void SpecialInput(int key, int xx, int yy)
{
	switch (key) {
	case GLUT_KEY_LEFT: // Lewo
		FreeCamera.Update(Camera::LEFT_ARROW);
		Player.Move(FreeCamera.getTargetXPos(), FreeCamera.getTargetZPos(), true);
		Player.WheelAnimationUpdateF();
		if (ChangeSky)
			sky[1].Move(FreeCamera.getTargetXPos(), FreeCamera.getTargetZPos());
		else
			sky[0].Move(FreeCamera.getTargetXPos(), FreeCamera.getTargetZPos());
		break;
	case GLUT_KEY_RIGHT: // Prawo
		FreeCamera.Update(Camera::RIGHT_ARROW);
		Player.Move(FreeCamera.getTargetXPos(), FreeCamera.getTargetZPos(), false);
		Player.WheelAnimationUpdateB();
		if (ChangeSky)
			sky[1].Move(FreeCamera.getTargetXPos(), FreeCamera.getTargetZPos());
		else
			sky[0].Move(FreeCamera.getTargetXPos(), FreeCamera.getTargetZPos());
		break;
	case GLUT_KEY_UP: // Do przodu
		FreeCamera.Update(Camera::UP_ARROW);
		Player.Move(FreeCamera.getTargetXPos(), FreeCamera.getTargetZPos());
		Player.WheelAnimationUpdateB();
		if (ChangeSky)
			sky[1].Move(FreeCamera.getTargetXPos(), FreeCamera.getTargetZPos());
		else
			sky[0].Move(FreeCamera.getTargetXPos(), FreeCamera.getTargetZPos());
		break;
	case GLUT_KEY_DOWN: // Do ty³u
		FreeCamera.Update(Camera::DOWN_ARROW);
		Player.Move(FreeCamera.getTargetXPos(), FreeCamera.getTargetZPos());
		Player.WheelAnimationUpdateF();
		if (ChangeSky)
			sky[1].Move(FreeCamera.getTargetXPos(), FreeCamera.getTargetZPos());
		else
			sky[0].Move(FreeCamera.getTargetXPos(), FreeCamera.getTargetZPos());
		break;
	case GLUT_KEY_F9: // Widok z kokpitu
		FreeCamera.setInsideView();
		Player.Move(FreeCamera.getTargetXPos(), FreeCamera.getTargetZPos());
		break;
	case GLUT_KEY_F10: // Zrzut ekranu
		TextureHandler::getScreenShoot();
		break;
	case GLUT_KEY_F11: // Zmiana kamery
		FreeCamera.setHorizontalView();
		break;
	case GLUT_KEY_F1: // W³¹czenie œwiat³a
		glEnable(GL_LIGHTING);
		ChangeSky = true;
		break;
	case GLUT_KEY_F2: // Wy³¹czenie œwiat³a
		glDisable(GL_LIGHTING);
		ChangeSky = false;
		break;
	}
	//glutPostRedisplay();
}
void processMouse(int x, int y) {
	if (Player.getInsideView()){
		// Koordynaty prawej strony kierownicy, gdy gracz nacisnie przycisk na tej czêœci kierownicy, to czo³g zaczyna skrêcaæ w prawo...
		if (x >= 294 && x <= 493 && y >= 364 && y <= 532){ 
			cout << "Prawa czesc kierownicy..." << endl << endl;
			FreeCamera.Update(Camera::RIGHT_ARROW);
			Player.Move(FreeCamera.getTargetXPos(), FreeCamera.getTargetZPos(), false);
			Player.RotateSteeringWheelR();
		}
		// Analogicznie, tylko w lewo.
		if (x >= 23 && x <= 146 && y >= 364 && y <= 532){
			cout << "Lewa czesc kierownicy..." << endl << endl;
			FreeCamera.Update(Camera::LEFT_ARROW);
			Player.Move(FreeCamera.getTargetXPos(), FreeCamera.getTargetZPos(), true);
			Player.RotateSteeringWheelL();
		}
	}
	//Koordynaty klikniêcia
	cout << "Mysz.x: " << x << endl;
	cout << "Mysz.y: " << y << endl;
}

int main(int argc, char **argv)
{
	srand(time(NULL)); 

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	cout << "#FreeGLUT v. " << glutGet(GLUT_VERSION) << endl; // SHOW VERSION
	cout << "#SOIL 1.16 is working!" << endl;
	glutCreateWindow("TANK 3D v. 1.0");
	
	glewInit();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_MULTISAMPLE);
	glEnable(GL_TEXTURE_2D);
	glDepthFunc(GL_LESS);

	/*----------------- WCZYTYWANIE ZASOBÓW ----------------*/
	// SKRZYNKI
	for (int i = 0; i < 5; i++)
		WoodenBox[i].setTexture("Assets/Textures/wood_box.jpg");
	for (int i = 0; i < 5; i++) {
		WoodenBox[i].setPostion(rand() % 5, 5, rand() % 6);
		WoodenBox[i].setRotate(rand() % 360);
	}
	// TRAWA
	grass[0].setTexture("Assets/Textures/wheel2.jpg");
	for (int i = 0; i < 50; i++) {
		grass[i].loadModel("Assets/Objects/grass1.obj");
		grass[i].randPosition(rand()%100-100, rand()%100-100);
	}
	// DRZEWA
	tree[0].setTexture("Assets/Textures/wheel2.jpg");
	for (int i = 0; i < 50; i++) {
		tree[i].loadModel("Assets/Objects/tree.obj");
		tree[i].randPosition(rand() % 100-100, rand() % 100-100);
	}
	//POD£OGA
	Terrain.setTexture("Assets/Textures/terrain.jpg");
	//CZO£G
	Player.Body[0].setTexture("Assets/Textures/metal.jpg");
	Player.Body[0].loadModel("Assets/Objects/Tiger_body.obj");
	Player.Body[1].loadModel("Assets/Objects/Tiger_body2.obj");
	Player.Track.setTexture("Assets/Textures/forest.jpg");
	Player.Track.loadModel("Assets/Objects/TankTrack.obj");
	Player.LoadWheels();
	Player.LoadSteeringWheel();
	Player.LoadTower();
	Player.Picture.setTexture("Assets/Textures/wojtek3.jpg");
	Player.Picture.loadModel("Assets/Objects/wojtek5.obj");
	// SKYBOX
	sky[0].setTexture("Assets/Textures/skybox.jpg");
	sky[0].loadModel("Assets/Objects/skybox.obj");

	sky[1].setTexture("Assets/Textures/nightskybox.jpg");
	sky[1].loadModel("Assets/Objects/skybox2.obj");

	/*-------------------------------------------------------*/

	glutDisplayFunc(Display);
	glutIdleFunc(Display);
	glutKeyboardFunc(processKeys);
	glutSpecialFunc(SpecialInput);
	glutMotionFunc(processMouse);
	glutMainLoop();
	return 0;
}
