# include <iostream>
# include <fstream>
# include <String.h>


/*

ESTRUCTURA

mat char  9 + 2
nom char 30 + 2
car char  4 + 2

*/


class Archivo {
    public:
        char matIn[11] = {'\0'};
        char matF[11] = {'\0'};
        char nomIn[32] = {'\0'};
        char nomF[32] = {'\0'};
        char carIn[6] = {'\0'};
        char carF[6] = {'\0'};
        int op = 0;
        int flag = 1;
    
    public:
        bool busca_mat() {

            std::ifstream arch;

            arch.open("alumnos.txt", std::ios::in);

            while (arch >> matF >> nomF >> carF) {
                if (strcmp(matF, matIn) == 0) {
                    arch.close();
                    return true;
                }
            }
            arch.close();
            return false;
        }

        void agregar_registros() {
            
            while (flag) {
                matIn[11] = {'\0'};
                printf("Matricula: ");
                fgets(matIn, sizeof(matIn), stdin);
                strupr(matIn);
                strtok(matIn, "\n");
                fflush(stdin);

                // Valida longitud de matricula.
                if ((matIn[10] == 0 && matIn[9] == 0 && matIn[8] == 0) 
                    || ((matIn[10] == 0) && (matIn[9] != 0) && (matIn[8] != 0))
                    || ((matIn[10] != 0) && (matIn[9] != 0) && (matIn[8] != 0))) {

                        std::cerr << "[ERROR] La matricula debe tener exactamente 9 caracteres.";
                        getchar();
                        fflush(stdin);
                    }
                
                // Valida que matricula inicie con 'A0'.
                else if ((matIn[0] != 'A') || (matIn[1] != '0')) {
                        std::cerr << "[ERROR] La matricula debe iniciar con 'A0'.";
                        getchar();
                        fflush(stdin);
                }
                
                // Valida que no se duplique
                else if (busca_mat()) {
                    std::cerr << "[ERROR] La matricula se duplica en la base de datos.";
                    getchar();
                    fflush(stdin);
                }

                else {
                    flag = 0;
                }
            }

            flag = 1;

            while (flag) {
                nomIn[32] = {'\0'};
                printf("Nombre: ");
                fgets(nomIn, sizeof(nomIn), stdin);
                strtok(nomIn, "\n");
                fflush(stdin);
                
                // Valida longitud de nombre
                if ((nomIn[30] != 0) || (nomIn[0] == '\n')) {
                    std::cerr << "[ERROR] El nombre debe tener minimo 1 caracter y maximo 30.";
                    getchar();
                    fflush(stdin);
                }
                else {
                    for (int i = 0; i <= sizeof(nomIn); i++) {
                        if (nomIn[i] == ' ') {
                            nomIn[i] = '_';
                        }
                    }

                    flag = 0;
                }
            }

            flag = 1;

            while (flag) {
                carIn[6] = {'\0'};
                printf("Carrera: ");
                fgets(carIn, sizeof(carIn), stdin);
                strupr(carIn);
                strtok(carIn, "\n");
                fflush(stdin);

                if ((carIn[4] != 0) ||(carIn[1] == 0) || (carIn[0] == 0)) {
                    std::cerr << "[ERROR] La carrera debe tener minimo 2 caracteres y maximo  4.";
                    getchar();
                    fflush(stdin);
                }
                else {
                    flag = 0;
                }
            }

            std::ofstream arch;
            arch.open("alumnos.txt", std::ios::app);

            if (arch.fail()) {
                std::cout << "[ERROR] No se pudo abrir el archivo.\n";
                getchar();
                fflush(stdin);
                return;
            }

            else {

                arch << matIn << " " << nomIn << " " << carIn << "\n";
                flag = 1;
                arch.close();
            }


        }
        
        void consultar_registros() {

            matIn[11] = {'\0'};
            printf("Matricula a consultar: ");
            fgets(matIn, sizeof(matIn), stdin);
            strupr(matIn);
            strtok(matIn, "\n");
            fflush(stdin);

            if (busca_mat() == 0) {
                std::cerr << "[ERROR] La matricula no existe en la base de datos.";
                getchar();
                fflush(stdin);
                return;
            }

            std::ifstream arch;

            arch.open("alumnos.txt", std::ios::in);

            while (arch >> matF >> nomF >> carF) {

                if (strcmp(matF, matIn) == 0) {

                    for (int i = 0; i <= sizeof(nomF); i++) {
                        if (nomF[i] == '_') {
                            nomF[i] = ' ';
                        }
                    }
                    printf("\nMatricula   : %9s\n", matF);
                    printf("Nombre      : %s\n", nomF);
                    printf("Carrera     : %s\n", carF);
                    arch.close();
                }
            }

    }

        void menu() {

            while (op != 3) {
                std::cout << "----------------------------------\n";
                std::cout << "1. Agregar registros" << '\n';
                std::cout << "2. Consultar registros" << '\n';
                std::cout << "3. Terminar" << '\n';
                std::cout << "Tu opcion: ";
                std::cin >> op;
                std::cout << "----------------------------------\n";
                fflush(stdin);
                

                switch (op) {
                    case 1:
                        agregar_registros();
                        break;
                    case 2:
                        consultar_registros();
                        break;
                    default:
                        std::cout << "Bai.\n";
                        op = 3;
                        break;
                }
            }
        }

};


int main() {

    Archivo *objeto = new Archivo;
    objeto -> menu();
    
    return 0;
}







