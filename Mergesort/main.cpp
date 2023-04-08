#include<iostream>
#include "funkcje.hpp"
using namespace std;


int main()
{
int i;

 
int *tablica = new int [10];
 
for (i = 0; i < 10; i++)
{
cout << "Liczba " <<i+1<<": ";
cin >> tablica[i];
}
 
sortowanie_przez_scalanie(tablica, 0, 9);
 
cout << endl << "Posortowane liczby:" << endl;
for (i = 0; i < 10; i++)
cout << "    " << tablica[i];
 
delete [] tablica;
 
return 0;
}