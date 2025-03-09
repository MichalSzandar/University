#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

#include <iostream>

class SinglyLinkedList {
private:
    class Node {
        public:
            int data;
            Node* next;

            Node(int val) : data(val), next(nullptr) {}
            ~Node() = default;
    };

    Node* head;

public:
    SinglyLinkedList(): head(nullptr) {};
    ~SinglyLinkedList() {
        if (!head) return;
    
        Node* current = head;
        Node* nextNode = nullptr;
        while (current->next != head) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        delete current;
    }
    

    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
        }
    }

    static void merge(SinglyLinkedList& list1, SinglyLinkedList& list2) {
        if (!list1.head) {
            list1.head = list2.head;
            list2.head = nullptr;
            return;
        }
        if (!list2.head) {
            return;
        }
    
        Node* tail1 = list1.head;
        while (tail1->next != list1.head) {
            tail1 = tail1->next;
        }
    
        Node* tail2 = list2.head;
        while (tail2->next != list2.head) {
            tail2 = tail2->next;
        }
    
        tail1->next = list2.head;
        tail2->next = list1.head;
        
        list2.head = nullptr;
    }
    

    static int search(SinglyLinkedList& list, int data) {
        if(list.head == nullptr) {
            return 0;
        }

        Node* current = list.head;
        int comparisons = 0;
        do {
            comparisons++;
            if(current->data == data) {
                return comparisons;
            }
            current = current->next;
        } while (current != list.head);
        return comparisons;
    }

    void display() {
        Node* current = head;
        if(current == nullptr) {
            return;
        }

        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);
        std::cout << std::endl;
    }

};

#endif // SINGLY_LINKED_LIST_HPP