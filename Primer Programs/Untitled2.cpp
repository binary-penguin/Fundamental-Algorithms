# include <stdio.h>
# include <conio.h>

int x;

main() {
	printf("Indica un valor: "); scanf("%d", &x);
	if (x<100) {
		printf("Valor menor a 100.");
	}
	else {
		if (x==100) {
			printf("Valor igual a 100.");
		}
		else {
			printf("Valor mayor a 100.");
	}
			
	}
	getche();
}
