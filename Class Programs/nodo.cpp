# include <stdio.h>
# include <String.h>

class Nodo {
    public:
        int mat;
        char nom[21], car[5];
    public:
        void muestra() {
            printf("Mat%d\n", mat);
            printf("Nom%s\n", nom);
            printf("Car%s\n", car);
        }


};

int main() {
    Nodo *objeto = new Nodo;
    objeto -> mat = 123;
    strcpy(objeto -> nom, "Juan");
    strcpy(objeto -> car, "ITC");
    objeto -> muestra();
    printf("La dir es: %d ", objeto);
}