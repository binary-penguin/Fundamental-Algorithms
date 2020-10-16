# include <stdio.h>

class Uno {
    public:
        int *x;
    public:
        void muestra() {
             printf("El valor del atributo es : %d\n", x);
            printf("La direccion del atributo es : %d", *x);
        }


};

int main() {
    Uno objeto;
    objeto.x = new int;
    *(objeto.x) = 10;
    objeto.muestra();
}