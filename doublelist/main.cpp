#include <iostream>
#include <cassert>
#include "doublelist.h"

using namespace std;

int main()
{
     DoubleList<int> list;

    list.test_push_front();
    list.test_push_back();
    list.test_pop_front();
    list.test_empty();
    list.test_size();
    list.test_front();
    list.test_back();
    list.test_clear();
    list.test_display();
    list.test_display_reversed();
    list.test_pop_back();

    return 0;
}