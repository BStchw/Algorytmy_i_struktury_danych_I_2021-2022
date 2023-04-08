#include<iostream>
#include "funkcje.hpp"
using namespace std;
 
void scalanie(int tablica[], int start, int srodek, int koniec)
{
int *tab_pom = new int[(koniec-start)];
int i = start, j = srodek+1, k = 0;
 
while (i <= srodek && j <= koniec)
{
if (tablica[j] < tablica[i])
{
tab_pom[k] = tablica[j];
j++;
}
else
{
tab_pom[k] = tablica[i];
i++;
}
k++;
}
 
if (i <= srodek)
{
while (i <= srodek)
{
tab_pom[k] = tablica[i];
i++;
k++;
}
}
else
{
while (j <= koniec)
{
tab_pom[k] = tablica[j];
j++;
k++;
}
}
 
for (i = 0; i <= koniec-start; i++)
tablica[start+i] = tab_pom[i]; 
 
}
 
void sortowanie_przez_scalanie(int tablica[], int start, int koniec)
{
int srodek;
 
if (start != koniec)
{
srodek = (start + koniec)/2;
sortowanie_przez_scalanie(tablica, start, srodek);
sortowanie_przez_scalanie(tablica, srodek+1, koniec);
scalanie(tablica, start, srodek, koniec);
}
}