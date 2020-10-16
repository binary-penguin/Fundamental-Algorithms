# include <stdio.h>
# include <conio.h>

int v, f, i;

main(){
	printf("Indica no: "); scanf("%d", &v);
	i = 1;
	f = 1;
	while (i <= v) {
		f=f*i;
		i++;
	}
	printf("El factorial de %d es %d", v, f);
}
