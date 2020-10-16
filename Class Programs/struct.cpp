# include <stdio.h>
# include <String.h>

struct Nodo {
    int mat;
    char nom[21];
};

main() {
    Nodo obj;
    obj.mat = 10;
    strcpy(obj.nom, "Juan");
    printf("Mat: %d\n", obj.mat);
    printf("Nom: %s", obj.nom);
}