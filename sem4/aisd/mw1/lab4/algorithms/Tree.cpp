#include "../include/Tree.hpp"

int Tree::getKeyComparisons() const {
    return key_comparisons;
}

int Tree::getNodeOps() const {
    return node_ops;
}

bool Tree::isGreater(int a, int b) {
    key_comparisons++;
    return a > b;
}