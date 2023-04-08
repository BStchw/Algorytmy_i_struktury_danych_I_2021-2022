#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <iostream>
#include <cassert>
#include <vector>
#include <cctype>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graph.h"
#include "minheap.h"

// wynik
void printArr(int dist[], int n)
{
    printf("\nWierzchołek   Dystans\n");
    for (int i = 0; i < n; ++i)
    printf("%d \t\t %d\n", i, dist[i]);
}

int *dijkstra(struct Graph* graph, int src, int wyniki[])
{
    // pobranie liczby wierzcholkow
    int N = graph->V;

    // tabela przechowujaca dystans
    int *dist = new int[N];

    // kopiec
    struct MinHeap *minHeap = new MinHeap(N);

    // zainicjalizowanie kopca maksymalnymi wartosciami inta(nieskonczonoscia w teorii)
    for (int v = 0; v < N; ++v)
    {
        dist[v] = INT_MAX;
        minHeap->array[v] = new MinHeapNode(v, dist[v]);
        minHeap->pos[v] = v;
    }

    // inicjalizacja wartosci pierwszego wierzcholka na 0
    minHeap->array[src] = new MinHeapNode(src, dist[src]);
    minHeap->pos[src] = src;
    dist[src] = 0;
    minHeap->decreaseKey(src, dist[src]);

    minHeap->size = N;

    // petla liczaca najkrotszy dystans
    while (!minHeap->isEmpty())
    {
        // wierzcholek z najmniejszym dystansem
        struct MinHeapNode* minHeapNode = minHeap->extractMin();

        // przechowanie jego indeksu
        int u = minHeapNode->v;

        // przejscie przez wszystkie sasiednie wierzcholki i policzenie dystansu
        struct AdjListNode* pCrawl = graph->array[u].head;
        while (pCrawl != NULL)
        {
            int v = pCrawl->dest;

            // jesli wyliczony dystans jest mniejszy
            if (minHeap->isInMinHeap(v) && dist[u] != INT_MAX && pCrawl->weight + dist[u] < dist[v])
            {
                dist[v] = dist[u] + pCrawl->weight;
                // aktualizacja wartosci i dystansu
                minHeap->decreaseKey(v, dist[v]);
            }
            pCrawl = pCrawl->next;
        }
    }

    for(int i=0; i<N; i++) 
    {
        wyniki[i] = dist[i];
    }

    return wyniki;
}


#endif