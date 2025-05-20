#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP
#include "Tree.hpp"

class BinarySearchTree : public Tree {
    private:
        struct Node {
            int val;
            Node* left;
            Node* right;
            Node(const int value) : val(value), left(nullptr), right(nullptr) {}
            ~Node() = default;
        };

        Node* root;

        bool insert(Node*& node, const int value);
        bool remove(Node*& node, const int value);

        void inorder(Node* node) const;
        int getHeight(Node* node) const;
        void destroyTree(Node* node);
        void print(const std::string& prefix, const Node* node, bool isLeft) const;

    public:
        BinarySearchTree() = default;
        ~BinarySearchTree();

        bool insert(const int value) override;
        bool remove(const int value) override;

        void inorder() const override;
        void print() const override;
        int getHeight() const override;
};

#endif