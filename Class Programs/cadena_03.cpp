# include <stdio.h>
# include <conio.h>
# include <String.h>

char pal1[31];
int x, cont=0;

main() {
	printf("Indica la primera palabra: "); gets(pal1);
	x = strlen(pal1)-1;
	
	for (int i = 0; i <= x; i++) {
		if (((pal1[i] < 'a') || (pal1[i] > 'z')) && ((pal1[i] < 'A') || (pal1[i] > 'Z')) && ) {
			cont++;
			printf("%c\n", pal[i]);
		}
		
	}
	printf("Hay %d", cont);# include <stdio.h>
# include <conio.h>
# include <String.h>

char letra, palabra[101], abc[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};

void normal_1(){
  printf("");

}
//CHEQUENLO, NO LO HE REVISADO, REGRESANDO DE CLASE LE SIGO (ANS)
void shift_n(){
  printf("Ingresa la palabra a desencriptar: "); gets(palabra);
  int x= strlen(palabra)-1;
  char palabran[x];                 //aquí se almacenará la palabra obtenida
  int y= strlen(palabran);
  for(int i=0; i<=x; i++){
    for(int j=0; j<=26; i++){        //empieza proceso de desencriptado
      if(palabra[i]=='z'){
          palabra[i]='a';           //Si la letra es z, la reemplaza por A (para evitar tener que pasar por el arreglo)
          palabran[i]=palabra[i];
      }else{
        if(palabra[i]==abc[j]){ 
          palabran[i]=abc[j+1];     //Cuando encuentre la letra de la palabra en el abecedario, recorre al abecedario en una unidad
        }
      }
    }     
  }
  printf("El contenido desencriptado es: \n");
  for(int i=0;i<=y;i++) printf("%c",palabran[i]);
}

void menu(){
	letra='x';
  	while (letra!=char(27)){
    	printf("a) De normal a shift 1\n");
    	printf("b) De shift 1 a normal\n");
    	printf("Presiona esc para salir\n");
		printf("Indica la opci%cn deseada: \n", 162); letra=getche();
    
    if(((letra<'a')||(letra>'b')) && letra!=char(27)){
      printf("Opcion no valida");
    }else{
      switch(letra){
        case 'a': normal_1(); break;
        case 'b': shift_n(); break;
        case 'c': break;
      }
    }
	}
}

int main(){
  menu();
}
}
