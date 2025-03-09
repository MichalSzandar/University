#include <iostream>
#include "CLI.hpp"

int main() {
    int dataTypeNumber;
    std::cout << "Choose data type:\n (1) Integer\n (2) Double\n (3) String\n";
    std::cin >> dataTypeNumber;

    switch (dataTypeNumber) {
        case 1:
            CLI<int>();
            break;
        case 2:
            CLI<double>();
            break;
        case 3:
            CLI<std::string>();
            break;
        default:
            std::cout << "Invalid choice.\n";
            break;
    }

    return 0;
}

//g++ -I./ ./main.cpp CLI.cpp CLI.hpp BinaryTree.cpp BinaryTree.hpp