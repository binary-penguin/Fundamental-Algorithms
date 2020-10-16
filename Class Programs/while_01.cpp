# include <stdio.h>
# include <conio.h>

int i,s;

main() {
	i=0;
	while (i<10){
		printf("%d\n", i);
		i++;
		
	}
	i = 1;
	while (i<=5) {
		s = s + i; // ACUMULADOR
		i++; // CONTADOR
	}
	printf("La sumatoria es %d\n", s);
}


