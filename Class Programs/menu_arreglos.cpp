# include <stdio.h>
# include <math.h>

/*
A01367182 Josue Jemuel Flores Nestor
A01769059 Jorge Alberto Flores Ponce
A01366974 Ana Laura Rodríguez Jurado    
*/


float ar[100], arM[100];
int arraySize = 0;

void captura(){
	int i=-1;
	
	do{
		i++;
		printf("Indica el valor de la posici%cn %d: ",162,i);scanf("%f",&ar[i]);
	}while(ar[i]!=0 && i<=101);
	
	arraySize = i;
	printf("SIZE: %d\n", arraySize);
}
void muestra(){
	int i=-1;
	
	do{
		i++;
		printf("Posici%cn %d -> %8.4f\n",162,i,ar[i]);
		
	}while(ar[i+1]!=0);
}
float d_estandar(float prom, int n){
  	float sigma, d_est;
  	sigma = 0;
  		
		for (int i = 0; i < n; i++){
    	sigma =  sigma + ((ar[i] - prom)*(ar[i] - prom));
  		}
  		
  	d_est = sqrt(sigma/(n-1));
  	printf("La desviaci%cn est%cndar es de : %8.4f\n", 130, 160, d_est);
  	return(d_est);
}
float encuentraMayorMenor(int op){
  float menor = ar[0];
  float mayor = ar[0];

  for (int i=1; ar[i]!=0; i++){
    if (ar[i] > mayor) {
      mayor = ar[i];
    }
    if (ar[i] < menor) {
      menor = ar[i];
    }
  }
  if (op == 4){
  	printf("----------------------------\n");
    printf("Mayor -> %8.4f\n", mayor);
    printf("----------------------------\n");
  }
  else{
  	printf("----------------------------\n");
    printf("Menor -> %8.4f\n", menor);
    printf("----------------------------\n");
  }
}
float promedio(){
  float suma = 0;
  int c;
  
  for(c = 0; ar[c]!=0; c++){
    suma += ar[c];
  }
  return (suma / c);
}
float * men_may(int op, int n, char md){
 	// md, decide si imprimir el arreglo o no
 	// 'S'  -> TRUE
 	// else -> FALSE
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (ar[j] > ar[i]){
        float value = ar[i];
        ar[i] = ar[j];
        ar[j] = value;
      }
    }
  }
  if (op == 8){
  	printf("De Menor a Mayor:\n");
    for (int i = 0; i < n; i++){
    	arM[i] = ar[i];
    	if (md == 'S'){
    		printf("%8.4f\n", ar[i]);
		}
    	
	}
  }
	else{
		int c = 0;
        printf("De Mayor a Menor:\n");
        for (int i = (n-1); i != -1; i--){ 
		// ARRAY RE-BUILDER
		arM[c] = ar[i];
		c++;
		if (md == 'S'){
    		printf("%8.4f\n", ar[i]);
		}
		}
	}	
  return(arM);
}
void menu(){
	int op;
	
	do{
		printf("1) Capturar n%cmeros\n",163);
		printf("2) Mostrar valores capturados\n");
		printf("3) Media y Promedio\n",163);
		printf("4) Mayor\n",163);
		printf("5) Menor\n",163);
		printf("6) Mediana\n",163);
		printf("7) Desviaci%cn estandar\n",162,160);
		printf("8) Menor a mayor\n",163);
		printf("9) Mayor a menor\n");
		printf("10) Salir\n");
		printf("Indica la opci%cn deseada: \n",162); scanf("%d",&op);
		
		switch(op)	{
			case 1:
				captura();
				break;
      		case 2:
      			printf("----------------------------\n");
        		muestra();
        		printf("----------------------------\n");
      			break;
      		case 3:
      			{
      	  		printf("----------------------------\n");
		  		float prom = promedio();
		  		printf("Promedio -> %8.4f\n", prom);
		  		printf("----------------------------\n");
    			}
      			break;
      		case 4:
         		encuentraMayorMenor(op);
      			break;
      		case 5:
         		encuentraMayorMenor(op);
      			break;
      		case 6:
      			{
				float *p;
        		p = men_may(8, arraySize,'N');
        
        		// DONDE *(p+0) = ar[0] ordenado de menor a mayor
        		if (((arraySize-1) % 2) == 0) {
        			printf("----------------------------\n");
					printf("EL valor de la mediana es : %8.4f\n", *(p+((arraySize-1)/2)));
					printf("----------------------------\n");
				}
				
				// ELSE PROMEDIO DE LOS VALORES MEDIOS 
				else {
				printf("----------------------------\n");
				float med = float((*(p+((arraySize-1)/2)) + *(p+((arraySize-1)/2)+1))/2);
				printf("EL valor de la mediana es : %8.4f\n",med );
				printf("----------------------------\n");
				}
        		break;
    			}		
      		case 7:
        		d_estandar(promedio(),arraySize);
      			break;
      		case 8:
      			// SORTED-ARRAY PRINTER (USING POINTERS)
      			{  
        		printf("----------------------------\n");
        		float *p;
				p = men_may(op, arraySize,'S');
				printf("----------------------------\n");
				}			
				break;
      		case 9:
      			float *p;
      			printf("----------------------------\n");
				// SORTED-ARRAY PRINTER (USING POINTERS)
				p = men_may(op, arraySize, 'S');
				printf("----------------------------\n");
      			break;				
		}		
	} while (op!=10);
}

main(){
  menu();
}

