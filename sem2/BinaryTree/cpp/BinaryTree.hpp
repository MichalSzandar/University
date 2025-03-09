#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <iostream>

template <typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        
        Node(const T& value);
        ~Node();
    };
    
    Node* root;

    void insert(Node*& node, const T& value);
    void inorder(const Node* node) const;
    void destroyTree(Node* node);
    bool search(Node* node, const T& value);
    void erase(Node*& node, const T& value);
    //void printBT(const std::string& prefix, const Node* node, bool isLeft)
    Node* findMin(Node* node);
    void printBT(const std::string& prefix, const Node* node, bool isLeft);

public:
    BinaryTree();
    ~BinaryTree();

    void insert(const T& value);
    bool search(const T& value);
    void erase(const T& value);
    void inorder() const;
    void printBT();
};




#endif
