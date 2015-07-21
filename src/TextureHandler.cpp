#include "TextureHandler.h"

string TextureHandler::Path;
unsigned int TextureHandler::ScreenShotNumber = 0;
// Metoda wczytuj¹ca tekstury do przekazanej zmiennej GLuint
void TextureHandler::setTexture(GLuint &Texture2D, string Path) {
	if (Path != "") {
		const char  *FilePath = Path.c_str();
		cout << "\nWczytywanie tekstury z pliku ->" << FilePath;
		Texture2D = SOIL_load_OGL_texture
			(
				FilePath,
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
				);
		if (Texture2D == NULL) {
			printf("\nSciezka pliku jest nieprawidlowa, lub plik nieistnieje -> '%s'\n", SOIL_last_result());
		}
	}
	else
		cout << "Nie podano sciezki pliku!\n";
};
// Tworzenie zrzutów ekranu gry
void TextureHandler::getScreenShoot(){
	string filename;
	filename = "screenshot" + to_string(TextureHandler::ScreenShotNumber)
		+ ".bmp";
	const char  *File = filename.c_str();
	GLuint save_result = SOIL_save_screenshot
		(
			File,
			SOIL_SAVE_TYPE_BMP,
			0, 0, WINDOW_WIDTH, WINDOW_HEIGHT
		);
	cout << "\nZrzut ekranu zapisano do pliku -> screenshot" << ScreenShotNumber << ".bmp";
	ScreenShotNumber++;
} 