#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*

Algorytmy i Struktury Danych, zima 2021/2022
Zadanie p0
Zwyk�� tablic� statyczn� P[n] (n -sta�a) wype�ni� wylosowanymi rekordami o znaczaj�cymi wsp�rz�dne
ca�kowite (x, y) punkt�w na p�aszczy�nie z zakresu <G, G>(G �sta�a).

  ********************
  ???
  ???  czy zakres to <-G, G> ??? (innymi s�owy -G < x < G ) ?
  ???
  *********************

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
