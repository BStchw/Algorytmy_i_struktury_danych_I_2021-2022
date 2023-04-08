// singlelist.h

#ifndef SINGLELIST_H
#define SINGLELIST_H

#include <iostream>     // deklaracje strumieni cout, cin, cerr
#include <cassert>    // assert()

template <typename T>
struct SingleNode {
// the default access mode and default inheritance mode are public
    T value;
    SingleNode *next;
    SingleNode() : value(T()), next(nullptr) {} // konstruktor domyslny
    SingleNode(const T& item, SingleNode *ptr=nullptr) : value(item), next(ptr) {}
    ~SingleNode() {} // destruktor
};

template <typename T>
class SingleList {
    SingleNode<T> *head, *tail;
public:
    SingleList() : head(nullptr), tail(nullptr) {}
    ~SingleList(); // tu trzeba wyczyscic wezly
    SingleList(const SingleList& other);// copy constructor
    // usage:   SingleList<int> list2(list1);
    SingleList& operator=(const SingleList& other) {
        if (head != other.head && tail != other.tail) {
            SingleList<T> lista(other);
            std::swap(lista.head, head);
            std::swap(lista.tail, tail);
            return *this;
        }
        else {
            return *this;
        }
    } // copy assignment operator, return *this
    // usage:   list2 = list1;
    bool empty() const { return head == nullptr; }
    int size(); // O(n) bo trzeba policzyc
    void push_front(const T& item); // O(1), L.push_front(item)
    void push_back(const T& item); // O(1), L.push_back(item)
    T& front() const { return head->value; } // zwraca poczatek, nie usuwa
    T& back() const { return tail->value; } // zwraca koniec, nie usuwa
    void pop_front(); // usuwa poczatek O(1)
    void pop_back(); // usuwa koniec O(n)
    void clear(); // czyszczenie listy z elementow O(n)
    void display(); // O(n)
    void reverse(); // O(n)
    void test_push_front();
    void test_push_back();
    void test_pop_front();
    void test_pop_back();
    void test_empty();
    void test_size();
    void test_front();
    void test_back();
    void test_clear();
    void test_reverse();
};

template <typename T>
SingleList<T>::~SingleList() {
    // I sposob.
    for (SingleNode<T> *node; !empty(); ) {
        node = head->next; // zapamietujemy
        delete head;
        head = node; // kopiowanie wskaznika
    }
    // II sposob.
    // while (!empty()) { pop_front(); }
}

template <typename T>
SingleList<T>::SingleList(const SingleList& other) : head(nullptr), tail(nullptr){
        SingleNode<T>* node = other.head;
        while (node != nullptr) {
            push_back(node->value);
            node = node->next;
        }
    }

template <typename T>
void SingleList<T>::push_front(const T& item) {
    if (!empty()) {
        head = new SingleNode<T>(item, head);
    } else {
        head = tail = new SingleNode<T>(item);
    }
}

template <typename T>
void SingleList<T>::push_back(const T& item) {
    if (!empty()) {
        tail->next = new SingleNode<T>(item);
        tail = tail->next;
    } else {
        head = tail = new SingleNode<T>(item);
    }
}

template <typename T>
void SingleList<T>::display() {
    SingleNode<T> *node = head;
    while (node != nullptr){
        std::cout << node->value << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

template <typename T>
void SingleList<T>::pop_front() {
    assert(!empty());
    SingleNode<T> *node = head; // zapamietujemy
    if (head == tail) { // jeden wezel na liscie
        head = tail = nullptr;
    } else { // wiecej niz jeden wezel na liscie
        head = head->next;
    }
    delete node;
}

template <typename T>
void SingleList<T>::pop_back() {
    assert(!empty());
    SingleNode<T> *node = tail; // zapamietujemy
    if (head == tail) { // jeden wezel na liscie
        head = tail = nullptr;
    } else { // wiecej niz jeden wezel na liscie
        // Szukamy poprzednika ogona.
        SingleNode<T> *before=head;
        while (before->next != tail) {
            before = before->next;
        }
        tail = before;
        tail->next = nullptr;
    }
    delete node;
}

template <typename T>
void SingleList<T>::clear() {

    SingleNode<T>* temp = head;
    while (temp != tail) {
        head = temp->next;
        delete temp;
        temp = head;
    }
    delete tail;
	
    head = nullptr;
    tail = nullptr;
}
    

template <typename T>
void SingleList<T>::reverse() {
    SingleNode<T> *node = head;
    SingleNode<T> *before = NULL, *next = NULL;
    if (head == tail) { 
        std::cout << "Lista ma jeden element" << std::endl;
    }
    else{
        while (node != NULL) {
            next = node->next;
            node->next = before;
            before = node;
            node=next;
        }
        head = before;
    }
}

template <typename T>
int SingleList<T>::size() {
    SingleNode<T> *node = head;
    int i=0;
    while (node != nullptr){
        i++;
        node = node->next;
    }
    std::cout << "Liczba elementow listy: " << i <<std::endl;
    return i;
}

template <typename T>
void SingleList<T>::test_push_front()
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
void SingleList<T>::test_push_back()
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
void SingleList<T>::test_pop_front()
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
void SingleList<T>::test_pop_back()
{
    T tab[6]={2, 4, 23, 65, 15, 24};

    for(int i=0; i<6; i++) {
        push_back(tab[i]);
    }
    pop_back();
    assert(tail->value == tab[4]);
    std::cout<<"Test metody: pop_back()"<<std::endl;
    display();
    clear();
}


template <typename T>
void SingleList<T>::test_size()
{
    T tab[6]={2, 4, 23, 65, 15, 24};

    for(int i=0; i<6; i++) {
        push_front(tab[i]);
    }
    assert(size()==6);
    std::cout<<"Test metody: size()"<<std::endl;
    display();
    clear();
}

template <typename T>
void SingleList<T>::test_empty()
{
    assert(empty()==true);
    std::cout<<"Test metody: empty()"<<std::endl;
}

template <typename T>
void SingleList<T>::test_front()
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
void SingleList<T>::test_back()
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
void SingleList<T>::test_clear()
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
void SingleList<T>::test_reverse()
{
    T tab[6]={2, 4, 23, 65, 15, 24};

    for(int i=0; i<6; i++) {
        push_front(tab[i]);
    }
    reverse();
    assert(head->value==2);

    std::cout<<"Test metody: reverse()"<<std::endl;
    display();
    clear();
}

void test_copy_constructor()
{
    SingleList<int> list1;
    int tab[6]={2, 4, 23, 65, 15, 24};

    for(int i=0; i<6; i++) {
        list1.push_front(tab[i]);
    }

    SingleList<int> list2(list1);
    std::cout<<"Test copy constructor"<<std::endl;
    std::cout<<"Test copy constructor"<<std::endl;
    list1.display();
    std::cout<<"Test copy constructor"<<std::endl;
    list2.display();
    list1.clear();
    list2.clear();
}


#endif