#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>

class Tree {
    protected:
        int key_comparisons = 0;
        int node_ops = 0;

        bool isGreater(int a, int b);

    public:
        Tree() = default;
        ~Tree() = default;
    
        virtual bool insert(const int value) = 0;
        virtual bool remove(const int value) = 0;

        virtual void inorder() const = 0;
        virtual void print() const = 0;

        virtual int getHeight() const = 0;
        int getKeyComparisons() const;
        int getNodeOps() const;
};


#endif