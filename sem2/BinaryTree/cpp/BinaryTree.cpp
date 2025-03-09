#include "BinaryTree.hpp"

template <typename T>
BinaryTree<T>::Node::Node(const T& value) : data(value), left(nullptr), right(nullptr) {}

template <typename T>
BinaryTree<T>::Node::~Node(){}

template <typename T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}

template <typename T>
BinaryTree<T>::~BinaryTree() {
    destroyTree(root);
}

template <typename T>
void BinaryTree<T>::insert(Node*& node, const T& value) {
    if (!node) {
        node = new Node(value);
    } else if (value < node->data) {
        insert(node->left, value);
    } else if(value > node->data){
        insert(node->right, value);
    } else
        std::cout<<"Element already exists\n";

}

template <typename T>
void BinaryTree<T>::insert(const T& value) {
    insert(root, value);
}

template <typename T>
void BinaryTree<T>::inorder(const Node* node) const {
    if (node) {
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }
}

template <typename T>
void BinaryTree<T>::inorder() const {
    inorder(root);
    std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::destroyTree(Node* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
        node = nullptr;
    }
}

template<typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::findMin(Node* node)
{
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

template<typename T>
void BinaryTree<T>::erase(Node*& node, const T& value)
{
    if (node == nullptr) {
        std::cout<<"element doesn't exist.\n";
        return; 
    } else if (value < node->data) {
        erase(node->left, value); 
    } else if (value > node->data) {
        erase(node->right, value); 
    } else 
    {
        if (node->left == nullptr && node->right == nullptr) 
        {
            delete node;
            node = nullptr; 
        }
        else if (node->left == nullptr) 
        {
            Node* temp = node;
            node = node->right;
            delete temp;
        } else if (node->right == nullptr) 
        {
            Node* temp = node;
            node = node->left;
            delete temp;
        }
        else {
            Node* minRight = findMin(node->right);
            node->data = minRight->data;
            erase(node->right, minRight->data);
        }
    }
}

template<typename T>
void BinaryTree<T>::erase(const T& value)
{
    erase(root, value);
}

template<typename T>
bool BinaryTree<T>::search(Node* node, const T& value)
{
    if(node==nullptr) return false;
    if(node->data == value) return true;
    if(node->data < value) 
        return search(node->right, value);
    else
        return search(node->left, value);
}

template<typename T>
bool BinaryTree<T>::search(const T& value)
{
    return search(root, value);
}

template<typename T>
void BinaryTree<T>::printBT(const std::string& prefix, const Node* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        std::cout << node->data << std::endl;

        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

template<typename T>
void BinaryTree<T>::printBT()
{
    printBT("", root, false);    
}

template class BinaryTree<int>;
template class BinaryTree<double>;
template class BinaryTree<std::string>;

// IEEE
// 0.1 + 0.2 == 0.3