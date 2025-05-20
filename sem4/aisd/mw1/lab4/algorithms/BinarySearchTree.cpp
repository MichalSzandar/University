#include "../include/BinarySearchTree.hpp"

bool BinarySearchTree::insert(Node*& node, const int value) {
    if (node == nullptr) {
        node = new Node(value);
    } else if (isGreater(node->val, value)) {
        node_ops++;
        insert(node->left, value);
    } else if (isGreater(value, node->val)) {
        node_ops++;
        insert(node->right, value);
    } else {
        return false; // Duplicate value
    }
    return true;
}

bool BinarySearchTree::remove(Node*& node, const int value) {
    if (!node) {
        return false; // Value not found
    }

    if (isGreater(node->val, value)) {
        node_ops++;
        return remove(node->left, value);
    } else if (isGreater(value, node->val)) {
        node_ops++;
        return remove(node->right, value);
    } else {
        // Node with only one child or no child
        if (!node->left) {
            node_ops++;
            Node* temp = node->right;
            delete node;
            node = temp;
        } else if (!node->right) {
            Node* temp = node->left;
            delete node;
            node = temp;
        } else {
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = node->right;
            node_ops++;

            while (temp && temp->left) {
                node_ops++;
                temp = temp->left;
            }

            node->val = temp->val; // Copy the inorder successor's value to this node
            node_ops++;
            remove(node->right, temp->val); // Delete the inorder successor
            node_ops++;
        }
        return true;
    }
}

bool BinarySearchTree::insert(const int value) {
    return insert(root, value);
}

bool BinarySearchTree::remove(const int value) {
    return remove(root, value);
}

void BinarySearchTree::inorder(Node* node) const {
    if (node != nullptr) {
        inorder(node->left);
        std::cout << node->val << " ";
        inorder(node->right);
    }
}

void BinarySearchTree::inorder() const {
    inorder(root);
    std::cout << std::endl;
}

void BinarySearchTree::print(const std::string& prefix, const Node* node, bool isLeft) const{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        std::cout << node->val << std::endl;

        print( prefix + (isLeft ? "│   " : "    "), node->left, true);
        print( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void BinarySearchTree::print() const {
    print("", root, false);
}

int BinarySearchTree::getHeight(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    return std::max(getHeight(node->left), getHeight(node->right)) + 1;
}

int BinarySearchTree::getHeight() const {
    return getHeight(root);
}

void BinarySearchTree::destroyTree(Node* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}
BinarySearchTree::~BinarySearchTree() {
    destroyTree(root);
}
