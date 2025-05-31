#include "../include/SplayTree.hpp"

SplayTree::SplayTree() : root(nullptr) {}
SplayTree::~SplayTree() {
    destroyTree(root);
}

SplayTree::Node* SplayTree::insert(Node* node, const int val) {
    if (node == nullptr) {
        return new Node(val);
    }
    
    node = splay(node, val);

    if(node->val == val) {
        return node; // Duplicate value, no insertion
    }

    Node* newNode = new Node(val);

    if (isGreater(node->val, val)) {
        setRight(newNode, node);
        setLeft(newNode, getLeft(node));
        node->left = nullptr; // Clear left child of the old node
    } else if (isGreater(val, node->val)) {
        setRight(newNode, getRight(node));
        setLeft(newNode, node);
        node->right = nullptr; // Clear right child of the old node
    }
    return newNode; // Return the new root of the subtree
}

SplayTree::Node* SplayTree::remove(Node* node, const int val) {
    if (node == nullptr) {
        return nullptr; // Value not found
    }
    
    node = splay(node, val);

    if (node->val != val) {
        return node; // Value not found, return the current node
    }

    Node* temp = nullptr;
    if (!getLeft(node)) {
        temp = node;
        node = getRight(node);
    } else {
        temp = node;

        node = splay(getLeft(node), val);
        setRight(node, getRight(temp));
    }


    return node;  
}

SplayTree::Node* SplayTree::rotateRight(Node* x) {
    Node* y = getLeft(x);
    setLeft(x, getRight(y));
    setRight(y, x);
    return y;
}

SplayTree::Node* SplayTree::rotateLeft(Node* x) {
    Node* y = getRight(x);
    setRight(x, getLeft(y));
    setLeft(y, x);
    return y;
}

SplayTree::Node* SplayTree::splay(Node* node, const int val) {
    if (node == nullptr || node->val == val) {
        return node; // Node is already splayed or not found
    }
    
    if (isGreater(node->val, val)) {
        if (getLeft(node) == nullptr) {
            return node; // Value not found in left subtree
        }
        
        if (isGreater(getLeft(node)->val, val)) {
            setLeft(getLeft(node), splay(getLeft(getLeft(node)), val));
            node = rotateRight(node);

        } else if (isGreater(val, getLeft(node)->val)) {
            setRight(getLeft(node), splay(getRight(getLeft(node)), val));
            
            if (getRight(getLeft(node)) != nullptr) 
                setLeft(node, rotateLeft(getLeft(node)));
        } else {
            return node; // Value found
        }

        return (getLeft(node) == nullptr) ? node : rotateRight(node);

    } else {
        if (getRight(node) == nullptr) {
            return node; // Value not found in right subtree
        }
        
        if (isGreater(getRight(node)->val, val)) {
            setLeft(getRight(node), splay(getLeft(getRight(node)), val));

            if (getLeft(getRight(node)) != nullptr)
                setRight(node, rotateRight(getRight(node)));
        } else if (isGreater(val, getRight(node)->val)) {
            setRight(getRight(node), splay(getRight(getRight(node)), val));
            node = rotateLeft(node);
        } else {
            return node; // Value found
        }

        return (getRight(node) == nullptr) ? node : rotateLeft(node);
    }
}

//--------------------------------------------------------------------------------------------------------
// Funkcje pomocnicze
//--------------------------------------------------------------------------------------------------------

SplayTree::Node* SplayTree::getLeft(Node* node) {
    node_ops++;
    return node->left;
}

SplayTree::Node* SplayTree::getRight(Node* node) {
    node_ops++;
    return node->right;
}

void SplayTree::setLeft(Node* node, Node* left) {
    node_ops++;
    node->left = left;
}

void SplayTree::setRight(Node* node, Node* right) {
    node_ops++;
    node->right = right;
}

bool SplayTree::insert(const int val) {
    if (root == nullptr) {
        root = new Node(val);
        return true;
    }
    
    root = insert(root, val);
    return true;
}

bool SplayTree::remove(const int val) {
    if (root == nullptr) {
        return false; // Tree is empty
    }
    
    root = remove(root, val);
    return true;
}
void SplayTree::inorder(Node* node) const {
    if (node != nullptr) {
        inorder(node->left);
        std::cout << node->val << " ";
        inorder(node->right);
    }
}
void SplayTree::inorder() const {
    inorder(root);
    std::cout << std::endl;
}
void SplayTree::print(const std::string& prefix, const Node* node, bool isLeft) const {
    if (node != nullptr) {
        std::cout << prefix;
        std::cout << (isLeft ? "├──" : "└──");
        std::cout << node->val << std::endl;

        print(prefix + (isLeft ? "│   " : "    "), node->left, true);
        print(prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}
void SplayTree::print() const {
    print("", root, false);
}
int SplayTree::getHeight(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    return std::max(getHeight(node->left), getHeight(node->right)) + 1;
}
int SplayTree::getHeight() const {
    return getHeight(root);
}
void SplayTree::destroyTree(Node* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}