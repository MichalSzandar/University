#include "../include/CLI.hpp"

Cli::Cli(Tree* tree, bool printOutput) : tree(tree), printOutput(printOutput), op_index(1) {
    if (tree == nullptr) {
        throw std::invalid_argument("Tree pointer cannot be null");
    }
}

void Cli::printOutputMessage(const std::string& message) {
    if (printOutput) {
        std::cout << message << std::endl;
    }
}

void Cli::printErrorMessage(const std::string& message) {
    if (printOutput) {
        std::cerr << message << std::endl;
    }
}

void Cli::printInsert(std::istringstream& iss) {
    int value = 0;
    iss >> value;
    if (iss.fail()) {
       printErrorMessage("Invalid input for insert command");
    }

    if (tree->insert(value)) {
        if (printOutput) {
            std::cout << "insert " << value << std::endl;
            tree->print();
        }
        std::cout << op_index++ << " " << tree->getKeyComparisons() << " " << tree->getNodeOps() << " " << tree->getHeight() << std::endl;
    } else {
        printErrorMessage("Failed to insert " + std::to_string(value));
    }
}

void Cli::printDelete(std::istringstream& iss) {
    int value = 0;
    iss >> value;
    if (iss.fail()) {
        printErrorMessage("Invalid input for delete command");
    }

    if (tree->remove(value)) {
        if (printOutput) {
            std::cout << "delete " << value << std::endl;
            tree->print();
        }
        std::cout << op_index++ << " " << tree->getKeyComparisons() << " " << tree->getNodeOps() << " " << tree->getHeight() << std::endl;
    } else {
        printErrorMessage("Failed to remove " + std::to_string(value));
    }
}

void Cli::run() {
    std::string input, command;
    while(true) {
        std::getline(std::cin, input);
        std::istringstream iss(input);
        iss >> command;

        if(command == "insert") {
            printInsert(iss);
        } else if(command == "delete") {
           printDelete(iss);
        } else if(command == "inorder") {
            tree->inorder();
        } else if(command == "height") {
            printOutputMessage("Height: " + std::to_string(tree->getHeight()));
        } else if(command == "print") {
            tree->print();
        } else if(command == "exit") {
            break;
        } else {
            std::cout << "Unknown command: " << command << std::endl;
        }
    }
}
