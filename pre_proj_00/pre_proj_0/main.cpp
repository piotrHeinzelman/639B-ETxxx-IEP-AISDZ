#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*

Algorytmy i Struktury Danych, zima 2021/2022
Zadanie p0
Zwyk�� tablic� statyczn� P[n] (n -sta�a) wype�ni� wylosowanymi rekordami o znaczaj�cymi wsp�rz�dne
ca�kowite (x, y) punkt�w na p�aszczy�niez zakresu <G, G>(G �sta�a).

*** zakres <-G, G> *** ???

Nast�pnie:

1. wydrukowa� tablic� P.

2. utworzy� dwie tablice dynamiczne zawieraj�ce punkty le��ce nad osi� x uk�adu wsp�rz�dnych
   oraz pod osi� x uk�adu (a wi�c nie le��ce na osiach uk�adu).

3. wydrukowa� tak utworzone tablice.

Wskaz�wki:
1. liczby ca�kowite z zakresu <d, g>, gdzie d i g s� liczbami ca�kowitymi,
   losujemy jako d + rand() % (g+1-d).

2. przed utworzeniem tablic dynamicznych i wpisaniem do nich rekord�w z tablicy P trzeba najpierw policzy�,
   ile tych rekord�w  b�dzie w ka�dej tabli

*/

const int n=9;
const int G=20;

struct Point {
    int x;
    int y;
};


Point *constructor(){  //d + rand() % (g+1-d)
    Point *ptr = new Point();
          (*ptr).x = rand()%(G+1);
            ptr->y = rand()%(G+1);
            //printf( "\nPunkt(%i,%i)" , ptr->x , ptr->y );
    return ptr;
}

// unused
void toString( Point *ptr ){
   //printf( "\nPunkt(%i,%i)" , (*ptr).x , ptr->y );
}

void printArray( Point *ptr[] ){
   for ( int i=0 ; i<n ; i++) {
    //    printf("?");
   printf( "\nPunkt(%i,%i)" , (*ptr[i]).x , ptr[i]->y );
   }
}



int main(){

// prepare rand
    srand( time(NULL));

//1
    Point* P[n];

    for ( int i=0 ; i<n ; i++) {
        P[i] = constructor();
    }

    printArray( P );

  //  printArray( P );


//cout <<  rand() % (G+1) << endl;


    for ( int i=0; i<n; i++) {
        toString( constructor() );
        //cout << "constructor" << endl;
    }
    //int r = rand() % G ;
    //cout << "Losuje wektor: " << r << endl;


    //P[n];
    cout << endl << endl;
    system("pause");
    return 0;
}
