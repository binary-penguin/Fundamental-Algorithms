# include <iostream>
# include <fstream>
# include <stdio.h>

int main() {
    
    std::ios::sync_with_stdio(false);
    int n = 3;
    char error[1];


    std::cerr << "[ERROR] Your name is mispelled.\n";
    getchar();
    fflush(stdin);
    
    std::cout << "Your variable is " << n << '\n';

    return 0;
}

