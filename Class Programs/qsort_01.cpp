#include <stdlib.h>
# include <stdio.h>


float values[] = {40.5,10,100,40.2,20,25};

float compare (const void * a, const void * b){
	return (*(float*)a - *(float*)b);
}
main(){
	int n;
	qsort(values,6,sizeof(float), compare);
	for (n=0; n<6; n++){
		printf("%d,", values[n]);
	}
}
