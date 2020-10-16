# include <stdio.h>
# include <String.h>

class Nodo {
    public:
        int *x;
      
    public:
        void muestra() {
            printf("X: %d\n", *x);
            printf("Dirección: %d\n", x);
        }


};

int main() {
    Nodo *objeto = new Nodo;
    objeto->x = new int;
    *(objeto -> x) = 10;
    objeto -> muestra();
    printf("La dir del obj: %d", objeto);

}