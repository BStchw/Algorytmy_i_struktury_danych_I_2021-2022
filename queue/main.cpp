#include <iostream>
#include <cassert>
#include <stdio.h>
#include "myqueue.h"

using namespace std;
int main ()
{
    MyQueue<int> queue1;
    cout << "Push: " << endl;
    queue1.push(14);
    queue1.push(12);
    queue1.push(18);
    queue1.push(5);
    queue1.display();

    cout << "Pop: " << endl;
    queue1.pop();
    queue1.display();

    cout << "Copy constructor: " << endl;
    MyQueue<int> queue2(queue1);
    queue2.display();

    cout << "Front: " << endl;
    cout << queue1.front() << endl;

    cout << "Back: " << endl;
    cout << queue1.back() << endl;

    cout << "Size: " << endl;
    cout << queue1.size() << endl;

    cout << "Max size: " << endl;
    cout << queue1.max_size() << endl;

    cout << "Clear: " << endl;
    queue1.clear();
    queue1.display();


    return 0;
}