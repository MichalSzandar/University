#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include <iostream>

class DoublyLinkedList {
private:
    class Node {
        public:
            int data;
            Node* next;
            Node* prev;

            Node(int val) : data(val), next(nullptr), prev(nullptr) {}
            ~Node() = default;
    };

    Node* head;

public:
    DoublyLinkedList(): head(nullptr) {};
    ~DoublyLinkedList() {
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
            newNode->prev = head;
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    void display() {
        if (!head) {
            std::cout << "List is empty" << std::endl;
            return;
        }

        Node* current = head;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);
        std::cout << std::endl;
    }

    static void merge(DoublyLinkedList& list1, DoublyLinkedList& list2) {
        if (!list1.head) {
            list1.head = list2.head;
            list2.head = nullptr;
            return;
        }
        if (!list2.head) {
            return;
        }

        Node* tail1 = list1.head->prev;
        Node* tail2 = list2.head->prev;

        tail1->next = list2.head;
        list2.head->prev = tail1;

        tail2->next = list1.head;
        list1.head->prev = tail2;
    }

    static int searchForward(DoublyLinkedList& list, int data) {
        if (!list.head) {
            return 0;
        }

        int comparisons = 0;
        Node* current = list.head;
        do {
            comparisons++;
            if (current->data == data) {
                return comparisons;
            }
            current = current->next;
        } while (current != list.head);

        return comparisons;
    }

    static int searchBackward(DoublyLinkedList& list, int data) {
        if (!list.head) {
            return 0;
        }

        int comparisons = 0;
        Node* current = list.head;
        do {
            comparisons++;
            if (current->data == data) {
                return comparisons;
            }
            current = current->prev;
        } while (current != list.head);

        return comparisons;
    }

};

#endif // DOUBLY_LINKED_LIST_HPP