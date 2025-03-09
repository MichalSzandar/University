#ifndef CLI_HPP
#define CLI_HPP

#include <iostream>
#include "BinaryTree.hpp"
#include<limits>
#include<sstream>
#include<string>

template <typename T>
class CLI {
private:
    BinaryTree<T> tree;
    T getInput();

public:
    CLI();
    ~CLI();
    void run();
};

#endif 
