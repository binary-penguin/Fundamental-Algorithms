# include <stdio.h>
# include <String.h>
# include <fstream>
# include <iostream>

using namespace std;

/*
Estructura

Placas char (7 posiciones) ---> KEY FIELD cannot be modified + 2
Marca  char (20 posiciones) + 2
Tipo   char	(20 posiciones) + 2
Ano    int  (4 posicion) + 2 
Precio int  (4 posicion) + 2 
*/

char platesIn[9] = {'\0'};
char brandIn[22] = {'\0'};
char typeIn[22] = {'\0'};
char userIn[3] = {'\0'};
char yearIn[6] = {'\0'};
char priceIn[6] = {'\0'}; 
char carToSearch[9] = {'\0'};
char query[22] = {'\0'};
char platesF[9] = {'\0'};
char brandF[22] = {'\0'};
char typeF[22] = {'\0'};
char yearF[6] = {'\0'};
char priceF[6] = {'\0'}; 

bool searchCar(char carToSearchPointer[], int size) {


	for(int i = 0; i < size; i++) {
		carToSearch[i] = carToSearchPointer[i];
	}
	
	ifstream file;
	file.open("cars.txt", ios::in);


	while (file >> platesF >> brandF >> typeF >> yearF >> priceF) {
		if (strcmp(platesF, carToSearch) == 0) {
			file.close();
			return true;
		}
	}
	file.close();
	return false;

}

void addCars() {
	int yearInt;
	float priceInf;
	int flag = 1;

	
	// Plates loop.
	while (flag) {
		printf("Plates: ");
		fgets(platesIn, sizeof(platesIn), stdin);
		strupr(platesIn);
		strtok(platesIn, "\n");
		if (((platesIn[6] == 0) && (platesIn[7] == 0) && (platesIn[8] == 0)) || 
		((platesIn[6] != 0) && (platesIn[7] != 0) && (platesIn[8] == 0)) ||
		((platesIn[6] != 0) && (platesIn[7] != 0) && (platesIn[8] != 0))) {
			 printf("ERROR, PLATES MUST HAVE A LENGTH OF SEVEN.\n");
			 fflush(stdin);
			 getchar();
			 fflush(stdin);
		}
	
		else {
			if(!searchCar(platesIn, sizeof(platesIn))) flag = 0;
			else {
				printf("ERROR, CAR ALREADY IN DATABASE\n");
				fflush(stdin);
				getchar();
				fflush(stdin);
				return;
			}
		}
	}
	// Brand loop.
	flag = 1;
	while (flag) {
		printf("Marca: ");
		fgets(brandIn, sizeof(brandIn), stdin);
		strupr(brandIn);
		strtok(brandIn, "\n");
		
		//ASESORIA.
		if (((brandIn[19] != '\0') && (brandIn[20] != '\0') && (brandIn[21] != '\0')) || 
		((brandIn[19] != '\0') && (brandIn[20] != '\0') && (brandIn[21] == '\0'))) {
			 printf("ERROR, BRAND MUST HAVE A MAX LENGTH OF 22.\n");
			 fflush(stdin);
			 getchar();
		}
		else flag = 0;
		for(int c = 0; c < sizeof(brandIn); c++) {
			if (brandIn[c] == ' ') {
				brandIn[c] = '_';
				break;
			}
		}
	}
	// Type loop.
	flag = 1;
	while (flag) {
		printf("Tipo: ");
		fgets(typeIn, sizeof(typeIn), stdin);
		strupr(typeIn);
		strtok(typeIn, "\n");
		if (((typeIn[19] != '\000') && (typeIn[20] != '\000') && (typeIn[21] != '\000')) || 
		((typeIn[19] != '\000') && (typeIn[20] != '\000') && (typeIn[21] == '\000'))) {
			 printf("ERROR, TYPE MUST HAVE A MAX LENGTH OF 22.\n");
			 fflush(stdin);
			 getchar();
		}
		else flag = 0;
		for(int c = 0; c < sizeof(typeIn); c++) {
			if (typeIn[c] == ' ') {
				typeIn[c] = '_';
				break;
			}
		}
	}
	// Year loop.
	flag = 1;
	while (flag) {
		printf("A%co: ", 164);
		fgets(yearIn, sizeof(yearIn), stdin);
		strtok(yearIn, "\n");
		yearInt = atoi(yearIn);
		if (yearInt < 1900) {
			printf("ERROR, YEAR MUST BE GREATER OR EQUAL THAN 1900.\n");
			fflush(stdin);
			getchar();
			

		}
		else flag = 0;

	}
	// Price loop.
	flag = 1;
	while (flag) {
		printf("Price: ");
		fgets(priceIn, sizeof(priceIn), stdin);
		strtok(priceIn, "\n");
		priceInf = atof(priceIn);
		if (priceInf < 1.0) {
			printf("ERROR, PRICE MUST BE GREATER THAN 1.\n");
			fflush(stdin);
			getchar();
		}
		else flag = 0;
	}
	fflush(stdin);
	printf("Type Y/N to record the new car: ");
	fgets(userIn, sizeof(userIn), stdin);
	strtok(userIn, "\n");
	strupr(userIn);
	fflush(stdin);
	
	if (userIn[0] == 'Y') {
		ofstream file;
		file.open("cars.txt", ios::app);
		file << platesIn << " " << brandIn << " " << typeIn << " " << yearInt << " " << priceInf << "\n";
		file.close();
	}
}

void genCatalog(char option[]) {
	char userIn[22] = {'\0'};


	ifstream file;
	file.open("cars.txt", ios::in);

	// Check for errors
	if (file.fail()) {
		printf("Error Opening File.\n");
		exit;
	}
	
	
	// Define query
	if (strcmp(option, "c") == 0) strcpy(query, "plates");
	if (strcmp(option, "d") == 0) strcpy(query, "brand");
	if (strcmp(option, "e") == 0) strcpy(query, "model");

	// Read query
	if ((strcmp(option, "c") == 0) || (strcmp(option, "d") == 0) || (strcmp(option, "e") == 0)) {
		printf("Introduce your %s to filter: ", query);
		fgets(userIn, sizeof(userIn), stdin);
		strtok(userIn, "\n");
		strupr(userIn);
		fflush(stdin);
	}
	
	
	// Read a file until you've reach the end
	while (file >> platesF >> brandF >> typeF >> yearF >> priceF) {

		// Change '_' for ' ' LOOP. [brand]
		for (int c = 0; c < sizeof(brandF); c++) {
			if (brandF[c] == '_') {
				brandF[c] = ' ';
				break;
			}
		}
		// Change '_' for ' ' LOOP. [type]
		for (int c = 0; c < sizeof(typeF); c++) {
			if (typeF[c] == '_') {
				typeF[c] = ' ';
				break;
			}
		}

		// General
		if (strcmp(option, "b") == 0) {
		printf("%7s %20s %20s %4s %5s\n", platesF, brandF, typeF, yearF, priceF);
		}
		
		// Filter by plates
		if (strcmp(option, "c") == 0) {
			if (strcmp(userIn, platesF) == 0) printf("%7s %20s %20s %4s %5s\n", platesF, brandF, typeF, yearF, priceF);
		}
		
		// Filter by brand
		if (strcmp(option, "d") == 0) {
			if (strcmp(userIn, brandF) == 0) printf("%7s %20s %20s %4s %5s\n", platesF, brandF, typeF, yearF, priceF);
		}
		
		// Filter by model
		if (strcmp(option, "e") == 0) {
			if (strcmp(userIn, typeF) == 0) printf("%7s %20s %20s %4s %5s\n", platesF, brandF, typeF, yearF, priceF);
		}
		
	}
	file.close();
	
}

void menu() {
	
	char userInput[3];
	int userWannaStay = 1;
	
	while (userWannaStay) {
		
		fflush(stdin);
		printf("\na. Add cars\n");
		printf("b. General catalog\n");
		printf("c. List cars by plates\n");
		printf("d. List cars by brand\n");
		printf("e. List cars by model\n");
		printf("f. Exit\n");
		printf("Choose one option and hit [ENTER]: ");
		fgets(userInput, sizeof(userInput), stdin);
		strtok(userInput, "\n");
		fflush(stdin);
		if (strcmp(userInput, "f") == 0) userWannaStay = 0;
		else if (strcmp(userInput, "a") == 0) addCars();
		else genCatalog(userInput);
	
	}
	
}

int main() {
	
	menu();
	return 5;
}


