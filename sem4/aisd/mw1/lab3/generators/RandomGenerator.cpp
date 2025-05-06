#include<random>
#include<iostream>

int main(int argc, char *argv[]) {

    if(argc <= 2) {
        std::cout << "Usage: ./RandomGenerator <n> <k>" << std::endl;
        return 1;
    }

    int n = std::stoi(argv[1]);
    int k = std::stoi(argv[2]);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 2 * n - 1);

    std::cout << n << " ";

    for (int i = 0; i < n; i++) {
        std::cout << dis(gen) << " ";
    }

    std::cout << k << std::endl;

    return 0;
}