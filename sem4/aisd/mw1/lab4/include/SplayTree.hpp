#ifndef SPLAY_TREE_HPP
#define SPLAY_TREE_HPP

#include "Tree.hpp"

class SplayTree : public Tree {
    private:
        struct Node {
            int val;
            Node* left;
            Node* right;
            Node(const int value) : val(value), left(nullptr), right(nullptr) {}
        };

        Node* root;

        Node* rotateLeft(Node* node);
        Node* rotateRight(Node* node);
        Node* splay(Node* node, const int value);
        Node* insert(Node* node, const int value);
        Node* remove(Node* node, const int value);
        void inorder(Node* node) const;
        int getHeight(Node* node) const;
        void destroyTree(Node* node);
        void print(const std::string& prefix, const Node* node, bool isLeft) const;

        Node* getRight(Node* node);
        Node* getLeft(Node* node);
        void setRight(Node* node, Node* right);
        void setLeft(Node* node, Node* left);
        bool isLeft(Node* node);

    public:
        SplayTree();
        ~SplayTree();

        bool insert(const int value) override;
        bool remove(const int value) override;

        void inorder() const override;
        void print() const override;
        int getHeight() const override;
};

#endif