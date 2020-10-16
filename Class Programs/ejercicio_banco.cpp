/*

Archivo de Clientes (clientes.txt)
*************************
CUENTA      INT 6       cuenta (Primary Key)
NOMBRE      CHAR 15     nom
AP          CHAR 15     ap
AM          CHAR 15     am  
NO. CEL     CHAR 10     cel 
CORREO      CHAR 30     cor
SALDO INI   FLOAT 9     saldo_ini
SALDO ACT   FLOAT 9     saldo_act


******************************
Archivo de movimientos (movimientos.txt)
CUENTA      INT 6       cta_mov
FECHA       CHAR 10     fecha (del movimiento)
TIPO de MOV CHAR 1      tipo_mov (D = Depo, R = Retiro)
MONTO       FLOAT 9     monto
*/

# include <stdio.h>
# include <String.h>
# include <fstream>
# include <conio.h>
# include <time.h>
using namespace std;


char falso[2];
// GLOBALES PA CLIENTE
int cuenta;
char nom[16], ap[16], am[16], cel[11], cor[31];
float saldo_ini, saldo_act;
int cta_mov;
char fecha[11], tipo_mov;
float monto;


struct NodoClientes {
    int cuenta;
    char nom[16], ap[16], am[16], cel[11], cor[31];
    float saldo_ini, saldo_act;
    NodoClientes *next;
};

NodoClientes *nuevoc, *actualc, *primeroc, *ultimoc;

struct NodoMovimientos {
    int cta_mov;
    char fecha[11], tipo_mov;
    float monto;
    NodoMovimientos *next;

};

NodoMovimientos *nuevom, *actualm, *primerom, *ultimom;

void pausa() {
    printf("[ENTER] pa' continuar\n");
    getche();
}


void carga_archivos() {
    // ARCH CLIENTES
    ifstream archC;
    archC.open("clientes.txt", ios::in);
    while (archC >> cuenta >> nom >> ap >> am >> cel >> cor >> saldo_ini >> saldo_act) {
        nuevoc = new NodoClientes;
        nuevoc->cuenta = cuenta;
        strcpy(nuevoc ->nom, nom);
        strcpy(nuevoc ->ap, ap);
        strcpy(nuevoc ->am, am);
        strcpy(nuevoc ->cel, cel);
        strcpy(nuevoc ->cor, cor);
        nuevoc->saldo_ini = saldo_ini;
        nuevoc->saldo_act = saldo_act;
        nuevoc->next = NULL;
        
        if (primeroc == NULL) {
            primeroc = nuevoc;
            ultimoc = nuevoc;
        }
        else {
            ultimoc->next = nuevoc;
            ultimoc = nuevoc;
        }
    }

    // ARCH MOVIMIENTOS
    ifstream archM;
    archM.open("clientes.txt", ios::in);
    while (archM >> cta_mov >> fecha >> tipo_mov >> monto)
    {
        nuevom = new NodoMovimientos;
        nuevom->next = NULL;
        nuevom->cta_mov = cta_mov;
        strcpy(nuevom->fecha, fecha);
        nuevom->tipo_mov = tipo_mov;
        nuevom->monto = monto;

        if (primerom == NULL) {
            primerom = nuevom;
            ultimom = nuevom;
        }
        else {
            ultimom->next = nuevom;
            ultimom = nuevom;
            
        }

    }
    

}

bool busca_cuenta() {
    printf("Indica el numero de cuenta: \n"); scanf("%d", &cuenta); gets(falso);

    actualc = primeroc;

    while (actualc != NULL) {

        if (actualc->cuenta == cuenta) return true; 
        actualc = actualc->next;
    }
    return false;
}

void descarga_clientes() {
    actualc = primeroc;

    ofstream arch;
    arch.open("clientes.txt", ios::out);
    while (actualc != NULL) {
        for (int i = 0; i < strlen(actualc->nom); i++) if (actualc->nom[i] == ' ') actualc->nom[i] = '_';
        for (int i = 0; i < strlen(actualc->ap); i++) if (actualc->ap[i] == ' ') actualc->ap[i] = '_';
        for (int i = 0; i < strlen(actualc->am); i++) if (actualc->am[i] == ' ') actualc->am[i] = '_';
        arch << actualc->cuenta << " " << actualc->nom << " " << actualc->ap << " " << actualc->am << " " << actualc->cel << " " << actualc->cor << " " << actualc->saldo_ini << " " << actualc->saldo_act << "\n";
        actualc = actualc->next;
    }
    arch.close();
}

void descarga_movimientos() {
    actualm = primerom;

    ofstream arch;
    arch.open("movimientos.txt", ios::out);
    while (actualm != NULL) {
        arch << actualm->cta_mov << " " << actualm->fecha << " " << actualm->monto << "\n";
        actualm = actualm->next;
    }
    arch.close();
}

void alta_cuenta() {

    int l;

    if (busca_cuenta()) {
        printf("[ERROR], cuenta se duplica en la base de datos ...\n");
        pausa();
    }
    // VALIDACIONES
    else {
        do {
            printf("Indica el nomvre: "); gets(nom);
            l = strlen(nom);

            if ((l < 1) || (l > 15)) {
                printf("[ERROR] cadena entre 1-15 \n");
                pausa();
            }
        } while ((l < 1) || (l > 15));

        do {
            printf("Indica el ap: "); gets(ap);
            l = strlen(ap);

            if ((l < 1) || (l > 15)) {
                printf("[ERROR] cadena entre 1-15 \n");
                pausa();
            }
        } while ((l < 1) || (l > 15));

        do {
            printf("Indica el am: "); gets(am);
            l = strlen(am);

            if ((l < 1) || (l > 15)) {
                printf("[ERROR] cadena entre 1-15 \n");
                pausa();
            }
        } while ((l < 1) || (l > 15));


        // Cambiar spaces por _

        for (int i = 0; i < strlen(nom); i++) if (nom[i] == ' ') nom[i] = '_';
        for (int i = 0; i < strlen(ap); i++) if (ap[i] == ' ') ap[i] = '_';
        for (int i = 0; i < strlen(am); i++) if (am[i] == ' ') am[i] = '_';

        do {
            printf("Indica el cel: "); gets(cel);
            l = strlen(cel);

            if ((l < 1) || (l > 10)) {
                printf("[ERROR] cadena entre 1-10 \n");
                pausa();
            }
        } while ((l < 1) || (l > 10));

        do {
            printf("Indica el cor: "); gets(cor);
            l = strlen(cor);

            if ((l < 1) || (l > 30)) {
                printf("[ERROR] cadena entre 1-30 \n");
                pausa();
            }
        } while ((l < 1) || (l > 30));

        do {
            printf("Indica el saldo: ");  scanf("%f", &saldo_ini); gets(falso);

            if ((saldo_ini < 1) || (saldo_ini > 99999999)) {
                printf("[ERROR] cadena entre 1-15 \n");
                pausa();
            }
        } while ((l < 1) || (l > 15));

        nuevoc = new NodoClientes;
        nuevoc->cuenta = cuenta;
        strcpy(nuevoc ->nom, nom);
        strcpy(nuevoc ->ap, ap);
        strcpy(nuevoc ->am, am);
        strcpy(nuevoc ->cel, cel);
        strcpy(nuevoc ->cor, cor);
        nuevoc->saldo_ini = saldo_ini;
        nuevoc->saldo_act = saldo_ini;
        nuevoc->next = NULL;
        
        if (primeroc == NULL) {
            primeroc = nuevoc;
            ultimoc = nuevoc;
        }
        else {
            ultimoc->next = nuevoc;
            ultimoc = nuevoc;
        }

    }
    descarga_clientes();

}


void consulta_cuentaXnumero() {
    if (!busca_cuenta()) {
        printf("[ERROR], cuenta inexistente en DataBase ... \n");
        pausa();
    }

    else {
        
        for (int i = 0; i < strlen(actualc->nom); i++) if (actualc->nom[i] == '_') actualc->nom[i] = ' ';

        for (int i = 0; i < strlen(actualc->ap); i++) if (actualc->ap[i] == '_') actualc->ap[i] = ' ';

        for (int i = 0; i < strlen(actualc->am); i++) if (actualc->am[i] == '_') actualc->am[i] = ' ';



        printf("Nombre      : %s\n", actualc->nom);
        printf("Ap          : %s\n", actualc->ap);
        printf("Am          : %s\n", actualc->am);
        printf("Cel         : %s\n", actualc->cel);
        printf("Cor         : %s\n", actualc->cor);
        printf("Saldo ini   : %9.1f\n", actualc->saldo_ini);
        printf("Saldo act   : %9.1f\n", actualc->saldo_act);
    }
}




void listado_clientes() {
    actualc = primeroc;

    while (actualc != NULL) {


        for (int i = 0; i < strlen(actualc->nom); i++) if (actualc->nom[i] == '_') actualc->nom[i] = ' ';

        for (int i = 0; i < strlen(actualc->ap); i++) if (actualc->ap[i] == '_') actualc->ap[i] = ' ';

        for (int i = 0; i < strlen(actualc->am); i++) if (actualc->am[i] == '_') actualc->am[i] = ' ';


        printf("\n\n");
        printf("Cuenta  Nombre          AP. Paterno     AP. Materno     Celular    Correo                         Saldo Actual\n");
        //      123456  123456789012345 123456789012345 123456789012345 1234567890 123456789012345678901234567890

        printf("%6d %15s %15s %15s %10s %30s %11.1f \n", actualc->cuenta, actualc->nom, actualc->ap, actualc->am, actualc->cel, actualc->cor, actualc->saldo_act);

        actualc = actualc->next;
    }
    pausa();
}

char *obtiene_fecha() {
    time_t tiempo;
    struct tm, *tm;
    char fechayhora[11];

    tiempo = time (NULL);
    tm = localtime(&tiempo);
    strftime(fechayhora, 11, "%d/%m/%Y", tm);
    return (fechayhora);
}

void depositos() {
     if (!busca_cuenta()) {
        printf("[ERROR], cuenta inexistente en DataBase ... \n");
        pausa();
    }

    else {

        printf("Indica el monto DEPOSITO : \n"); scanf("%f", monto); gets(falso);
        strcpy(fecha, obtiene_fecha());
        tipo_mov = 'D';
        actualc->saldo_act = saldo_act + monto;
        
        // Nuevo Node

        nuevom = new NodoMovimientos;
        nuevom->cta_mov = cuenta;
        strcpy(nuevom->fecha, fecha);
        nuevom -> tipo_mov = tipo_mov;
        nuevom -> monto = monto;
        nuevom->next = NULL;


        // Agregar nuevo nodo a lista mov

        if (primerom == NULL) {
            primerom = nuevom;
            ultimom = nuevom;
        }
        else 
        {
            ultimom -> next = nuevom;
            ultimom = nuevom;
        }
        descarga_clientes();
        descarga_movimientos();

    }
}

void retiros() {
     if (!busca_cuenta()) {
        printf("[ERROR], cuenta inexistente en DataBase ... \n");
        pausa();
    }

    else {

        printf("Indica el monto RETIRO : \n"); scanf("%f", monto); gets(falso);
        strcpy(fecha, obtiene_fecha());
        tipo_mov = 'R';
        if (actualc->saldo_act < monto) {
            printf("ERROR, fondos insuficientes");
            return;
            
        }
        else  {
            actualc->saldo_act = saldo_act - monto;
        }
        
        // Nuevo Node

        nuevom = new NodoMovimientos;
        nuevom->cta_mov = cuenta;
        strcpy(nuevom->fecha, fecha);
        nuevom -> tipo_mov = tipo_mov;
        nuevom -> monto = monto;
        nuevom->next = NULL;


        // Agregar nuevo nodo a lista mov

        if (primerom == NULL) {
            primerom = nuevom;
            ultimom = nuevom;
        }
        else 
        {
            ultimom -> next = nuevom;
            ultimom = nuevom;
        }
        descarga_clientes();
        descarga_movimientos();

    }
}




void estados_cuenta(){
    printf("**************************************\n");
    printf("CUENAT          : %d\n", actualc->cuenta);
    printf("CLIENTE         : %s %s %s \n", actualc->nom, actualc->ap, actualc->am);
    printf("SALDO ACTUAL    : %d\n", actualc->saldo_act);
    printf("**************************************\n");
    printf("MOVS**********************************\n");

    actualm = primerom;
    while (actualm != NULL) {
        if (actualm->cta_mov == cuenta) 
        {
            printf("* %s", actualm->fecha);
            if (actualm->tipo_mov == 'D') {
                printf("           %11.1f\n", actualm->monto);
            }
            else {
                printf("                     %11.1f\n", actualm->monto);
            }
        }
    }

}

void consultaXcelular() {
    
    bool existe_cel = 0;
    printf("Indica el celular a consultar : "); gets(cel);

    actualc = primeroc;
    while (actualc != NULL) {
        if (strcmp(actualc->cel, cel) == 0) {
            existe_cel = 1;

        }
        actualc = actualc->next;
    }
    if (!existe_cel) {
        printf("ERROR, noetsiste cel.");
        pausa();
    }
    else {
        
        for (int i = 0; i < strlen(actualc->nom); i++) if (actualc->nom[i] == '_') actualc->nom[i] = ' ';

        for (int i = 0; i < strlen(actualc->ap); i++) if (actualc->ap[i] == '_') actualc->ap[i] = ' ';

        for (int i = 0; i < strlen(actualc->am); i++) if (actualc->am[i] == '_') actualc->am[i] = ' ';


        printf("Cuenta      : %d\n", actualc->cuenta);
        printf("Nombre      : %s\n", actualc->nom);
        printf("Ap          : %s\n", actualc->ap);
        printf("Am          : %s\n", actualc->am);
        printf("Cel         : %s\n", actualc->cel);
        printf("Cor         : %s\n", actualc->cor);
        printf("Saldo ini   : %9.1f\n", actualc->saldo_ini);
        printf("Saldo act   : %9.1f\n", actualc->saldo_act);
    }

}


void menu() {
    int op = 0;


    carga_archivos();
    while (op != 9) {
        printf("\n\n");
        printf("|||||||||||||||||||||||||||||||||||||||\n");
        printf("1) Alta de cuentas\n");
        printf("2) Consulta de cuentas por cuenta\n");
        printf("3) Consulta de cuentas por celular\n");
        printf("4) Listado general de cuentas\n");
        printf("|||||||||||||||||||||||||||||||||||||||\n");
        printf("5) Depositos\n");
        printf("6) Retiros\n");
        printf("|||||||||||||||||||||||||||||||||||||||\n");
        printf("7) Estado de cuenta\n");
        printf("8) Cancelar cuenta\n");
        printf("9) Terminar");
        printf("Indica la opcion deseada    :"); scanf("%d", &op); gets(falso);

        if (op == 1) alta_cuenta();
        if (op == 2) consulta_cuentaXnumero();
        if (op == 3) consultaXcelular();
        if (op == 4) listado_clientes();
        if (op == 5) depositos();
        if (op == 6) retiros();

    }
}




int main() {

    // Crea un archivo si no etsiste
    ofstream archC;
    archC.open("clientes.txt", ios::app);
    archC.close();

    // Crea un archivo si no etsiste
    ofstream archM;
    archM.open("movimientos.txt", ios::app);
    archM.close();

    menu();
    return 0;
}