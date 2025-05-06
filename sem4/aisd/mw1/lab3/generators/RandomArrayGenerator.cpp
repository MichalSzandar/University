#include<random>
#include<iostream>

int main(int argc, char *argv[]) {

    if(argc <= 1) {
        std::cout << "Usage: ./RandomGenerator <n>" << std::endl;
        return 1;
    }

    int n = std::stoi(argv[1]);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 100000);

    std::cout << n << " ";

    for (int i = 0; i < n; i++) {
        std::cout << dis(gen) << " ";
    }

    return 0;
}