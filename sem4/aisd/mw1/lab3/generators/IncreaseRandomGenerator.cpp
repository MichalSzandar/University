#include<iostream>
#include<random>

int main(int argc, char *argv[]) {
    
    if(argc <= 1) {
        std::cout << "Usage: ./IncreaseGenerator <n>" << std::endl;
        return 1;
    }

    int n = std::stoi(argv[1]);

    std::cout << n << " ";

    for (int i = 0; i < n; i++) {
        std::cout << i << " ";
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, n - 1);
    std::cout << dis(gen) << std::endl;

    return 0;
}