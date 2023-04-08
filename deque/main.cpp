#include <iostream>
#include <cassert>
#include <stdio.h>
#include "mydeque.h"

using namespace std;
int main ()
{
    MyDeque<int> deque1;

    cout << "Push_front: " << endl;
    deque1.push_front(14);
    deque1.push_front(12);
    deque1.display();

    cout << "Push_back: " << endl;
    deque1.push_back(18);
    deque1.push_back(27);
    deque1.display();

    cout << "Pop_front: " << endl;
    deque1.pop_front();
    deque1.display();

    cout << "Pop_back: " << endl;
    deque1.pop_back();
    deque1.display();

    cout << "Copy constructor: " << endl;
    MyDeque<int> deque2(deque1);
    deque2.display();

    cout << "Clear: " << endl;
    deque1.clear();
    deque1.display();

    return 0;
}