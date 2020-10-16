# include <stdio.h>
# include <conoo.h>

int x;

main {
	printf("Indica un valor : "); scanf("%d", &x);
	if ((x<1) || (x>100)) {
		printf("Error, valor fuera de rango ...");
	} 
	else {
		printf("Valor correcto")
	}
	getche();
}
