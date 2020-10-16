# include <stdio.h>
# include <conio.h>

int x, y;
int *ap_x, *ap_y;

main() {
	x = 10;
	y = 20;
	
	printf("X = %d\n", x);
	printf("Y = %d\n", y);
	ap_x = &x;
	ap_y = &y;
	printf("La direccion de memoria de x es : %d\n", ap_x);
	printf("La direccion de memoria de y es : %d\n", ap_y);
	*ap_x = 200;
	printf("X = %d\n", x);
	
}
