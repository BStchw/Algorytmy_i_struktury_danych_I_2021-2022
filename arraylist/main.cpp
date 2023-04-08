#include <iostream>
#include <cassert>
#include <stdio.h>
#include "arraylist.hpp"

using namespace std;
int main ()
{
    ArrayList<int> list;

    cout << "Test push_front" << endl;
    list.push_front(9);
    list.push_front(25);
    list.push_front(67);
    list.display();
    cout << "Test push_back" << endl;
    list.push_back(6);
    list.push_back(32);
    list.push_back(78);
    list.display();
    cout << "Test reverse" << endl;
    list.reverse();
    list.display();
    cout << "Test empty" << endl;
    list.empty();
    cout << "Test full" << endl;
    list.full();
    cout << "Test size" << endl;
    list.size();
    cout << "Test max_size" << endl;
    list.max_size();
    cout << "Test front" << endl;
    list.front();
    cout << "Test back" << endl;
    list.back();
    cout << "Test pop_front" << endl;
    list.pop_front();
    list.display();
    cout << "Test reverse" << endl;
    list.reverse();
    list.display();
    cout << "Test pop_back" << endl;
    list.pop_back();
    list.display();
    cout << "Test mergesort" << endl;
    list.sortowanie_przez_scalanie(0, 3);
    list.display();
    cout << "Test copy constructor" << endl;
    ArrayList<int> list2(list);
    list2.display();
    cout << "Test clear" << endl;
    list.clear();
    list.display();

    return 0;
}