#ifndef FIFOQUEUE_HPP
#define FIFOQUEUE_HPP

#include <iostream>
#include <vector>

template <typename T>
class FIFOQueue {
private:
    std::vector<T> queue;
public:
    FIFOQueue() {
        queue = std::vector<T>();
    }

    ~FIFOQueue() = default;

    void push(T& data) {
        queue.push_back(data);
    }

    T& pop() {
        T& data = queue.front();
        queue.erase(queue.begin());
        return data;
    }
    T& peek() {
        return queue.front();
    }
    bool isEmpty() {
        return queue.empty();
    }
    void print() {
        for (T& data : queue) {
            std::cout << data << " ";
        }
        std::cout << std::endl;
    }
};
#endif // FIFOQUEUE_HPP