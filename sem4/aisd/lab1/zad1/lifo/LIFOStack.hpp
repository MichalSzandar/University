#ifndef LIFOSTACK_HPP
#define LIFOSTACK_HPP

#include <iostream>
#include <vector>

template <typename T>
class LIFOStack {
private:
    std::vector<T> stack;
public:
    LIFOStack() = default;
    ~LIFOStack() = default;

    void push(T& data) {
        stack.push_back(data);
    }

    T& pop() {
        T& data = stack.back();
        stack.pop_back();
        return data;
    }

    T& peek() {
        return stack.back();
    }

    bool isEmpty() {
        return stack.empty();
    }

    void print() {
        for (T& data : stack) {
            std::cout << data << " ";
        }
        std::cout << std::endl;
    }

    void clear() {
        stack.clear();
    }

    size_t size() {
        return stack.size();
    }

};

#endif // LIFOSTACK_HPP