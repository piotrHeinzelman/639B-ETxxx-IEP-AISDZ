#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*

Algorytmy i Struktury Danych, zima 2021/2022
Zadanie p0
Zwyk³¹ tablicê statyczn¹ P[n] (n -sta³a) wype³niæ wylosowanymi rekordami o znaczaj¹cymi wspó³rzêdne
ca³kowite (x, y) punktów na p³aszczyŸnie z zakresu <G, G>(G –sta³a).

  ********************
  ???
  ???  czy zakres to <-G, G> ??? (innymi s³owy -G < x < G ) ?
  ???
  *********************

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

struct Nexus {
    //Point ?
};



Point *constructor(){  //d + rand() % (g+1-d) //printf( "\nPunkt(%i,%i)" , ptr->x , ptr->y );
    Point *ptr = new Point();
          (*ptr).x = rand()%(G+G+1)-G;
            ptr->y = rand()%(G+G+1)-G;

    return ptr;
}

// unused
void toString( Point *ptr ){
   printf( "\nPunkt(%i,%i)" , (*ptr).x , ptr->y );
}

void printArray( Point *ptr[] ){
   for ( int i=0 ; i<n ; i++) {
   printf( "\nPunkt(%i,%i)" , (*ptr[i]).x , ptr[i]->y );
   }
}



int main(){

// prepare rand
    srand( time(NULL));
    int overNum=0;
    int underNum=0;


//1
    Point* P[n];

    for ( int i=0 ; i<n ; i++) {
        P[i] = constructor();
    }

    printArray( P );

    //Test
    //overNum++; printf( "\n\noverNum: %i, %i, %i, %i",overNum );

//2
    for ( int i=0 ; i<n; i++ ){
        printf("\nPoint: ( %i, %i); addr?:[0x%x], INFO(&P=%x)" , (*P[i]).x , P[i]->y , *P+i , &P[i] );
    }



  //  printArray( P );


//cout <<  rand() % (G+1) << endl;


    for ( int i=0; i<n; i++) {
        toString( constructor() );
        //cout << "constructor" << endl;
    }
    //int r = rand() % G ;
    //cout << "Losuje wektor: " << r << endl;


    //P[n];
    cout << endl << endl ; // (char)0x0a <<(char)0x0d;
    system("pause");
    return 0;
}
