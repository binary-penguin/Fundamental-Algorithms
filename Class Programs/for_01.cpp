#include <stdio.h>
#include <conio.h>


main() {
	for (int i=1; i<=10; i++){
		printf("%d\n", i);
	}
	getche();
	printf("------------\n");
	for (int i=2; i<=10; i+=2){
		printf("%d\n", i);
	}
	getche();	
	printf("------------\n");
	
	for (int i=10; i>=1; i--){
		printf("%d\n", i);
	}
	getche();
}

