#include "../include/BinarySearchTree.hpp"
#include "../include/RedBlackTree.hpp"
#include "../include/SplayTree.hpp"
#include "../include/CLI.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <tree_type> <print_output>" << std::endl;
        std::cerr << "Available tree types: BST" << std::endl;
        return 1;
    }

    std::string treeType = argv[1];
    Tree* tree = nullptr;
    bool printOutput = false;

    if (argc > 2) {
        printOutput = std::string(argv[2]) == "-p";
    }
  
    if (treeType == "BST") {
        tree = new BinarySearchTree();
    } else if (treeType == "RBT") {
        tree = new RedBlackTree();
    } else if (treeType == "Splay") {
        tree = new SplayTree();
    } else {
        std::cerr << "Unknown tree type: " << treeType << std::endl;
        return 1;
    }

    /*bool printOutput = true; // Default value, can be set based on user input or command line arguments
    Tree* tree = new SplayTree();*/

    Cli cli(tree, printOutput);
    cli.run();
    
    delete tree;
    return 0;
}