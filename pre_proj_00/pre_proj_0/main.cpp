#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*

Algorytmy i Struktury Danych, zima 2021/2022
Zadanie p0
Zwyk³¹ tablicê statyczn¹ P[n] (n -sta³a) wype³niæ wylosowanymi rekordami o znaczaj¹cymi wspó³rzêdne
ca³kowite (x, y) punktów na p³aszczyŸniez zakresu <G, G>(G –sta³a).

*** zakres <-G, G> *** ???

Nastêpnie:

1. wydrukowaæ tablicê P.

2. utworzyæ dwie tablice dynamiczne zawieraj¹ce punkty le¿¹ce nad osi¹ x uk³adu wspó³rzêdnych
   oraz pod osi¹ x uk³adu (a wiêc nie le¿¹ce na osiach uk³adu).

3. wydrukowaæ tak utworzone tablice.

Wskazówki:
1. liczby ca³kowite z zakresu <d, g>, gdzie d i g s¹ liczbami ca³kowitymi,
   losujemy jako d + rand() % (g+1-d).

2. przed utworzeniem tablic dynamicznych i wpisaniem do nich rekordów z tablicy P trzeba najpierw policzyæ,
   ile tych rekordów  bêdzie w ka¿dej tabli

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
