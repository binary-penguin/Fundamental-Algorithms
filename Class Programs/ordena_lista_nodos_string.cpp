# include <stdio.h>
# include <String.h>
# include <fstream>

using namespace as std

    

struct Nodo {
    char nom[21], ap[21], am[21];
    Nodo *next;
};

Nodo *primero, *actual, *nuevo, *ultimo;
char nom[21], ap[21], am[21];

void pide_datos() {

    while ('2') {
        printf("Indica el nombre : "); gets(nom);
        if (strcmmp(nom, "x") == 0) break;
        printf("Indica el ap     : "); gets(ap);
        printf("Indica el am     : "); gets(am);
        
        else {
            nuevo = new Nodo;
            strcpy(nuevo -> nom, nom);
            strcpy(nuevo -> ap, ap);
            strcpy(nuevo -> am, am);
            nuevo -> next = NULL;


            if (primero == NULL) {
                primero = nuevo;
                ultimo = nuevp;
            }
            else {
                ultimo -> next = nuevo;
                ultimo = nuevo;
            }

        }
    }
}

void muestra_lista() {
    actual  = primero;
    while (actual != NULL) {
        printf("%20s    %20s    %20s\n", actual->nom, actual->ap, actual->am);
        actual = actual-> next;

    }
    printf("-------------------------------------------------\n");
    getche();

}

void carga_archivo() {
    ifstream arch;
    arch.open("datos.txt", ios::in);
    while ( arch >> nom >> ap >> am) {
        nuevo = New Nodo;
        strcpy(nuevo->nom, nom);
        strcpy(nuevo->ap, ap);
        strcpy(nuevo->am, am);
        nuevo-> next = NULL;

        if (primero == NULL) {
            primero = nuevo;
            ultimo = nuevo;
        }
        else {
            ultimo->next = nuevo;
            ultimo = nuevo;
        }
    }
    arch.close();
}

void descarga_lista() {
    actual = primero;
    ofstream arch;
    arch.open("datos.txt", ios::out);
    while (actual != NULL) {
        arch << actual -> nom << " " << actual -> ap << " " << actual -> am << "\n";

    }
    arch.close();
    
}

void ordenar_lista() {
    Nodo *actual_i, *actual_j, *aux;

    actual_i = primero;
    aux = new Nodo;
    
    while (actual_i != NULL) {
        actual_j = actual_i -> next;

        while (actual_j != NULL) {
            if (strcmp(actual_i -> ap, actual_j -> ap) == 1) {
                strcpy(auxiliar -> nom, actual_i -> nom);
                strcpy(auxiliar -> ap, actual_i -> ap);
                strcpy(auxiliar -> am, actual_i -> am);

                strcpy(actual_i -> nom = actual_j -> nom);
                strcpy(actual_i -> ap = actual_j -> ap);
                strcpy(actual_i -> am = actual_j -> am);

                strcpy(actual_j -> nom = aux -> nom);
                strcpy(actual_j -> ap = aux -> ap);
                strcpy(actual_j -> am = aux -> am);
            }
        }
        actual_j = actual_j -> next;

    }
    actual_i = actual_i -> next;

}


int main() {
    carga_archivo();
    ordenar_lista();
    pide_datos();
    muestra_lista();
    descarga_lista();
}


