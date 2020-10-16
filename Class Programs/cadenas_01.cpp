# include <stdio.h>
# include <conio.h>

char letra;

main(){
	
	// char 
	// works only with ''
	letra = 'H';
	printf("Letra = %c", letra);
	printf("\nIndica caracter: "); scanf("%c", &letra);
	printf("Letra = %c", letra);
	printf("\nIndica caracter: "); letra = getche();
	printf("\nLetra = %c", letra);
	printf("\nIndica caracter: "); letra = getch();
	printf("\nLetra = %c", letra);
	
	if (letra == '*') printf("\nBien");	
	else printf("\nMal");
	
}
