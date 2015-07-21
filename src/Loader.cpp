#include "Loader.h"

bool Loader::loadOBJ(const char * path, std::vector<glm::vec3> & out_vertices, std::vector<glm::vec2> & out_uvs,
					std::vector<glm::vec3> & out_normals )
{
	printf("\nWczytywanie pliku OBJ -> %s...\n", path);

	std::vector<unsigned int> vertexIndices, uvIndices, normalIndices; // kontenery do indekstów
	std::vector<glm::vec3> temp_vertices; // wierzcho³ki tymczasowe
	std::vector<glm::vec2> temp_uvs; // koordynaty tekstur
	std::vector<glm::vec3> temp_normals; // normalne


	FILE * file = fopen(path, "r"); // otwarcie pliku
	if (file == NULL) {
		printf("Z³y format pliku!\n");
		getchar();
		return false;
	}

	while (1) { // czytanie zawartoœci z pliku

		char lineHeader[128];
		// wczytanie linii
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break; // Koniec pliku, zakoñczenie pêtli
		if (strcmp(lineHeader, "v") == 0) { // je¿eli pierwsz¹ liter¹ jest 'v' to czytam wierzcho³ki
			glm::vec3 vertex; // wbudowany wektor 3 wymiarowy, zawarty w bibliotece glm
			fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z); //czytamy wszystkie 3 koordynaty wierzcho³ka
			temp_vertices.push_back(vertex); // wrzucamy do stworzonego wczeœniej kontenera
		}
		else if (strcmp(lineHeader, "vt") == 0) { // je¿eli 'vt' to s¹ to wspó³rzêdne tekstur
			glm::vec2 uv; // podobnie jak poprzednio tylko jest to wektor 2 wymiarowy
			fscanf(file, "%f %f\n", &uv.x, &uv.y);
			//uv.y = -uv.y; // Invert V coordinate since we will only use DDS texture, which are inverted. Remove if you want to use TGA or BMP loaders.
			temp_uvs.push_back(uv); // dodanie wierzcho³ka do kontenera z teksturami
		}
		else if (strcmp(lineHeader, "vn") == 0) { // czytanie normalnych, analogicznie jak przy czytaniu wierzcho³ków
			glm::vec3 normal;
			fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
			temp_normals.push_back(normal);
		}
		else if (strcmp(lineHeader, "f") == 0) { // rozpracowanie œcian
			std::string vertex1, vertex2, vertex3; // 3 oddzielne stringi {wierzcho³ek, uv, normalny}
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3]; // po 3 poniewa¿ w ka¿dym wierszu s¹ 3 dane na temat œcian
			int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]); //wczytanie wartoœci z pliku (poza znakami '/')
			if (matches != 9) { //musi byæ 9, znaczy to tyle ¿e tekstury te¿ musz¹ byæ
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
	Przy œcianie, za³ó¿my: 'f 8/11/7 7/12/7 6/10/7'(koordynaty pierwszego wierzcho³ka trójk¹ta),
	rozk³adamy dane w nastêpuj¹cy sposób:
	dla ->8/11/7<-
	8 - oznacza ¿e trzeba wzi¹æ wierzcho³ek 8smy z naszego 'temp_vertices'(UWAGA! Indeksy w pliku .obj dla kolejnych wierszy zaczynaj¹ siê od 1)
	11 - oznacza które koordynaty tekstury musimy wzi¹æ z naszego 'temp_uvs'
	7 - oznacza które normalnie nale¿y wzi¹æ...
	*/
	// dla ka¿dego wierzcho³ka trójk¹ta...
	fclose(file);
	for (unsigned int i = 0; i<vertexIndices.size(); i++) {

		// pobieramy id
		unsigned int vertexIndex = vertexIndices[i];
		unsigned int uvIndex = uvIndices[i];
		unsigned int normalIndex = normalIndices[i];

		// uk³adamy dane w odpowiedni sposób
		glm::vec3 vertex = temp_vertices[vertexIndex - 1];
		glm::vec2 uv = temp_uvs[uvIndex - 1];
		glm::vec3 normal = temp_normals[normalIndex - 1];

		// wrzucamy dane do kontenerów przekazanych poprzez referencje
		out_vertices.push_back(vertex);
		out_uvs.push_back(uv);
		out_normals.push_back(normal);

	}
	return true;
}


