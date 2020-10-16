# include <stdio.h>
# include <String.h>
# include <string>
# include <fstream>

using namespace std;

/*
mat 10 + 2
nom 21 + 2
ap  21 + 2
car 4  + 2



*/
char matIn[12] = {'\0'};
char nomIn[23] = {'\0'};
char apIn[23] = {'\0'};
char carIn[6] = {'\0'};

struct Nodo{
    char matIn[12] = {'\0'};
    char nomIn[23] = {'\0'};
    char apIn[23] = {'\0'};
    char carIn[6] = {'\0'};
    Nodo *next;
};

Nodo *primero, *ultimo, *nuevo, *actual, *previo;


void insertar_nodo_final() {
    if (primero == NULL) {
        primero = nuevo;
        ultimo = nuevo;
    }
    else {
        ultimo -> next = nuevo;
        ultimo = nuevo;
    }

}

void lista_alumnos() {
    if (primero == NULL) {
        printf("Error, la lista est%c vac%a\n", 160,161);
    }
    else {
        actual = primero;
        while (actual != NULL) {
            printf("%9s %20s %20s %3s\n", actual->matIn, actual -> nomIn, actual -> carIn);
            actual = actual -> next;
        }
    }
}


bool busca_nodo() {
    actual = primero;
    previo = primero;
    while (actual != NULL) {
        if (strcmp(actual ->matIn, matIn)==0) return true;
    }
    return false;
}

void carga_archivo_lista() {

    ifstream arch;
    arch.open("alumnos.txt", ios::in);
    while (!arch.eof()) {
        arch >> matIn >> nomIn >> apIn >> carIn;
        // Avoid duplicate print
        if (!arch.eof()) {

        }
    }
}

void descarga_lista_archivo() {
    ofstream arch;
    arch.open("alumnos.txt", ios::out);
    actual = primero;
    while (actual != NULL) {
        arch << actual->matIn << " " << actual-> nomIn << " " << actual-> apIn << " " actual->carIn << "\n";
        actual = actual->next;
    }
}



void consulta_alumnos(){
    printf("Indica la matricula a buscar: ");
    fgets(matIn, sizeof(matIn), stdin);
    busca_nodo();
    
    if (!busca_nodo()) printf("Error, no existe");

    else {
        printf("Nombre  : %s\n", actual -> nomIn);
        printf("Ap.P  : %s\n", actual -> apIn);
        printf("Carreta  : %s\n", actual -> carIn);

    }
}

void cambios_alumnos() {
    printf("Indica la mat a modif :");
    fgets(matIn, sizeof(matIn), stdin);
    strtok(matIn, "\n");
    strupr(matIn);
    fflush(stdin);

    if (!busca_nodo()) {
        printf("ERROR, mat no existe");
        getchar();
        fflush(stdin);

    }
    else {
        printf("Indica la carrera new: \n");
        fgets(carIn, sizeof(carIn), stdin);
        strtok(carIn, "\n");
        strupr(carIn);
        fflush(stdin);
        strcpy(actual -> carIn, carIn);
        descarga_lista_archivo();

    }
}


void alta_alumnos() {
    
    printf("Indica mat: ");
    fgets(matIn, sizeof(matIn), stdin);
    strtok(matIn, "\n");
    fflush(stdin);

    if (busca_nodo()) {
        printf("Error, existe duplicado ....\n");
        getchar();
        fflush(stdin);
    }
    else {

        printf("Indica nom: ");
        fgets(nomIn, sizeof(nomIn), stdin);
        strtok(nomIn, "\n");
        fflush(stdin);

        printf("Indica ap: ");
        fgets(apIn, sizeof(apIn), stdin);
        strtok(apIn, "\n");
        fflush(stdin);

        printf("Indica mat: ");
        fgets(carIn, sizeof(carIn), stdin);
        strtok(carIn, "\n");
        fflush(stdin);

        nuevo = new Nodo;
        strcpy(nuevo -> matIn, matIn);
        strcpy(nuevo -> nomIn, nomIn);
        strcpy(nuevo -> apIn, apIn);
        strcpy(nuevo -> carIn, carIn);
        nuevo-> next = NULL;
        insertar_nodo_final();
    }
}



void menu() {
    char userInput[3] = {'\0'};

    printf("\n\n1) Alta de alumnos");
    printf("1) Altas de alumnos");
    printf("2) Bajas de alumnos");
    printf("3) Cambios de carrera");
    printf("4) Consultas de alumnos");
    printf("5) Lista de alumnos");
    printf("6) Lista de alumnos");
    printf("7) Terminar");
    printf("Indica opcion: ");
    fgets(userInput, sizeof(userInput), stdin);
    strtok(userInput, "\n");
    stoi(userInput);
    fflush(stdin);

    if (atoi(userInput) == 1) alta_alumnos();
}