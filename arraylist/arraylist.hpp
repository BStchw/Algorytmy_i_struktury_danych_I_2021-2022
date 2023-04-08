// arraylist.h

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>     // deklaracje strumieni cout, cin, cerr
#include <cassert>    // assert()
#include <stdio.h>
#include <algorithm>
#include <cstdlib>

template <typename T>
class ArrayList {
    T* tab;
    int msize; // najwieksza mozliwa liczba elementow
    int last; // pierwsza wolna pozycja
public:
    ArrayList(int s=10) : msize(s), last(0) {
        tab = new T[s];
        assert( tab != nullptr );
    } // default constructor
    ~ArrayList() { delete [] tab; }
    ArrayList(const ArrayList& other) {
        msize = other.max_size();
        last = other.size();
        tab = new T[msize];

        for(int i = 0; i < last; i++)
        {
            tab[i] = other.tab[i];
        }
    } // copy constructor
    // usage:   ArrayList<int> list2(list1);
    ArrayList& operator=(const ArrayList& other) {
        if (*this != other)
        {
            msize = other.max_size();
            last = other.size();
            tab = new T[msize];
        
            for(int i = 0; i < last; i++)
            {
                tab[i] = other.tab[i];
            }
        }
        return *this;
    }
    bool empty() const { return last == 0; } // checks if the container has no elements
    bool full() const { return last == msize; } // checks if the container is full
    int size() const { return last; } // liczba elementow na liscie
    int max_size() const { return msize; } // najwieksza mozliwa liczba elementow
    T& front() const {return tab[0]; } // zwraca poczatek, nie usuwa, error dla pustej listy
    T& back() const {return tab[msize-1]; }
    void push_front(const T& item)
    {
        if(last == msize)
        {
            std::cout<<"Lista jest pełna";
        }
        else
        {
            for(int i=last+1; i>0; i--)
            {
                tab[i]=tab[i-1];
            }
            tab[0] = item;
            last++;
        }
    } // dodanie na poczatek
    void push_back(const T& item)
    {
        if(last == msize)
        {
            std::cout<<"Lista jest pełna";
        }
        else
        {
            tab[last] = item;
            last++;
        }
    }  // dodanie na koniec
    void pop_front()
    {
        if(empty()==true)
        {
            std::cout<<"Lista jest pusta";
        }
        for(int i=0; i<last+1; i++)
            {
                tab[i]=tab[i+1];
            }
            last--;
    } // usuwa poczatek, error dla pustej listy
    void pop_back(){ // usuwa koniec, error dla pustej listy
        if(empty()==true)
        {
            std::cout<<"Lista jest pusta";
        }
        else
        {
            last--;
        }
    }
    void clear()
    {
       for(int i=last; i>0; i--)
        {
            pop_front();

        }
    } // czyszczenie listy z elementow
    void display()
    {
        for(int i=0; i<last; i++)
        {
            std::cout<<tab[i] << " ";
        }
        std::cout<<" "<<std::endl;
    } // lepiej zdefiniowac operator<<
    void reverse()
    {
    for (int low = 0, high = last - 1; low < high; low++, high--) {
        std::swap(tab[low], tab[high]);
    }
    } // odwracanie kolejnosci

    void sortowanie_przez_scalanie(int start, int koniec)
    {
        int srodek;
 
        if (start != koniec)
        {
            srodek = (start + koniec)/2;
            sortowanie_przez_scalanie(start, srodek);
            sortowanie_przez_scalanie(srodek+1, koniec);
            scalanie(start, srodek, koniec); 
        }
    }
     // sortowanie listy
    
    void scalanie(int start, int srodek, int koniec)
    {
        int *tab_pom = new int[(koniec-start)];
        int i = start, j = srodek+1, k = 0;
 
        while (i <= srodek && j <= koniec)
        {
            if (tab[j] < tab[i])
            {
                tab_pom[k] = tab[j];
                j++;
            }
            else
            {
                tab_pom[k] = tab[i];
                i++;
            }
            k++;
        }
 
        if (i <= srodek)
        {
            while (i <= srodek)
            {
                tab_pom[k] = tab[i];
                i++;
                k++;
            }
        }
        else
        {
            while (j <= koniec)
            {
            tab_pom[k] = tab[j];
            j++;
            k++;
            }
        }
 
        for (i = 0; i <= koniec-start; i++)
        {
            tab[start+i] = tab_pom[i];
        }
 
    }

};

#endif

// EOF