#include "Loader.h"

bool Loader::loadOBJ(const char * path, std::vector<glm::vec3> & out_vertices, std::vector<glm::vec2> & out_uvs,
					std::vector<glm::vec3> & out_normals )
{
	printf("\nWczytywanie pliku OBJ -> %s...\n", path);

	std::vector<unsigned int> vertexIndices, uvIndices, normalIndices; // kontenery do indekst�w
	std::vector<glm::vec3> temp_vertices; // wierzcho�ki tymczasowe
	std::vector<glm::vec2> temp_uvs; // koordynaty tekstur
	std::vector<glm::vec3> temp_normals; // normalne


	FILE * file = fopen(path, "r"); // otwarcie pliku
	if (file == NULL) {
		printf("Z�y format pliku!\n");
		getchar();
		return false;
	}

	while (1) { // czytanie zawarto�ci z pliku

		char lineHeader[128];
		// wczytanie linii
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break; // Koniec pliku, zako�czenie p�tli
		if (strcmp(lineHeader, "v") == 0) { // je�eli pierwsz� liter� jest 'v' to czytam wierzcho�ki
			glm::vec3 vertex; // wbudowany wektor 3 wymiarowy, zawarty w bibliotece glm
			fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z); //czytamy wszystkie 3 koordynaty wierzcho�ka
			temp_vertices.push_back(vertex); // wrzucamy do stworzonego wcze�niej kontenera
		}
		else if (strcmp(lineHeader, "vt") == 0) { // je�eli 'vt' to s� to wsp�rz�dne tekstur
			glm::vec2 uv; // podobnie jak poprzednio tylko jest to wektor 2 wymiarowy
			fscanf(file, "%f %f\n", &uv.x, &uv.y);
			//uv.y = -uv.y; // Invert V coordinate since we will only use DDS texture, which are inverted. Remove if you want to use TGA or BMP loaders.
			temp_uvs.push_back(uv); // dodanie wierzcho�ka do kontenera z teksturami
		}
		else if (strcmp(lineHeader, "vn") == 0) { // czytanie normalnych, analogicznie jak przy czytaniu wierzcho�k�w
			glm::vec3 normal;
			fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
			temp_normals.push_back(normal);
		}
		else if (strcmp(lineHeader, "f") == 0) { // rozpracowanie �cian
			std::string vertex1, vertex2, vertex3; // 3 oddzielne stringi {wierzcho�ek, uv, normalny}
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3]; // po 3 poniewa� w ka�dym wierszu s� 3 dane na temat �cian
			int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]); //wczytanie warto�ci z pliku (poza znakami '/')
			if (matches != 9) { //musi by� 9, znaczy to tyle �e tekstury te� musz� by�
				printf("Cos poszlo nie tak, sprobuj wyeksportowac uzywajac innych opcji\n"); //blad
				return false;
			}
			vertexIndices.push_back(vertexIndex[0]); // zapisujemy do kontenera (typ unsigned int) indeksy kolejnych wierszy 'f'
			vertexIndices.push_back(vertexIndex[1]);
			vertexIndices.push_back(vertexIndex[2]);
			uvIndices.push_back(uvIndex[0]);
			uvIndices.push_back(uvIndex[1]);
			uvIndices.push_back(uvIndex[2]);
			normalIndices.push_back(normalIndex[0]);
			normalIndices.push_back(normalIndex[1]);
			normalIndices.push_back(normalIndex[2]);
		}
		else {
			// Probably a comment, eat up the rest of the line
			char stupidBuffer[1000];
			fgets(stupidBuffer, 1000, file);
		}

	}
	/*NORMALIZACJA
	Przy �cianie, za��my: 'f 8/11/7 7/12/7 6/10/7'(koordynaty pierwszego wierzcho�ka tr�jk�ta),
	rozk�adamy dane w nast�puj�cy spos�b:
	dla ->8/11/7<-
	8 - oznacza �e trzeba wzi�� wierzcho�ek 8smy z naszego 'temp_vertices'(UWAGA! Indeksy w pliku .obj dla kolejnych wierszy zaczynaj� si� od 1)
	11 - oznacza kt�re koordynaty tekstury musimy wzi�� z naszego 'temp_uvs'
	7 - oznacza kt�re normalnie nale�y wzi��...
	*/
	// dla ka�dego wierzcho�ka tr�jk�ta...
	fclose(file);
	for (unsigned int i = 0; i<vertexIndices.size(); i++) {

		// pobieramy id
		unsigned int vertexIndex = vertexIndices[i];
		unsigned int uvIndex = uvIndices[i];
		unsigned int normalIndex = normalIndices[i];

		// uk�adamy dane w odpowiedni spos�b
		glm::vec3 vertex = temp_vertices[vertexIndex - 1];
		glm::vec2 uv = temp_uvs[uvIndex - 1];
		glm::vec3 normal = temp_normals[normalIndex - 1];

		// wrzucamy dane do kontener�w przekazanych poprzez referencje
		out_vertices.push_back(vertex);
		out_uvs.push_back(uv);
		out_normals.push_back(normal);

	}
	return true;
}


