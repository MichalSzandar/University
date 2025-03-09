#include "SinglyLinkedList.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));

    SinglyLinkedList list1, list2;

    for (int i = 0; i < 10; i++) {
        list1.insert(rand() % 90 + 10);
        list2.insert(rand() % 90 + 10);
    }

    std::cout << "List 1: ";
    list1.display();
    std::cout << "List 2: ";
    list2.display();

    SinglyLinkedList::merge(list1, list2);
    std::cout << "Merged: ";
    list1.display();

    SinglyLinkedList list3;

    std::vector<int> T(10000);
    for (int i = 0; i < 10000; i++) {
        T[i] = rand() % 100001;
        list3.insert(T[i]);
    }

    int totalComparisons = 0;
    for (int i = 0; i < 10000; i++) {
        totalComparisons += SinglyLinkedList::search(list3, T[rand() % 10000]);
    }
    std::cout << "Average comparisons for existing numbers: " << totalComparisons / 10000.0 << std::endl;

    totalComparisons = 0;
    for (int i = 0; i < 10000; i++) {
        totalComparisons += SinglyLinkedList::search(list3, rand() % 100001);
    }
    std::cout << "Average comparisons for random numbers: " << totalComparisons / 10000.0 << std::endl;

    return 0;
}