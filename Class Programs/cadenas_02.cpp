# include <stdio.h>
# include <conio.h>

char palabra[16];


main() {
	printf("Indica una palabra : "); scanf("%s", &palabra);
	printf("\nPalabra = %s", palabra);
	printf("\nRaro = %s", palabra[3]);
	
}
