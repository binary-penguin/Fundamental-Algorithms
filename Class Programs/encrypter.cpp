# include <stdio.h>
# include <conio.h>
# include <String.h>


/* Patch notes 1.1 BY J.F  >.<


====================================BUG FIXES========================================================================
- Se cambió la longitud de palabran de (x) -> (x+1). Ya que nos hace falta añadir el '\0'. [LINE 16]
- Se cambió la declaración de y por sizeof() en lugar de strlen(). No jalaba porque seguía siendo un array. [LINE 19]
- Se cambió el iterador de i++ a j++. No jalaba igual. [LINE 33]
- Se eliminó la asignación de palabran[i] y palabra[n]
=====================================================================================================================

===================================NEW FEATURES======================================================================
- UI improvements
- Se añadió el parámetro op dentro de shift_n, porfa chequen si todo jala en orden, estoy abierto a modificaciones.
  0 -> encriptar
  1 -> desencriptar
=====================================================================================================================  
*/
char letra, palabra[101], abc[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};

void shift_n(int op){ // param op, 0 -> encriptar, 1 -> desencriptar
  printf("\nIngresa la palabra: "); gets(palabra);
  int x = strlen(palabra)-1;
  
  char palabran[x+1]; //aquí se almacenará la palabra obtenida
  int y = sizeof(palabran);

  for(int i=0; i<=x; i++){
    for(int j=0; j<=26; j++){        //empieza proceso de desencriptado/encriptado
      if ((palabra[i]=='z') && (op == 1)){
          palabran[i] = 'a';
      }
      else if ((palabra[i]=='a') && (op == 0)){
	  	  palabran[i] = 'z';
			}
 	  else if ((palabra[i] == abc[j]) && (op == 1)) palabran[i]=abc[j+1]; //Cuando encuentre la letra de la palabra en el abecedario, recorre al abecedario en una unidad
	  else if ((palabra[i] == abc[j]) && (op == 0)) palabran[i]=abc[j-1]; // else retrocede una unidad   
    } 
  }
  if (op == 1) printf("\nLa cadena desencriptada es: ");
  else printf("\nLa cadena encriptada es: ");
  
  for(int i=0;i<=y-1;i++) {
  printf("%c",palabran[i]);}
  printf("\n");
}

void menu(){
	letra='x';
  	while (letra!=char(27)){
    	printf("\na) De normal a shift 1\n");
    	printf("b) De shift 1 a normal\n");
    	printf("Presiona esc para salir\n");
		printf("Indica la opci%cn deseada: ", 162); letra=getche();
    
    if(((letra<'a')||(letra>'b')) && letra!=char(27)){
      printf("\n\n---Opci%cn no valida---\n [ENTER] para intentar de nuevo.", 162); getch();
      printf("\n");
    }
	else{
      switch(letra){
        case 'a': shift_n(0); break;
        case 'b': shift_n(1); break;
      }
    }
	}
}

int main(){
  menu();
}
