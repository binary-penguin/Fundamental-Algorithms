# include <stdio.h>
# include <String.h>
# include <iostream>


struct Dog {
    bool pedigree;
    double ageMonths;
    Dog* next;
};


Dog *nuevo, *primero, *ultimo, *actual;

void inserta_final(bool p, float a) {

    nuevo = new Dog;
    nuevo ->next = NULL;
    nuevo ->ageMonths = a;
    nuevo ->pedigree = p;


    if (primero == NULL) {
        primero = nuevo;
        ultimo = nuevo;
    }
    else {
        ultimo->next = nuevo;
        ultimo = nuevo;
    }
}

void recorre() {
    actual = primero;

    while (actual != NULL) {
        printf("%d      %f\n", actual->pedigree, actual->ageMonths);
        actual = actual -> next;
    }
}

void menu() {
    int op = 0;
    bool pedigree;
    float age;


    while (op != 3) {

        std::cout << "\n1. Agrega Dog\n";
        std::cout << "2. Recorre Dogs\n";
        std::cout << "3. Exit\n";

        scanf("%d", &op);
        fflush(stdin);

        if (op == 1) {
            std::cout << "Pedigree? (1 o 0):\n";
            scanf("%d", &pedigree);

            std::cout << "Age? (decimal):\n";
            scanf("%f", &age);

            inserta_final(pedigree, age);
            
        }
        if (op == 2) {
            recorre();
        }
        if (op == 3) return;
    


    }
}


int main() {
    menu();
    return 0;

}



