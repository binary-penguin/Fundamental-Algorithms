#include <stdio.h>
#include <conio.h>
#include <String.h>
#include <windows.h>


struct Nodo{
    int clave;
    char nom[21];
    int tiempo;
    Nodo *prev, *next;
};

Nodo *primero, *ultimo, *actual, *nuevo;
int clave;
char nom[21], falso[2];
int tiempo;
int x;

bool busca_nodo() {
    do {
        printf("Indica la clave     :"); scanf("%d", &clave); gets(falso);
        if ((clave < 1) || (clave > 999999)) {
            printf("Error, valor fuera de rango");
        }
    } while ((clave < 1) || (clave > 999999));
    
    if (primero == NULL) return (false);
    actual = primero;

    /// CANT USE NULL
    do {

        if (clave == actual->clave) return true;
        actual = actual->next;

    } while (actual != primero);

    return false;
}

void agrega_nodo(){
    if (busca_nodo()) {
        printf("SE duplica\n");
        getche();
    }
    else {
        do {
            printf("Indica no: \n"); gets(nom);
            x = strlen(nom);

            if ((x < 1) || (x > 20)) {
                printf("Error en extrension\n");
                getche();
            }

        } while ((x < 1) || (x > 20));
        printf("Indica el tiempo    :"); scanf("%d", &tiempo); gets(falso);        

        // Inserta nodo

        nuevo = new Nodo;
        nuevo->clave = clave
        strcpy(nuevo->nombre, nombre);
        strcpy(nuevo->tiempo, tiempo);
        nuevo->prev = NULL;
        nuevo->next = NULL;

        if (primero == NULL) {
            primero = nuevo;
            primero->prev = primero;
            primero->next = primero;
            ultimo = primero;
        }
        else {
            nuevo ->prev = ultimo;
            ultimo->next = nuevo;
            nuevo->next = primero;
            ultimo = nuevo;
            primero->prev = ultimo;
        }
    
    }
}

void lista() {
    actual = primero;
    
    while (true) {
        printf("%6d %20s %d\n", actual->clave, actual->nombre, actual->tiempo);
        actual = actual -> next;
        // Time in ms
        //Sleep(actual->tiempo * 1000);
        Beep(500)
        // kbhit()
        if (kbhit()) x = getche();
        if (x == 's') break;
    }
}

void consultaNodo() {
    if (!busca_nodo()) {
        printf("ERROR, CLAVE inexistente\n");
    }
    else {
        printf("Nombre : %s\n", actual->nom);
        printf("Tiempo : %d\n", actual->tiempo);
    }
}

void cambio_nodo() {

    if (!busca_nodo()) {
        printf("ERROR, CLAVE inexistente\n");
        
    }
    else {
        printf("Indica el nuevo tiempo : %d\n"); scanf("%d", &tiempo); gets(falso);
        actual->tiempo = tiempo;
    }

}

void elimina_nodo(){

    if (!busca_nodo()) {
        printf("ERROR, CLAVE inexistente\n");
        
    }
    else {

        if (actual == primero) {
            primero = primero -> next;
            primero ->prev = ultimo;
            delete(actual);
        }
        else if (actual == ultimo) {
            ultimo = ultimo->prev;
            primero->prev = ultimo;
            delete(actual);
        }
        else {
            
        }
    }

}

void menu() 
{
    int op =0;

    while (op!= 7) {
        printf("\n\n");
        printf("1. Agregar nodo\n");
        printf("2. Eliminar nodo\n");
        printf("3. Consultar nodo\n");
        printf("4. Cambios nodo\n");
        printf("5. Lista\n");
        printf("6. Lista Invertida\n");
        printf("7. END\n");

        printf("Indica:     "); scanf("%d", &op); gets(falso);
        
        if (op == 1) agrega_nodo();
        if (op == 5) lista();
    }

    
}

int main() {
    menu();
}