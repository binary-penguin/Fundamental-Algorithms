# include <stdio.h>
# include <conio.h>

float pro;
int v1, v2, v3, v4, v5, vmayor, vmenor,v_1, v_2, v_3, v_4, v_5;


main() {
	v_1=0;
	v_2=0;
	v_3=0;
	v_4=0;
	v_5=0;
	printf("Indica v1 : "); scanf("%d", &v1);
	printf("Indica v2 : "); scanf("%d", &v2);
	printf("Indica v3 : "); scanf("%d", &v3);
	printf("Indica v4 : "); scanf("%d", &v4);
	printf("Indica v5 : "); scanf("%d", &v5);
	
	pro = float((v1 + v2 + v3 + v4 + v5)) / 5;
	if ((v1 > v2) && (v1 > v3) && (v1 > v4) && (v1 > v5)) {
		
		vmayor = v1;
	}
	else {
		if ((v2 > v1) && (v2 > v3) && (v2 > v4) && (v2 > v5)) {
			vmayor = v2;
		}
		else {
			if ((v3 > v1) && (v3 > v2) && (v3 > v4) && (v3 > v5)) {
				vmayor = v3;
			}
			else {
				if ((v4 > v1) && (v4 > v2) && (v4 > v3) && (v4 > v5)) {
					vmayor = v4;
				}
				else {
					vmayor = v5;
				}
			}
		}
	}
	if ((v1 < v2) && (v1 < v3) && (v1 < v4) && (v1 < v5)) {
		
		vmenor = v1;
	}
	else {
		if ((v2 < v1) && (v2 < v3) && (v2 < v4) && (v2 < v5)) {
			vmenor = v2;
		}
		else {
			if ((v3 < v1) && (v3 < v2) && (v3 < v4) && (v3 < v5)) {
				vmenor = v3;
			}
			else {
				if ((v4 < v1) && (v4 < v2) && (v4 < v3) && (v4 < v5)) {
					vmenor = v4;
				}
				else {
					vmenor = v5;
				}
			}
		}
	}
	
	printf("Promedio -> %.2f\n", pro);
	printf("No. Mayor-> %d\n", vmayor);
	printf("No. Menor-> %d\n", vmenor);
	printf("Los valores pares son: \n");
	if ((v1 % 2) == 0) {
		
	}
	printf("Los valores impares son: \n");

	
	
	
	
	
	
}
