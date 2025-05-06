#include<iostream>

int main(int argc, char *argv[]) {
    
    if(argc <= 2) {
        std::cout << "Usage: ./IncreaseGenerator <n> <v>" << std::endl;
        return 1;
    }

    int n = std::stoi(argv[1]);

    std::cout << n << " ";

    for (int i = 0; i < n; i++) {
        std::cout << i << " ";
    }

    std::cout << std::stoi(argv[2]) << std::endl;

    return 0;
}