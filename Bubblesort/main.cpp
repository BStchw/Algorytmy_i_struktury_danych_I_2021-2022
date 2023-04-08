#include<iostream>

using namespace std;
int main ()
{
	int i, j;
	int tab[10];
	cout <<"Podaj 10 liczb do posortowania."<< endl;

	for(i = 0; i<10; i++) {
	cout <<"Liczba numer "<<i+1<<": ";
	cin >>tab[i];
	}
	int n;

	for(i = 0; i<10; i++) {
		for(j = i+1; j<10; j++)
		{
			if(tab[j] < tab[i]) {
				n = tab[i];
				tab[i] = tab[j];
				tab[j] = n;
			}
		}
	}
cout <<endl<<"Posortowane liczby: \n";
for(i = 0; i<10; i++) {
   cout <<tab[i]<<"    ";
}
return 0;
}