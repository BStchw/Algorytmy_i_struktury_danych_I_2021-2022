#include <iostream>
#include <cassert>
#include <stdio.h>
#include "mypriorityqueue.h"

using namespace std;
int main ()
{
    MyPriorityQueue<int> queue1;
    cout << "Push: " << endl;
    queue1.push(14);
    queue1.push(12);
    queue1.push(18);
    queue1.push(5);
    queue1.display();
    
    cout << endl << "Pop: " << endl;
    queue1.pop();
    queue1.display();
    
    cout << endl << "Top: " << endl;
    cout << queue1.top() << endl;

    cout << "Size: " << endl;
    cout << queue1.size() << endl;

    cout << "Copy constructor: " << endl;
    MyPriorityQueue<int> queue2(queue1);
    queue2.display();

    cout << endl << "Clear: " << endl;
    queue1.clear();
    queue1.display();

    return 0;
}