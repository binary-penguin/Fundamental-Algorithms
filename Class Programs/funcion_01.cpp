# include <stdio.h>
# include <conio.h>


void func1(){
	printf("Hola funcion 1\n");
}

void func2(int vi, float vf, char vc){
	printf("v1=%d\n", vi);
	printf("vf=%.2f\n", vf);
	printf("vc=%c\n", vc);
	
}

int func3(int v1, int v2){
	
	return(v1+v2);
	
}
main(){
	func1();
	func2(10, 4.34, '@');
	printf("La suma es: %d\n", func3(5,10));
}
