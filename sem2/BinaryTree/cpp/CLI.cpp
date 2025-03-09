#include "CLI.hpp"

template <typename T>
CLI<T>::CLI() {
    run();
}

template<typename T>
CLI<T>::~CLI(){

}

template <typename T>
T CLI<T>::getInput() {
    T value;
    std::cin >> value;
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid value: ";
        std::cin >> value;
    }
    return value;
}

template <typename T>
void CLI<T>::run() 
{
    std::cout<<"list of commands:\n (p) - print\n (i) - insert\n (s) - search\n (d) - delete\n (q) - quit\n";
    std::string input;
    std::getline(std::cin, input);
    std::string command;
    while (true) 
    {
        std::cout << "Enter command : ";
        std::getline(std::cin, input);
        std::istringstream iss(input);
        iss >> command;

        if (command == "i") {
            T value;
            iss >> value;
            if (!iss.fail()) {
                tree.insert(value);
            } else {
                std::cout << "Invalid input.\n";
            }
        } else if (command == "p") {
            tree.printBT();
        } else if (command == "s") {
            T value;
            iss >> value;
            if (!iss.fail()) {
                bool found = tree.search(value);
                if (found) {
                    std::cout << "Element found.\n";
                } else {
                    std::cout << "Element not found.\n";
                }
            } else {
                std::cout << "Invalid input.\n";
            }
        } else if (command == "d") {
            T value;
            iss >> value;
            if (!iss.fail()) {
                tree.erase(value);
                std::cout << "Element deleted.\n";
            } else {
                std::cout << "Invalid input.\n";
            }
        } else if (command == "q") {

            std::cout << "Exiting...\n";
            break;
        } else {
            std::cout << "Invalid command. Please try again.\n";
        }
    }
}

template class CLI<int>;
template class CLI<double>;
template class CLI<std::string>;
