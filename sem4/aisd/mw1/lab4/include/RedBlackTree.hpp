#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include "Tree.hpp"

class RedBlackTree : public Tree {
    private:
        struct RBNode {
            int val;
            bool isBlack;
            RBNode* parent;
            RBNode* left;
            RBNode* right;
            RBNode(const int value) : val(value), isBlack(false), parent(nullptr), left(nullptr), right(nullptr) {}
        };

        RBNode* root;

        bool ll; // Left-Left Rotation flag
        bool rr; // Right-Right Rotation flag
        bool lr; // Left-Right Rotation flag
        bool rl; // Right-Left Rotation flag


        RBNode* rotateLeft(RBNode* node);
        RBNode* rotateRight(RBNode* node);

        bool isLeft(RBNode* node);
        
        RBNode* minimum(RBNode* node);
        RBNode* BSTReplace(RBNode* node);
        void transplant(RBNode* u, RBNode* v);
        void fixDoubleBlack(RBNode* x);
        RBNode* getSibling(RBNode* node);

        RBNode* insert(RBNode* node, const int value);
        void fixRemove(RBNode* x, RBNode* parent);
        bool remove(RBNode* node);

        void inorder(RBNode* node) const;
        int getHeight(RBNode* node) const;
        void destroyTree(RBNode* node);
        void print(const std::string& prefix, const RBNode* node, bool isLeft) const;

        RBNode* getRight(RBNode* node);
        RBNode* getLeft(RBNode* node);
        RBNode* getParent(RBNode* node);

        void setLeft(RBNode* node, RBNode* left);
        void setRight(RBNode* node, RBNode* right);
        void setParent(RBNode* node, RBNode* parent);

        void assign(RBNode*& x, RBNode* y);

    public:
        RedBlackTree();
        ~RedBlackTree();

        bool insert(const int value) override;
        bool remove(const int value) override;

        void inorder() const override;
        void print() const override;
        int getHeight() const override;
};
#endif