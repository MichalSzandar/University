#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include "Tree.hpp"

class RedBlackTree : public Tree {
    private:
        struct RBNode {
            RBNode* parent;
            RBNode* left;
            RBNode* right;
            int val;
            bool isBlack;
            RBNode(const int value) : val(value), isBlack(false), parent(nullptr), left(nullptr), right(nullptr) {}
        };

        RBNode* root;

        bool insert(RBNode*& node, RBNode* parent, const int value);
        bool remove(RBNode*& node, const int value);

        void fixViolation(RBNode*& node);
        void rotateLeft(RBNode*& x);
        void rotateRight(RBNode*& y);

        void inorder(RBNode* node) const;
        int getHeight(RBNode* node) const;
        void destroyTree(RBNode* node);
        void print(const std::string& prefix, const RBNode* node, bool isLeft) const;

    public:
        RedBlackTree() = default;
        ~RedBlackTree();

        bool insert(const int value) override;
        bool remove(const int value) override;

        void inorder() const override;
        void print() const override;
        int getHeight() const override;
};
#endif