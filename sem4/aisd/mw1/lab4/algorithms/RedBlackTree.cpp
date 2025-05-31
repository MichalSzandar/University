#include "../include/RedBlackTree.hpp"

// Constructor
RedBlackTree::RedBlackTree() : root(nullptr), ll(false), rr(false), lr(false), rl(false) {}

// Insertion logic (unchanged)
RedBlackTree::RBNode* RedBlackTree::insert(RBNode* node, const int value) {
    bool f = false; // Flag to check RED-RED conflict

    if (node == nullptr)
        return new RBNode(value);
    else if (isGreater(node->val, value)) {
        setLeft(node, insert(getLeft(node), value));
        setParent(getLeft(node), node);

        if (node != root) {
            if (!node->isBlack && !getLeft(node)->isBlack)
                f = true;
        }
    } else if (isGreater(value, node->val)) {
        setRight(node, insert(getRight(node), value));
        setParent(getRight(node), node);

        if (node != root) {
            if (!node->isBlack && !getRight(node)->isBlack)
                f = true;
        }
    } else {
        // Duplicate value, do nothing
        return node;
    }

    // Perform rotations
    if (ll) {
        node = rotateLeft(node);
        node->isBlack = true;
        getLeft(node)->isBlack = false;
        ll = false;
    } else if (rr) {
        node = rotateRight(node);
        node->isBlack = true;
        getRight(node)->isBlack = false;
        rr = false;
    } else if (rl) {
        setRight(node, rotateRight(getRight(node)));
        setParent(getRight(node), node);

        node = rotateLeft(node);
        node->isBlack = true;
        getLeft(node)->isBlack = false;
        rl = false;
    } else if (lr) {
        setLeft(node, rotateLeft(getLeft(node)));
        setParent(getLeft(node), node);

        node = rotateRight(node);
        node->isBlack = true;
        getRight(node)->isBlack = false;
        lr = false;
    }

    // Handle RED-RED conflicts
    if (f) {
        if (!isLeft(node)) {
            if (getLeft(getParent(node)) == nullptr || getLeft(getParent(node))->isBlack == true) {
                if (getLeft(node) != nullptr && getLeft(node)->isBlack == false)
                    rl = true;
                else if (getRight(node) != nullptr && getRight(node)->isBlack == false)
                    ll = true;
            } else {
                getLeft(getParent(node))->isBlack = true;
                node->isBlack = true;
                if (getParent(node) != root)
                    getParent(node)->isBlack = false;
            }
        } else {
            if (getRight(getParent(node)) == nullptr || getRight(getParent(node))->isBlack == true) {
                if (getLeft(node) != nullptr && getLeft(node)->isBlack == false)
                    rr = true;
                else if (getRight(node) != nullptr && getRight(node)->isBlack == false)
                    lr = true;
            } else {
                getRight(getParent(node))->isBlack = true;
                node->isBlack = true;
                if (getParent(node) != root)
                    getParent(node)->isBlack = false;
            }
        }
        f = false;
    }
    return node;
}

// Improved rotation: updates parent pointers and root if necessary
RedBlackTree::RBNode* RedBlackTree::rotateLeft(RBNode* x) {
    RBNode* y = getRight(x);
    setRight(x, getLeft(y));
    if (getLeft(y) != nullptr)
        setParent(getLeft(y), x);

    setParent(y, x->parent);

    if (getParent(x) == nullptr)
        root = y;
    else if (isLeft(x))
        setLeft(x->parent, y);
    else
        setRight(x->parent, y);

    setLeft(y, x);
    setParent(x, y);
    return y;
}

RedBlackTree::RBNode* RedBlackTree::rotateRight(RBNode* x) {
    RBNode* y = getLeft(x);
    setLeft(x, getRight(y));
    if (getRight(y) != nullptr)
        setParent(getRight(y), x);

    setParent(y, x->parent);

    if (getParent(x) == nullptr)
        root = y;
    else if (isLeft(x))
        setLeft(x->parent, y);
    else
        setRight(x->parent, y);

    setRight(y, x);
    setParent(x, y);
    return y;
}

void RedBlackTree::fixDoubleBlack(RBNode *x) {
    if (x == root)
         // Reached root
        return;

    RBNode *sibling = getSibling(x);
    RBNode* parent = getParent(x);

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
        if ((getLeft(sibling) != nullptr && getLeft(sibling)->isBlack == false) ||
            (getRight(sibling) != nullptr && getRight(sibling)->isBlack == false)) {
          // at least 1 red children
          if (getLeft(sibling) != nullptr && getLeft(sibling)->isBlack == false) {
            if (isLeft(sibling)) {
              // left left
              getLeft(sibling)->isBlack = sibling->isBlack;
              sibling->isBlack = parent->isBlack;
              parent = rotateRight(parent);
            } else {
              // right left
              getLeft(sibling)->isBlack = parent->isBlack;
              sibling = rotateRight(sibling);
              parent = rotateLeft(parent);
            }
          } else {
            if (isLeft(sibling)) {
              // left right
              getRight(sibling)->isBlack = parent->isBlack;
              sibling = rotateLeft(sibling);
              parent = rotateRight(parent);
            } else {
              // right right
              getRight(sibling)->isBlack = sibling->isBlack;
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
    RBNode* parent = getParent(v);

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
                setLeft(parent, nullptr);
            } else {
                setRight(parent, nullptr);
            }
        }

        delete v;
        return true; // Successfully removed leaf node
    }

    if (getLeft(v) == nullptr || getRight(v) == nullptr) {
        //v has one child
        if (v == root) {
            v->val = u->val; // If v is root, replace value with u's value
            setLeft(v, nullptr);
            setRight(v, nullptr);
            delete u;
        } else {
            if (isLeft(v)) {
                setLeft(parent, u); // If v is left child, replace with u
            } else {
                setRight(parent, u); // If v is right child, replace with u
            }
            delete v;
            setParent(u, parent); // Update u's parent
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
//Funkcje pomocnicze, które zwiększają liczniki
//--------------------------------------------------------------------------------------------------------

RedBlackTree::RBNode *RedBlackTree::getRight(RBNode *node) {
    node_ops++;
    return node->right;
}

RedBlackTree::RBNode *RedBlackTree::getLeft(RBNode *node) {
    node_ops++;
    return node->left;
}

RedBlackTree::RBNode *RedBlackTree::getParent(RBNode *node) {
    node_ops++;
    return node->parent;
}

void RedBlackTree::setLeft(RBNode *node, RBNode *left) {
    node_ops++;
    node->left = left;
}

void RedBlackTree::setRight(RBNode *node, RBNode *right) {
    node_ops++;
    node->right = right;
}

void RedBlackTree::setParent(RBNode *node, RBNode *parent) {
    node_ops++;
    node->parent = parent;
}

void RedBlackTree::assign(RBNode*& x, RBNode* y) {
    x = y;
}

bool RedBlackTree::isLeft(RBNode* node) {
    return getParent(node) && getLeft(getParent(node)) == node;
}

RedBlackTree::RBNode* RedBlackTree::minimum(RBNode* node) {
    while (getLeft(node) != nullptr) {
        node = getLeft(node);
    }

    return node;
}

// Proper transplant: updates parent pointers and handles root
void RedBlackTree::transplant(RBNode* u, RBNode* v) {
    if (getParent(u) == nullptr)
        root = v;
    else if (isLeft(u))
        setLeft(getParent(u), v);
    else
        setRight(getParent(u), v);
    if (v != nullptr)
        setParent(v, getParent(u));
}

RedBlackTree::RBNode* RedBlackTree::BSTReplace(RBNode* node) {
    if (getLeft(node) != nullptr && getRight(node) != nullptr)
        return minimum(node->right);
    else if (getLeft(node) != nullptr)
        return getLeft(node);
    else if (getRight(node) != nullptr)
        return getRight(node);
    else
        return nullptr;
}

RedBlackTree::RBNode* RedBlackTree::getSibling(RBNode* node) {
    if (node == nullptr || getParent(node) == nullptr)
        return nullptr;
    if (isLeft(node))
        return getRight(getParent(node));
    else
        return getLeft(getParent(node));
}

//--------------------------------------------------------------------------------------------------------

bool RedBlackTree::insert(const int value) {
    if (root == nullptr) {
        root = new RBNode(value);
        root->isBlack = true;
        return true;
    } else
        root = insert(root, value);

    return true;
}

bool RedBlackTree::remove(const int value) {
    if (root == nullptr)
        return false;

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

    if (node == nullptr)
        return false;
    node_ops++;

    if (node->val == value) {
        return remove(node);
    }
    return false; // <--- Missing return fixed
}

void RedBlackTree::inorder(RBNode* node) const {
    if (node != nullptr) {
        inorder(node->left);
        std::cout << node->val << (node->isBlack ? "B " : "R "); // Print color
        inorder(node->right);
    }
}

void RedBlackTree::inorder() const {
    inorder(root);
}

int RedBlackTree::getHeight(RBNode* node) const {
    if (node == nullptr)
        return 0;
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

void RedBlackTree::print() const
{
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