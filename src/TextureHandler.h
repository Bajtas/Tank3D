#pragma once
#include <string>
#include <iostream>
#include <SOIL.h>
#include <GL/freeglut.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

using namespace std;

class TextureHandler
{
public:
	static void setTexture(GLuint &Texture2D, string Path); // Metoda wczytuj�ca tekstur� do przekazanego poprzez referencje parametru
	static void getScreenShoot(); // Metoda zapisuj�ca zrzut ekranu na dysk twardy komputera
private:
	static string Path;
	static unsigned int ScreenShotNumber;
};

