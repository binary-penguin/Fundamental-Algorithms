# include <stdio.h>
# include <conio.h>

int x, y;
int *apx, *apy, *apd;

main() {
	x = 10;
	y = 20;
	apx = &x;
	apy = &y;
	apd = new int;
	
	printf("Dirección de ap_x		: %d\n", apx);
	printf("Dirección de ap_y		: %d\n", apy);
	printf("Dirección de ap_y		: %d\n", apd);
}
