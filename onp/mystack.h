// Interfejs stosu na bazie kontenera std::vector.

#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include <cassert>
#include <vector>
#include <cctype>

template <typename T>
class MyStack {
    std::vector<T> lst;
public:
    MyStack(int s=10) { lst.reserve(s); } // default constructor
    ~MyStack() { lst.clear(); }
    MyStack(const MyStack& other); // copy constructor
    MyStack(MyStack&& other); // move constructor
    MyStack& operator=(const MyStack& other); // copy assignment operator, return *this
    MyStack& operator=(MyStack&& other); // move assignment operator, return *this
    bool empty() const { return lst.empty(); } // checks if the container has no elements
    bool full() const { return lst.size() == lst.capacity(); }
    int size() const { return lst.size(); }
    int max_size() const { return lst.capacity(); }
    void push(const T& item) { lst.push_back(item); }
    void push(T&& item) { lst.push_back(std::move(item)); }
    T& top() { return lst.back(); } // zwraca koniec, nie usuwa
    void pop() { lst.pop_back(); } // usuwa koniec
    void clear() { lst.clear(); }
    void display() {
        std::vector<int>::iterator it_lst = lst.begin();
        for(; it_lst != lst.end(); it_lst++) {
            std::cout <<* it_lst << " ";
        }
    }

};


int calculate(int a, int b, const std::string &operation) {
    if(operation == "+") {
        return a + b;
    }
    if(operation == "-") {
        return a - b;
    }    
    if(operation == "*") {
        return a * b;
    }
    if(operation == "/") {
        return a / b;
    }
    return -1;
}

bool isOperation(const std::string& op) {
    return op == "+" || op == "-" || op == "*" || op == "/";
}

int rpn(std::vector<std::string> input) {
    MyStack<int> stack1;
    int a, b;

    for (const auto& str : input)
    {
        if (isOperation(str))
        {
            a = stack1.top(); stack1.pop();
            b = stack1.top(); stack1.pop();

            stack1.push(calculate(b, a, str));
        }
        else
            stack1.push(std::stoi(str));
    }

    return stack1.top();

}

#endif