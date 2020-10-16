# include <stdio.h>
# include <String.h>




struct Nodo {
    int fol;
    char nom[21];
    Nodo *next;
};
void inserta_inicio() {
    // This behaves as a set.
    int f;
    char n[21];
    print("Indica folio: "); scanf("%d", &f);
    fflush(stdin);
    printf("Indica el nombre: "); gets(n);

    // Create the new node.
    nuevo = new Nodo;
    nuevo -> fol = f;
    strcpy(nuevo -> nom, n);
    nuevo -> next = NULL;
    // Check if the list is empty.

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
    // This behaves as a set.
    int f;
    char n[21];
    printf("Indica folio: "); scanf("%d", &f);
    fflush(stdin);
    printf("Indica el nombre: "); gets(n);

    // Create the new node.
    nuevo = new Nodo;
    nuevo -> fol = f;
    strcpy(nuevo -> nom, n);
    nuevo -> next = NULL;
    // Check if the list is empty.

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

Nodo *primero;
Nodo *ultimo;
Nodo *nuevo;

main() {

    int userInput = 1;

    while (userInput == 1) {
        inserta_inicio();
        muestra_lista();
        printf("Quieres más, 1/Si, 2/No.");
        scanf("%d", userInput);
        fflush(stdin);
    }

}