#include<iostream>

int main(int argc, char *argv[]) {
    
    if(argc <= 1) {
        std::cout << "Usage: ./DecreaseGenerator <n>" << std::endl;
        return 1;
    }

    int n = std::stoi(argv[1]);

    std::cout << n << " ";

    for (int i = n-1; i >= 0; i--) {
        std::cout << i << " ";
    }

    return 0;
}