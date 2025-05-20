#ifndef CLI_HPP
#define CLI_HPP

#include <iostream>
#include "Tree.hpp"
#include <limits>
#include <sstream>
#include <string>

class Cli {
    private:
        Tree* tree;
        bool printOutput;
        int op_index;
        void printInsert(std::istringstream& iss);
        void printDelete(std::istringstream& iss);
        void printOutputMessage(const std::string& message);
        void printErrorMessage(const std::string& message);
    public:
        Cli(Tree* tree, bool printOutput);
        ~Cli() = default;
        void run();
};

#endif
