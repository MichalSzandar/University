#include "../include/BinarySearchTree.hpp"
#include "../include/RedBlackTree.hpp"
#include "../include/CLI.hpp"

int main(int argc, char* argv[]) {
    /*if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <tree_type> <print_output>" << std::endl;
        std::cerr << "Available tree types: BST" << std::endl;
        return 1;
    }*/

    //std::string treeType = argv[1];
    Tree* tree = nullptr;
    bool printOutput = false;

    /*if (argc > 2) {
        printOutput = std::string(argv[2]) == "-p";
    }*/
  
    /*if (treeType == "BST") {
        tree = new BinarySearchTree();
    } else if (treeType == "RBT") {
        tree = new RedBlackTree();
    } else {
        std::cerr << "Unknown tree type: " << treeType << std::endl;
        return 1;
    }*/

    tree = new RedBlackTree();
    tree->insert(7);
    tree->insert(3);
    tree->insert(2);
    /*printOutput = true;

    Cli cli(tree, printOutput);
    cli.run();*/
    
    delete tree;
    return 0;
}