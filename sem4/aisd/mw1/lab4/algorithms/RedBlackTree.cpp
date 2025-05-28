#include "../include/RedBlackTree.hpp"

RedBlackTree::RedBlackTree() : root(nullptr), ll(false), rr(false), lr(false), rl(false) {}

RedBlackTree::RBNode* RedBlackTree::insert(RBNode* node, const int value) {
    bool f = false; // Flag to check RED-RED conflict

    if (node == nullptr)
        return new RBNode(value);
    else if (value < node->val) {
        node->left = insert(node->left, value);
        node->left->parent = node;
        if (node != root) {
            if (!node->isBlack && !node->left->isBlack)
                f = true;
        }
    } else {
        node->right = insert(node->right, value);
        node->right->parent = node;
        if (node != root) {
            if (!node->isBlack && !node->right->isBlack)
                f = true;
        }
    }

    // Perform rotations
    if (ll) {
        node = rotateLeft(node);
        node->isBlack = true;
        node->left->isBlack = false;
        ll = false;
    } else if (rr) {
        node = rotateRight(node);
        node->isBlack = true;
        node->right->isBlack = false;
        rr = false;
    } else if (rl) {
        node->right = rotateRight(node->right);
        node->right->parent = node;
        node = rotateLeft(node);
        node->isBlack = true;
        node->left->isBlack = false;
        rl = false;
    } else if (lr) {
        node->left = rotateLeft(node->left);
        node->left->parent = node;
        node = rotateRight(node);
        node->isBlack = true;
        node->right->isBlack = false;
        lr = false;
    }

    // Handle RED-RED conflicts
    if (f) {
        if (node->parent->right == node) {
            if (node->parent->left == nullptr || node->parent->left->isBlack == true) {
                if (node->left != nullptr && node->left->isBlack == false)
                    rl = true;
                else if (node->right != nullptr && node->right->isBlack == false)
                    ll = true;
            } else {
                node->parent->left->isBlack = true;
                node->isBlack = true;
                if (node->parent != this->root)
                    node->parent->isBlack = false;
            }
        } else {
            if (node->parent->right == nullptr || node->parent->right->isBlack == true) {
                if (node->left != nullptr && node->left->isBlack == false)
                    rr = true;
                else if (node->right != nullptr && node->right->isBlack == false)
                    lr = true;
            } else {
                node->parent->right->isBlack = true;
                node->isBlack = true;
                if (node->parent != this->root)
                    node->parent->isBlack = false;
            }
        }
        f = false;
    }
    return node;
}

RedBlackTree::RBNode* RedBlackTree::rotateLeft(RBNode* node) {
    RBNode* x = node->right;
    RBNode* y = x->left;
    x->left = node;
    node->right = y;
    node->parent = x;
    if (y != nullptr)
        y->parent = node;
    return x;
}

RedBlackTree::RBNode* RedBlackTree::rotateRight(RBNode* node) {
    RBNode* x = node->left;
    RBNode* y = x->right;
    x->right = node;
    node->left = y;
    node->parent = x;
    if (y != nullptr)
        y->parent = node;
    return x;
}

bool RedBlackTree::isLeft(RBNode* node) {
    node_ops++;
    return node->parent && node->parent->left == node; // Check if node is a left child
}

RedBlackTree::RBNode* RedBlackTree::minimum(RBNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

void RedBlackTree::transplant(RBNode* u, RBNode* v) {
    if (u->parent == nullptr) {
        root = v; // If u is root, update root
    } else if (u == u->parent->left) {
        u->parent->left = v; // If u is left child, update parent's left child
    } else {
        u->parent->right = v; // If u is right child, update parent's right child
    }
    if (v != nullptr) {
        v->parent = u->parent; // Update v's parent
    }
}

RedBlackTree::RBNode* RedBlackTree::BSTReplace(RBNode* node) {
    if (node->left != nullptr && node->right != nullptr) {
        return minimum(node->right); // If node has two children, return the minimum of the right subtree
    } else if (node->left != nullptr) {
        return node->left; // If node has only left child, return it
    } else if (node->right != nullptr) {
        return node->right; // If node has only right child, return it
    } else {
        return nullptr; // If node is a leaf, return nullptr
    }
}

RedBlackTree::RBNode* RedBlackTree::getSibling(RBNode* node) {
    if (node == nullptr || node->parent == nullptr) {
        return nullptr; // No sibling if node is null or has no parent
    }
    if (node == node->parent->left) {
        return node->parent->right; // If node is left child, return parent's right child
    } else {
        return node->parent->left; // If node is right child, return parent's left child
    }
}

void RedBlackTree::fixDoubleBlack(RBNode *x) {
    if (x == root)
      // Reached root
      return;

    RBNode *sibling = getSibling(x);
    RBNode* parent = x->parent;

    if (sibling == nullptr) {
      // No sibling, double black pushed up
      fixDoubleBlack(parent);
    } else {
      if (sibling->isBlack == false) {
        // Sibling red
        parent->isBlack = false;
        sibling->isBlack = true;
        if (isLeft(sibling)) {
          // left case
          parent = rotateRight(parent);
        } else {
          // right case
          parent = rotateLeft(parent);
        }
        fixDoubleBlack(x);
      } else {
        // Sibling black
        if ((sibling->left != nullptr && sibling->left->isBlack == false) ||
            (sibling->right != nullptr && sibling->right->isBlack == false)) {
          // at least 1 red children
          if (sibling->left != nullptr && sibling->left->isBlack == false) {
            if (isLeft(sibling)) {
              // left left
              sibling->left->isBlack = sibling->isBlack;
              sibling->isBlack = parent->isBlack;
              parent = rotateRight(parent);
            } else {
              // right left
              sibling->left->isBlack = parent->isBlack;
              sibling = rotateRight(sibling);
              parent = rotateLeft(parent);
            }
          } else {
            if (isLeft(sibling)) {
              // left right
              sibling->right->isBlack = parent->isBlack;
              sibling = rotateLeft(sibling);
              parent = rotateRight(parent);
            } else {
              // right right
              sibling->right->isBlack = sibling->isBlack;
              sibling->isBlack = parent->isBlack;
              parent = rotateLeft(parent);
            }
          }
          parent->isBlack = true;
        } else {
          // 2 black children
          sibling->isBlack = false;
          if (parent->isBlack == true)
            fixDoubleBlack(parent);
          else
            parent->isBlack = true;
        }
      }
    }
  }

bool RedBlackTree::remove(RBNode* node) {
    RBNode* v = node;
    RBNode* u = BSTReplace(node);

    bool uvBlack = ((u == nullptr || u->isBlack) && (v->isBlack));
    RBNode* parent = v->parent;

    if (u == nullptr) {
        //v is leaf
        if (v == root) {
            root = nullptr; // If v is root, set root to nullptr
        } else {
            if (uvBlack) {
                //u is black and v is black
                fixDoubleBlack(v);
            } else {
                //u or v is red
                if (getSibling(v) != nullptr) {
                    getSibling(v)->isBlack = false; // Set sibling to red
                }
            }

            if (isLeft(v)) {
                parent->left = nullptr; // Remove v from its parent's left child
            } else {
                parent->right = nullptr; // Remove v from its parent's right child
            }
        }

        delete v;
        return true; // Successfully removed leaf node
    }

    if (v->left == nullptr || v->right == nullptr) {
        //v has one child
        if (v == root) {
            v->val = u->val; // If v is root, replace value with u's value
            v->left = nullptr;
            v->right = nullptr;
            delete u;
        } else {
            if (isLeft(v)) {
                parent->left = u; // If v is left child, replace with u
            } else {
                parent->right = u; // If v is right child, replace with u
            }
            delete v;
            u->parent = parent; // Update u's parent
            if (uvBlack) {
                fixDoubleBlack(u);
            } else {
                u->isBlack = true;
            }
        }
        return true; // Successfully removed node with one child
    } 
    //v has two children
    std::swap(v->val, u->val); // Swap values of v and u
    return remove(u); // Recursively remove u
}

//--------------------------------------------------------------------------------------------------------
//Utils
//--------------------------------------------------------------------------------------------------------

bool RedBlackTree::insert(const int value) {
    if (root == nullptr) {
        root = new RBNode(value);
        root->isBlack = true; // Root is always black
        return true;
    } else 
        root = insert(root, value);
    
    return true;
}

bool RedBlackTree::remove(const int value) {
    if (root == nullptr) {
        return false; // Tree is empty
    }

    RBNode* node = root;
    while (node && node->val != value) {
        if (isGreater(node->val, value)) {
            node_ops++;
            node = node->left;
        } else {
            node_ops++;
            node = node->right;
        }
    }

    if (node == nullptr) {
        return false; // Value not found
    }
    node_ops++;

    if (node->val == value) {
        remove(node);
        return true; // Successfully removed the node
    }
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

void RedBlackTree::print(const std::string& prefix, const RBNode* node, bool isLeft) const {
    if (node != nullptr) {
        std::cout << prefix;
        std::cout << (isLeft ? "├──" : "└──" );
        std::cout << node->val << (node->isBlack ? "B" : "R") << std::endl; // Show color
        print(prefix + (isLeft ? "│   " : "    "), node->left, true);
        print(prefix + (isLeft ? "│   " : "    "), node->right, false);
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