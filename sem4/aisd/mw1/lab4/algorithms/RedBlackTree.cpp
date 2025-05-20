#include "../include/RedBlackTree.hpp"

bool RedBlackTree::insert(RBNode*& node, RBNode* parent, const int value) {
    if (node == nullptr) {
        node = new RBNode(value);
        node->parent = parent;
    } else if (isGreater(node->val, value)) {
        node_ops++;
        insert(node->left, node, value);
    } else if (isGreater(value, node->val)) {
        node_ops++;
        insert(node->right, node, value);
    } else {
        return false;
    }

    fixViolation(node);

    return true;
}

bool RedBlackTree::remove(RBNode*& node, const int value) {
    // Implement the remove logic for Red-Black Tree
    // This is a placeholder implementation
    return false;
}

void RedBlackTree::fixViolation(RBNode*& node) {
    if(node->parent == nullptr) {
        std::cout << "root node color is black" << node->val << std::endl;
        node->isBlack = true;
        return;
    }

    if (!node->isBlack && !node->parent->isBlack) {
        std::cout<<"fix violation on node "<< node->val << std::endl;
        RBNode* grandparent = node->parent->parent;
        std::cout<<"grandparent "<< grandparent->val << std::endl;
        if (grandparent == nullptr) {
            node->parent->isBlack = true;
            return;
        }

        RBNode* uncle = (node->parent == grandparent->left) ? grandparent->right : grandparent->left;
        std::cout<<"uncle "<< (uncle ? std::to_string(uncle->val) : "null") << std::endl;
        if (uncle && !uncle->isBlack) {
            //uncle is red
            std::cout<<"uncle is red"<< std::endl;
            uncle->isBlack = true;
            node->parent->isBlack = true;
            grandparent->isBlack = false;
            fixViolation(grandparent);
        } else if (node == node->parent->left && node->parent == grandparent->left) {
            RBNode* oldGrandparent = grandparent;
            rotateRight(grandparent);
        
            // After rotate, node->parent is the new root of this subtree
            RBNode* newParent = node->parent;
            if (newParent) newParent->isBlack = true;
            if (oldGrandparent) oldGrandparent->isBlack = false;

        } else if (node == node->parent->right && node->parent == grandparent->left) {
            //left right case
            std::cout<<"left right case"<< std::endl;
            rotateLeft(node->parent);
            rotateRight(grandparent);
            node->isBlack = true;
            grandparent->isBlack = false;
        } else if (node == node->parent->right && node->parent == grandparent->right) {
            //right right case
            rotateLeft(grandparent);
            node->parent->isBlack = true;
            grandparent->isBlack = false;
        } else if (node == node->parent->left && node->parent == grandparent->right) {
            //right left case
            rotateRight(node->parent);
            rotateLeft(grandparent);
            node->isBlack = true;
            grandparent->isBlack = false;
        }
    }
}

void RedBlackTree::rotateLeft(RBNode*& x) {
    RBNode* y = x->right;
    x->right = y->left;
    if (y->left != nullptr) y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == nullptr) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void RedBlackTree::rotateRight(RBNode*& y) {
    RBNode* x = y->left;
    y->left = x->right;
    if (x->right != nullptr) x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == nullptr) {
        root = x;
    } else if (y == y->parent->right) {
        y->parent->right = x;
    } else {
        y->parent->left = x;
    }
    x->right = y;
    y->parent = x;
}

//--------------------------------------------------------------------------------------------------------
//Utils
//--------------------------------------------------------------------------------------------------------

bool RedBlackTree::insert(const int value) {
    return insert(root, nullptr, value);
}

bool RedBlackTree::remove(const int value) {
    return remove(root, value);
}

void RedBlackTree::inorder(RBNode* node) const {
    if (node != nullptr) {
        inorder(node->left);
        std::cout << node->val << " ";
        inorder(node->right);
    }
}

void RedBlackTree::inorder() const {
    inorder(root);
}

int RedBlackTree::getHeight(RBNode* node) const{
    if (node == nullptr) {
        return 0;
    }
    return std::max(getHeight(node->left), getHeight(node->right)) + 1;
}

int RedBlackTree::getHeight() const {
    return getHeight(root);
}

void RedBlackTree::print(const std::string& prefix, const RBNode* node, bool isLeft) const{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        std::cout << node->val << std::endl;

        print( prefix + (isLeft ? "│   " : "    "), node->left, true);
        print( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void RedBlackTree::print() const {
    print("", root, false);
}

void RedBlackTree::destroyTree(RBNode* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

RedBlackTree::~RedBlackTree() {
    destroyTree(root);
}