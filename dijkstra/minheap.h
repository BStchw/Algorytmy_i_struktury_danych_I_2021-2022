#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include <cassert>
#include <vector>
#include <cctype>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "dijkstra.h"

// minheap
struct MinHeapNode
{
    int  v;
    int dist;

    MinHeapNode(int v, int dist)
    {
        this->v = v;
        this->dist = dist;
    }
};


class MinHeap
{
    // pojemnosc kopca
    int capacity;
    public:
    // ile galezi
    int size;
    //indeks elementu
    int* pos;
    struct MinHeapNode** array;

    MinHeap(int capacity)   //konstruktor
    {
        this->pos = new int [capacity];
        this->size = 0;
        this->capacity = capacity;
        this->array = new struct MinHeapNode *[capacity];
    }
    void minHeapify(int idx);
    bool isEmpty();
    struct MinHeapNode* extractMin();
    void decreaseKey(int v, int dist);
    bool isInMinHeap(int v);

};


// swap
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// funkcja potrzebna do prawidlowego ustalenia struktury kopca, sortuje elementy
void MinHeap::minHeapify(int idx)
{
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if (left < size && array[left]->dist < array[smallest]->dist)
        smallest = left;

    if (right < size && array[right]->dist < array[smallest]->dist)
        smallest = right;

    if (smallest != idx)
    {
        
        MinHeapNode* smallestNode = array[smallest];
        MinHeapNode* idxNode = array[idx];

        
        pos[smallestNode->v] = idx;
        pos[idxNode->v] = smallest;

        
        swapMinHeapNode(&array[smallest], &array[idx]);

        minHeapify(smallest);
    }
}

// czy minheap jest pusty
bool MinHeap::isEmpty()
{
    return size == 0;
}

// najmniejszy element z kopca
struct MinHeapNode* MinHeap::extractMin()
{
    if (isEmpty())
        std::cout<<"MinHeap jest pusty \n";

    
    struct MinHeapNode* root = array[0];

    
    struct MinHeapNode* lastNode = array[size - 1];
    array[0] = lastNode;

    
    pos[root->v] = size - 1;
    pos[lastNode->v] = 0;

    
    size--;
    minHeapify(0);

    return root;
}

// funkcja ktora updatuje dystans miedzy wierzcholkami
void MinHeap::decreaseKey(int v, int dist)
{
    // indeks wierzcholka
    int i = pos[v];

    // pobiera wezel i go updatuje
    array[i]->dist = dist;

    while (i && array[i]->dist < array[(i - 1) / 2]->dist)
    {
        //zamiana wezla z rodzicem
        pos[array[i]->v] = (i - 1) / 2;
        pos[array[(i - 1) / 2]->v] = i;
        swapMinHeapNode(&array[i],&array[(i - 1) / 2]);

        // przeniesienie na indeks rodzica
        i = (i - 1) / 2;
    }
}

// funkcja sprawdzajaca czy wierzcholek jest w kopcu
bool MinHeap::isInMinHeap(int v)
{
    if (pos[v] < size)
        return true;
    return false;
}

#endif