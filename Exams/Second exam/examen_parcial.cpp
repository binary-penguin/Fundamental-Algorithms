# include <stdio.h>
# include <conio.h>
# include <String.h>
# include <fstream>

// Estructura del archivo y miembros del Nodo
// Id. Paciente     INT 9
// Positivo 		INT 1
// Fallecido	    INT 1
// Id. Estado       INT 2


// Miembros
using namespace std;
char falso[2];
int idP, pos, fall, idE;

// Contadores para conteos
int cuentaPos = 0;
int cuentaPosFa = 0;
int cuentaPosNFa = 0;
int cuentaTodos = 0;


struct Nodo{
	int idP, pos, fall, idE;
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
		if (actual->idP == idP) return 1;
		previo=actual;
		actual=actual->next;
	}
	return 0;
}



void consulta_paciente(){
	printf("Indica el ID del Paciente a buscar  : "); 
	scanf("%d", &idP);
	gets(falso);
	
	if (!busca_nodo()){
		printf("Error, el ID no existe ...\n");
	}
	else{
		printf("ID Paciente             : %d\n",actual->idP);
		printf("Positivo (0-No, 1-Si)   : %d\n",actual->pos);
		printf("Fallecio (0-No, 1-Si)   : %d\n",actual->fall);
		printf("ID Estado               : %d\n",actual->idE);
        printf("------------------------------------------\n");
	}
	stop();
}

int lista_pacientes(int print){ // print = 1 muestra la lista, print = 0 no muestra la lista
    // Regresa 0 si la lista está vacía
    // De otra forma 1;
    
    cuentaPos = 0;
    cuentaPosFa = 0;
    cuentaPosNFa = 0;
    cuentaTodos = 0;
    
    if (primero==NULL){
		printf("Error, la lista esta vacia.\n");
        stop();
        return 0;
	}
	else{
		actual=primero;
		while (actual!=NULL){
            if (print == 1) {
                printf("%9d   %1d   %1d   %2d\n",actual->idP,actual->pos,actual->fall,actual->idE);
			    printf("-----------------------------------------------------\n");
            }
            if (actual->pos == 1) cuentaPos = cuentaPos + 1;
            if ((actual-> pos == 1) && (actual-> fall == 0)) cuentaPosNFa = cuentaPosNFa + 1;
            if ((actual-> pos == 1) && (actual-> fall == 1)) cuentaPosFa = cuentaPosFa + 1;
            cuentaTodos = cuentaTodos + 1;
            actual=actual->next;
		}
        return 1;
	}
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
	file.open("datos_covid_parcial.txt",ios::in);
	while (file >> idP >> pos >> fall >> idE){
			nuevo=new Nodo;
			nuevo->idP = idP;
            nuevo->pos = pos;
            nuevo->fall = fall;
            nuevo->idE = idE;
			nuevo->next=NULL;
			insertar_nodo();
	}
	file.close();
    printf("Archivo cargado con exito a la lista enlazada!\n");
    stop();
}


void conteos(int op) {
    
    int vacia = lista_pacientes(0);

    if ((op == 4) && (vacia != 0)) {
        printf("Total de pruebas realizadas     : %d\n", cuentaTodos);
        printf("Total de casos positivos        : %d\n", cuentaPos);
        float porcentaje = (cuentaPos*100.0)/cuentaTodos;
        printf("Porcentaje de positivos         : %.2f%%\n", porcentaje);
        stop();
    }

    if ((op == 5) && (vacia != 0)) {
        printf("Total de pruebas realizadas             : %d\n", cuentaTodos);
        printf("Total de casos positivos                : %d\n", cuentaPos);
        printf("Positivos NO fallecidos                 : %d\n", cuentaPosNFa);
        float porcentaje = (cuentaPosNFa*100.0)/cuentaPos;
        printf("Porcentaje de NO fallecidos VS positvos : %.2f%%\n", porcentaje);
        stop();
    }
    
    if ((op == 6) && (vacia != 0)) {
        printf("Total de pruebas realizadas             : %d\n", cuentaTodos);
        printf("Total de casos positivos                : %d\n", cuentaPos);
        printf("Positivos SI fallecidos                 : %d\n", cuentaPosFa);
        float porcentaje = (cuentaPosFa*100.0)/cuentaPos;
        printf("Porcentaje de NO fallecidos VS positvos : %.2f%%\n", porcentaje);
        stop();
    }
    
}



void menu(){
	int op=0;
	while (op!= 7) {
		printf("-----------------------\n");
		printf("1) Carga archivo\n"); 
		printf("2) Mostrar Lista\n"); 
		printf("3) Consultar un ID De Paciente\n"); 
		printf("4) Conteo de Positivos\n");
		printf("5) Conteo de Positivos NO Fallecidos\n");
		printf("6) Conteo de Positivos SI Fallecidos\n");
        printf("7) TERMINAR\n");
		printf("Indica la opcion deseada : "); scanf("%d",&op); gets(falso);
		printf("-----------------------\n");
		
		if (op==1) carga_lista();
		if (op==2) int vacia = lista_pacientes(1);
		if (op==3) consulta_paciente();
        if (op==4) conteos(4);
        if (op==5) conteos(5);
        if (op==6) conteos(6);
		if (op==7) break;
	}
}
int main() {
	menu();
}
