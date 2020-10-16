# include <iostream>
# include <fstream>

int main() {
    std::ios_base::sync_with_stdio(false);

    int n = 0;
    
    std::cout << "Size of the array: ";
    std::cin >> n;

    // Initialize a dynamic array.
    int *arr = {new int[6] {5,4,3,2,1,0}};

    // It is impossible to know the size of a dynamic array.
    std::cout << "Size of the array is " << (sizeof(arr) / sizeof(arr[0])) << std::endl;
    std::cout << "-------------------------\n";

    // Loop through a dynamic array.
    for (int i = 0; i < n+1; i++) {
        // Last element what?
        std::cout << "The element [" << i << "] " << " has a value " << arr[i] << '\n';
    }

    // Free a dynamic array.
    delete []arr;
    std::cout << "-------------------------\n";
    
    // Check the memory spaces filled with shit.
    for (int i = 0; i < n+1; i++) {
        std::cout << "The element [" << i << "] " << " has a value " << arr[i] << '\n';
    }
    return 0;


    // Why dynamic arrays can be index to larger numbers? new int[5]; cout << arr[19]
}

