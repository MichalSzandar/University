#include "fifo/FIFOQueue.hpp"
#include "lifo/LIFOStack.hpp"
#include <iostream>

int main() {
    FIFOQueue<int> queue = FIFOQueue<int>();
    LIFOStack<int> stack = LIFOStack<int>();

    for (int i = 0; i < 50; i++) {
        queue.push(i);
        stack.push(i);
        std::cout << "Pushed " << i << std::endl;
    }

    queue.print();
    stack.print();

    while (!queue.isEmpty()) {
        std::cout << "Popped " << queue.pop() << " from fifo and " << stack.pop()<< " from lifo" << std::endl;
    }

}