#include <iostream>
#include <cassert>
#include "singlelist.h"

using namespace std;

int main()
{
     SingleList<int> list;

    list.test_push_front();
    list.test_push_back();
    list.test_pop_front();
    list.test_pop_back();
    list.test_empty();
    list.test_size();
    list.test_front();
    list.test_back();
    list.test_clear();
    list.test_reverse();
    test_copy_constructor();
    
    return 0;
}