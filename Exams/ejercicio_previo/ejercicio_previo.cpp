# include <stdio.h>
# include <conio.h>
# include <String.h>
# include <fstream>


// no. tarjeta INT 5
// nom 		   CHAR 15 + 1
// ap 		   CHAR 15 + 1
// am          CHAR 15 + 1
// sal		   FLOAT 9
// correo      CHAR  30 + 1

using namespace std;
char falso[2];
int num;
float sal;
char nom[16], ap[16], am[16], cor[31];


struct Nodo{
	int num;
	float sal;
	char nom[16], ap[16], am[16], cor[31];
	Nodo *next;
};

Nodo *primero, *ultimo, *nuevo, *actual, *previo;

void stop(){
	printf("[ENTER] para continuar ...\n");
	getche();
}

bool busca_nodo(){
	actual=primero;
	previo=actual;
	while (actual!=NULL){
		if (actual->num == num) return 1;
		previo=actual;
		actual=actual->next;
	}
	return 0;
}

void baja_clientes(){
	printf("Indica el cliente a eliminar  : "); 
	scanf("%d", &num);
	gets(falso);
	if (!busca_nodo()){
		printf("Error, cliente inexistente en la lista ...\n");
	}
	else{
		if (actual==primero){ // Eliminar el primer nodo
			primero=actual->next;
			delete(actual);
		}
		else{
			if (actual==ultimo){ // Eliminar último nodo
				previo->next=NULL;
				ultimo=previo;
				delete(actual);
			}
			else {
				previo->next=actual->next; // Eliminar nodo intermedio
				delete(actual);
			}
		}
	}
}

void consulta_cliente(){
	printf("Indica el no. de cliente a buscar  : "); 
	scanf("%d", &num);
	gets(falso);
	
	if (!busca_nodo()){
		printf("Error, el cliente no existe ...\n");
	}
	else{
		printf("No.         : %d\n",actual->num);
		printf("Nombre      : %s\n",actual->nom);
		printf("Ap. Paterno : %s\n",actual->ap);
		printf("Ap. Materno : %s\n",actual->am);
		printf("Salario     : %f\n",actual->sal);
		printf("Correo      : %s\n",actual->cor);
		
	}
	stop();
}

void lista_clientes(){
	if (primero==NULL){
		printf("Error, la lista esta vacia.\n");
	}
	else{
		actual=primero;
		while (actual!=NULL){
			
			printf("%2d   %15s   %15s   %15s   %9.2f   %30s\n",actual->num,actual->nom,actual->ap,actual->am, actual->sal, actual->cor);
			printf("-----------------------------------------------------------------------------------------------------------------------\n");
			actual=actual->next;
		}
	}
	stop();
}

void insertar_nodo(){
	
	if (primero==NULL){
		primero=nuevo;
		ultimo=nuevo;
	}
	else{
		ultimo->next=nuevo;
		ultimo=nuevo;
	}
}

void carga_lista(){
	ifstream file;
	file.open("clientes.txt",ios::in);
	while (file >> num >> nom >> ap >> am >> sal >> cor){
		nuevo=new Nodo;
		nuevo->num = num;
		strcpy(nuevo->nom,nom);
		strcpy(nuevo->ap,ap);
		strcpy(nuevo->am,am);
		nuevo->sal = sal;
		strcpy(nuevo->cor,cor);
		nuevo->next=NULL;
		insertar_nodo();
		
	}
	file.close();
}

void descarga_lista(){
	ofstream file;
	file.open("clientes_actualizado.txt",ios::out);
	actual=primero;
	while (actual!=NULL){
		file << actual->num << " " << actual->nom << " " << actual->ap << " " << actual->am << " " << actual->sal << " " << actual->cor << "\n";
		actual=actual->next;
	}
	file.close();
}

void menu(){
	int op=0;
	while ((op!= 7) || (op!=6)) {
		printf("-----------------------\n");
		printf("1) Carga archivo\n"); 
		printf("2) Mostrar Lista\n"); 
		printf("3) Consultar un nodo\n"); 
		printf("4) Eliminar un nodo\n");
		printf("5) Descargar archivo\n");
		printf("6) Terminar\n");
		printf("Indica la opcion deseada : "); scanf("%d",&op); gets(falso);
		printf("-----------------------\n");
		
		if (op==1) carga_lista();
		if (op==2) lista_clientes();
		if (op==3) consulta_cliente();
		if (op==4) baja_clientes();
		if (op==5) descarga_lista();
		if (op==6) break;
	}
}
int main() {
	menu();
}







