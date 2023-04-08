#include <iostream>
#include <cassert>
#include "binarytree.h"

using namespace std;

int main()
{
    RandomBinaryTree<int> tree;
    int liscie1;
    int liscie2;
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(4);
    tree.display();

    liscie1 = tree.calc_leafs_it();
    liscie2 = tree.calc_leafs_rek();

    cout << "Ilosc lisci policzona iteracyjnie: " << liscie1 << endl;
    cout << "Ilosc lisci policzona rekurencyjnie: " << liscie2 << endl;

    tree.clear();

    return 0;
}