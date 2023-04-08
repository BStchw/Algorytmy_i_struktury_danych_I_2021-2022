// myqueue.h

#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include <cassert>
#include <vector>
#include <cctype>

template <typename T>
class MyQueue {
    T* tab;
    int msize; // największa możliwa liczba elementów plus jeden
    int head; // pierwszy do pobrania
    int tail; // pierwsza wolna pozycja
public:
    MyQueue(int s=10) : msize(s+1), head(0), tail(0) {
        tab = new T[s+1];
        assert( tab != nullptr );
    } // default constructor
    ~MyQueue() { delete [] tab; }
    MyQueue(const MyQueue& other) {
        msize = other.max_size()+1;
        head = other.head;
        tail = other.tail;
        tab = new T[msize-1];
        
        for(int i = head; i != tail; i=(i+1) % msize){
            tab[i] = other.tab[i];
        }
    } // copy constructor
    MyQueue& operator=(const MyQueue& other) {
        if (*this != other)
        {
            msize = other.max_size()+1;
            head = other.head;
            tail = other.tail;
            tab = new T[msize-1];
        
            for(int i = head; i != tail; i=(i+1) % msize){
                tab[i] = other.tab[i];
            }
        }
        return *this;
    } // copy assignment operator, return *this
    bool empty() const { return head == tail; }
    bool full() const { return (head + msize -1) % msize == tail; }
    int size() const { return (tail - head + msize) % msize; }
    int max_size() const { return msize-1; }
    void push(const T& item); // dodanie na koniec
    void push(T&& item); // dodanie na koniec
    T& front() { return tab[head]; } // zwraca poczatek
    T& back() { return tab[(tail + msize -1) % msize]; } // zwraca koniec
    void pop(); // usuwa poczatek
    void clear(); // czyszczenie listy z elementow
    void display();
};

template <typename T>
void MyQueue<T>::push(const T& item) {
    tab[tail] = item;
    tail = (tail + 1) % msize;
}

template <typename T>
void MyQueue<T>::push(T&& item) {
    tab[tail] = std::move(item);
    tail = (tail + 1) % msize;
}

template <typename T>
void MyQueue<T>::pop() {
    if(empty()==true)
        {
            std::cout<<"Lista jest pusta";
        }
    if(head==tail)
        {
            msize--;
        }
    head = (head + 1) % msize;
}

template <typename T>
void MyQueue<T>::clear() {
    for (int i = head; i != tail; i=(i+1) % msize) {
            pop();
        
    }
}

template <typename T>
void MyQueue<T>::display() {
    for (int i = head; i != tail; i=(i+1) % msize) {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
}

#endif