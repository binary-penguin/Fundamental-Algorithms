# include <stdio.h>
# include <conio.h>

int ar[5];

void captura(){
	for (int i=0;i<=4;i++){
		printf("Indica el valor de la posici%cn %d : ", 162, i); scanf("%d", &ar[i]);
	}
}

void muestra(){
	for (int i=0; i<=4; i++){
		printf("%d -> %d\n", i, ar[i]);
	}
}

main(){
	/*
	ar[0]=10;
	ar[4]=-5;
	
	for (int i=0; i<=4; i++){
		printf("%d -> %d\n", i, ar[i]);
	}
	*/
	captura();
	muestra();
}
