# include <stdio.h>

class Uno {
    public:
        int x;
    public:
        void muestra() {
            printf("El valor del atrivuto es : %d", x);
        }


};

int main() {
    Uno objeto;
    objeto.x = 5;
    objeto.muestra();
}