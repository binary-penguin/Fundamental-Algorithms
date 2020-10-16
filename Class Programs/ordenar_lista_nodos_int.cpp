# include <stdio.h>
# include <String.h>


void ordena_lista_nodos() {
    Nodo *actual_i, *actual_j, *aux;

    actual_i = primero;
    auxiliar = new Nodo;
    
    while (actual_i != NULL) {
        actual_j = actual_i -> next;

        while (actual_j != NULL) {

            if (actual_i-> valor > actual_j -> valor) {
                aux -> valor = actual_i -> valor;
                actual_i -> valor = actual_j -> valor;
                actual_j -> valor = auxiliar -> valor;
            }
            actual_j = actual_j -> next;
        }
        actual_i = actual_i -> next;
    }
}

int main() {
    
}