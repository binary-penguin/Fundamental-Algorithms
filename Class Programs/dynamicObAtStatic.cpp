# include <stdio.h>

class *Uno {
    public:
        int x, y;
    public:
        void muestra() {
            printf("El valor del atributo es : %d\n", x);
            printf("El valor del atributo es : %d\n", y);

        }


};

int main() {
    Uno *objeto = new Uno;
    objeto.x -> 10;
    objeto.y -> 10;
    objeto -> muestra();
    printf("La dir es: %d ", objeto);
}