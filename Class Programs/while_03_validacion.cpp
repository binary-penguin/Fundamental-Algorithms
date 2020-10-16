# include <stdio.h>
# include <conio.h>

int x, y, i, p;

main() {
	
	do {
		printf("Indica x (base) 				: "); scanf("%d", &x);
		
		if ((x < 1) || (x > 10)) {
			printf("Error fuera de rango entre 1 y 10 . . .\n");
			getche();
		}
	} while((x < 1) || (x > 10));
	
	do {
		printf("Indica el valor de y (exponente)		: "); scanf("%d", &y);
		if ((y<1) || (y>5)) {
			printf("Error, valor fuera de rango entre 1 y 5 . . .\n");
			getche();
		}
	} while ((y<1) || (y>5));
	
	i = 1;
	p = 1;
	while (i<=y) {
		p = p * x;
		i++;
	}
	printf("La potencia es %d", p);
	getche();
}
