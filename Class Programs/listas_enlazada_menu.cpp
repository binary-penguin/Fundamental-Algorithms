# include <stdio.h>
# include <String.h>

struct Nodo {
    char fol[11] = {'\0'};
    char nom[13] = {'\0'};
    Nodo *next;

};

Nodo *primero, *ultimo, *nuevo;
char n[11] = {'\0'};
char f[11] = {'\0'};

void pide_datos() {
    printf("Indica el folio :");
    fflush(stdin);
    fgets(f, sizeof(f), stdin);
    strtok(f, "\n");
    fflush(stdin);
    printf("Indica el nom :");
    fflush(stdin);
    fgets(n, sizeof(n), stdin);
    strtok(n, "\n");
    fflush(stdin);

    strcpy(nuevo ->fol, f);
    strcpy(nuevo ->nom, n);
    nuevo -> next = NULL;
}


void inserta_inicio() {
    if (primero == NULL) {
        primero = nuevo;
        ultimo = nuevo;
    }
    else {

        nuevo -> next = primero;
        primero = nuevo;
    }


}

void inserta_inicio() {

    if (primero == NULL) {
        primero = nuevo;
        ultimo = nuevo;
    }
    else {
        
        nuevo -> next = ultimo;
        ultimo = nuevo;
    }


}

void muestra_lista() {
    Nodo *actual;
    actual = primero;
    while (actual != NULL) {
        printf("%d  %s\n", actual->fol, actual->nom);
    }
}

void elimina_inicio() {
    if (primero == NULL) {
        printf("Error, la lista ta vacía..\n");
        fflush(stdin);
    }
    else {
        
    }
}
