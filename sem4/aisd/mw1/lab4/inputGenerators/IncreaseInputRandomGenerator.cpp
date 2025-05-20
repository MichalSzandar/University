#include <iostream>
#include <algorithm>
#include <random>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <number_of_nodes>" << std::endl;
        return 1;
    }

    int numNodes = std::stoi(argv[1]);

    if (numNodes <= 0) {
        std::cerr << "Number of nodes must be a positive integer." << std::endl;
        return 1;
    }

    int permutation[numNodes];
    for (int i = 0; i < numNodes; ++i) {
        permutation[i] = i + 1;
    }

    // Randomly shuffle the permutation array
    std::random_shuffle(permutation, permutation + numNodes);

    for (int i = 0; i < numNodes; ++i) {
        std::cout << "insert " << permutation[i] << std::endl;
    }

    // Randomly shuffle the permutation array again for deletion
    std::random_shuffle(permutation, permutation + numNodes);

    for (int i = 0; i < numNodes; ++i) {
        std::cout << "delete " << permutation[i] << std::endl;
    }

    std::cout << "exit" << std::endl;

    return 0;
}