# include <stdio.h>
# include <String.h>


int main() {

    int age = 19;
    int *ageP = &age;

    printf("Age : %d\n", age);
    printf("Age address : %d\n", &age);
    printf("Age address (Pointer) : %d\n", ageP);
    printf("Age (Pointer) : %d\n", *ageP);
    printf("Pointer address : %d\n", &ageP);


    printf("\n------------------------\n");
    double profit = 35.123;
    double *profitP = &profit;

    printf("Profit : %f\n", profit);
    printf("Profit (P) : %f\n", *profitP);
    printf("Profit address : %d\n", &profit);
    printf("Profit address (P): %d\n", profitP);
    printf("Pointer address : %d\n", &profitP);


}

