// doublelist.h

#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>     // deklaracje strumieni cout, cin, cerr
#include <cassert>    // assert()

template <typename T>
struct DoubleNode {
// the default access mode and default inheritance mode are public
    T value;
    DoubleNode *next, *prev;
    // konstruktor domyslny (niepotrzebny)
    DoubleNode() : value(T()), next(nullptr), prev(nullptr) {}
    DoubleNode(const T& item, DoubleNode *nptr=nullptr, DoubleNode *pptr=nullptr)
        : value(item), next(nptr), prev(pptr) {} // konstruktor
    ~DoubleNode() {} // destruktor
};


template <typename T>
class DoubleList {
    DoubleNode<T> *head, *tail;
public:
    DoubleList() : head(nullptr), tail(nullptr) {}
    ~DoubleList(); // tu trzeba wyczyscic wezly
    DoubleList(const DoubleList& other) {
        DoubleNode<T> *tmp = other.head;
        head = tail = nullptr;

        while (tmp != nullptr)
        {
            push_back(tmp->value);
            tmp = tmp->next;
        }
    } // copy constructor
    // usage:   DoubleList<int> list2(list1);
    DoubleList& operator=(const DoubleList& other) {
        if(*this != other) {
            other.clear();
            DoubleNode<T> *tmp = other.head;
            while (tmp != nullptr)
            {
                push_back(tmp->value);
                tmp = tmp->next;
            }
        }
        return *this;
    } // copy assignment operator, return *this
    // usage:   list2 = list1;
    bool empty() const { return head == nullptr; }
    int size() const {
    DoubleNode<T> *node = head;
    int i=0;
    while (node != nullptr){
        i++;
        node = node->next;
    }
    return i;
    } // O(n) bo trzeba policzyc
    void push_front(const T& item); // O(1)
    void push_back(const T& item); // O(1)
    T& front() const { return head->value; } // zwraca poczatek, nie usuwa
    T& back() const { return tail->value; } // zwraca koniec, nie usuwa
    void pop_front(); // usuwa poczatek O(1)
    void pop_back(); // usuwa koniec O(n)
    void clear(); // czyszczenie listy z elementow O(n)
    void display(); // O(n)
    void display_reversed(); // O(n)
    void test_push_front();
    void test_push_back();
    void test_pop_front();
    void test_pop_back();
    void test_empty();
    void test_size();
    void test_front();
    void test_back();
    void test_clear();
    void test_display();
    void test_display_reversed();
};

template <typename T>
DoubleList<T>::~DoubleList() {

    for (DoubleNode<T> *node; !empty(); ) {
        node = head->next;
        delete head;
        head = node;
    }

}

template <typename T>
void DoubleList<T>::push_front(const T& item) {
    if (!empty()) {
        head = new DoubleNode<T>(item, head);
        head->next->prev = head;
    } else {
        head = tail = new DoubleNode<T>(item);
    }

}

template <typename T>
void DoubleList<T>::push_back(const T& item) {
    DoubleNode<T> *node = tail;
    if (!empty()) {
        tail->next = new DoubleNode<T>(item, tail);
        tail = tail->next;
        tail->prev = node;
        tail->next = nullptr;
    }
    else
    {
        head = new DoubleNode<T>(item);
        tail = head;
    }
}

template <typename T>
void DoubleList<T>::pop_front() {
    DoubleNode<T> *tmp = head;
    if (head == tail) {
        head = tail = nullptr;
    }
    else {
        head = head->next;
        head->prev = nullptr;
    }
    delete tmp;
}

template <typename T>
void DoubleList<T>::pop_back() {
    DoubleNode<T> *tmp = tail;
    assert(!empty());
    if(head == tail) {
        head = tail = nullptr;
    }
    else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete tmp;
}

template <typename T>
void DoubleList<T>::test_size()
{
    int tab[6]={2, 4, 23, 65, 15, 24};

    for(int i=0; i<6; i++) {
        push_front(tab[i]);
    }
    assert(size()==6);
    std::cout<<"Test metody: size()"<<std::endl;
    display();
    clear();
}

template <typename T>
void DoubleList<T>::test_empty()
{
    assert(empty()==true);
    std::cout<<"Test metody: empty()"<<std::endl;
}

template <typename T>
void DoubleList<T>::test_front()
{
    T tab[6]={2, 4, 23, 65, 15, 24};

    for(int i=0; i<6; i++) {
        push_front(tab[i]);
        assert(head->value == tab[i]);
    }
    assert(front()==tab[5]);
    
    std::cout<<"Test metody: front()"<<std::endl;
    display();
    clear();
}

template <typename T>
void DoubleList<T>::test_back()
{
    T tab[6]={2, 4, 23, 65, 15, 24};

    for(int i=0; i<6; i++) {
        push_front(tab[i]);
        assert(head->value == tab[i]);
    }
    assert(back()==tab[0]);
    
    std::cout<<"Test metody: back()"<<std::endl;
    display();
    clear();
}

template <typename T>
void DoubleList<T>::clear() {
    DoubleNode<T> *tmp = head;
    while (tmp != nullptr)
    {
        head = tmp;
        tmp = tmp->next;
        delete head;
    }
    head = tail = nullptr;
}

template <typename T>
void DoubleList<T>::display() {
    DoubleNode<T> *tmp = head;
    while (tmp != nullptr){
        std::cout << tmp->value << " ";
        tmp = tmp->next;
    }
    std::cout << std::endl;
}

template <typename T>
void DoubleList<T>::display_reversed() {
  DoubleNode<T> *tmp = tail;
    while (tmp != nullptr){
        std::cout << tmp->value << " ";
        tmp = tmp->prev;
        if (tmp==tail) {
            break;
        }
    }
    std::cout << std::endl;
}

template <typename T>
void DoubleList<T>::test_push_front()
{
    T tab[6]={2, 4, 23, 65, 15, 24};

    for(int i=0; i<6; i++) {
        push_front(tab[i]);
        assert(head->value == tab[i]);
        
        
    }
    std::cout<<"Test metody: push_front()"<<std::endl;
    display();
    clear();
}

template <typename T>
void DoubleList<T>::test_push_back()
{
    T tab[6]={2, 4, 23, 65, 15, 24};

    for(int i=0; i<6; i++) {
        push_back(tab[i]);
        assert(tail->value == tab[i]);
        
        
    }
    std::cout<<"Test metody: push_back()"<<std::endl;
    display();
    clear();
}

template <typename T>
void DoubleList<T>::test_pop_front()
{
    T tab[6]={2, 4, 23, 65, 15, 24};

    for(int i=0; i<6; i++) {
        push_back(tab[i]);
    }
    pop_front();
    assert(head->value == tab[1]);
    std::cout<<"Test metody: pop_front()"<<std::endl;
    display();
    clear();
}

template <typename T>
void DoubleList<T>::test_pop_back()
{
    T tab[6]={2, 4, 23, 65, 15, 24};

    for(int i=0; i<6; i++) {
        push_back(tab[i]);
    }
    pop_back();
    display();
    assert(tail->value == tab[4]);
    std::cout<<"Test metody: pop_back()"<<std::endl;
    display();
    clear();
}

template <typename T>
void DoubleList<T>::test_clear()
{
    T tab[6]={2, 4, 23, 65, 15, 24};

    for(int i=0; i<6; i++) {
        push_front(tab[i]);
        assert(head->value == tab[i]); 
    }
    clear();
    assert(head==nullptr);
    assert(tail==nullptr);

    std::cout<<"Test metody: clear()"<<std::endl;
    display();
}

template <typename T>
void DoubleList<T>::test_display()
{
    T tab[6]={2, 4, 23, 65, 15, 24};

    for(int i=0; i<6; i++) {
        push_front(tab[i]);
    }
    std::cout<<"Test metody: display()"<<std::endl;
    display();
    clear();
}

template <typename T>
void DoubleList<T>::test_display_reversed()
{
    T tab[6]={2, 4, 23, 65, 15, 24};

    for(int i=0; i<6; i++) {
        push_front(tab[i]);
    }
    std::cout<<"Test metody: display_reverse()"<<std::endl;
    display_reversed();
    clear();
}

#endif

// EOF