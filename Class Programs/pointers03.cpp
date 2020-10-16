# include <stdio.h>
# include <conio.h>


int *ap_dinamico;

main() {
	ap_dinamico = new int;
	printf("Dirección de ap_dinamico : %d\n", ap_dinamico);
	printf("El contenido es          : %d\n", *ap_dinamico);
	*ap_dinamico = NULL;
	printf("El contenido es          : %d\n", *ap_dinamico);
}
