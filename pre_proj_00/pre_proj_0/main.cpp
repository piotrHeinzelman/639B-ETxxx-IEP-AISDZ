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
const bool info=true;
const int n=9;
const int G=20;
int thisX;
int num;

struct Point {
    int x;
    int y;
};

Point *ary;



Point *constructor(){  //d + rand() % (g+1-d)
    Point *ptr = new Point();
          (*ptr).x = rand()%(G+G+1)-G;
            ptr->y = rand()%(G+G+1)-G;
                                         if (info) printf("\n Constructor :: Point *ptr = new Point(); *ptr= %i , ptr= %i" ,*ptr ,ptr );
    return ptr;
}

// unused
/*
void toString( Point *ptr ){
   printf( "\nPunkt(%  i,%  i)" , (*ptr).x , ptr->y );
}
*/
void printArray( Point* ary[] ){
   for ( int i=0 ; i<sizeof(ary) ; i++) {
        cout << endl << ary[i];
//       printf ("\n>%  1" , (*ary[i]).x);
//   printf( "\nPunkt(%i,%i)" , (*ptr[i]).x , ptr[i]->y );
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



    //Test
    //overNum++; printf( "\n\noverNum: %i, %i, %i, %i",overNum );

//2
    for ( int i=0 ; i<n; i++ ){
        printf("\n  Point: ( %+ .2d, %+ .2d )" , (*P[i]).x , P[i]->y );
                if ( info )   printf("\n scanTable: i:%i, P[i]=%i, *P[i]=%i, *P[i+1]=%i" , i, P[i], *P[i], *P[i+1] );
        if ( P[i]->x == 0 ) continue;
        if ( P[i]->x > 0 ) { overNum++; continue;}
        underNum++;
    }


    Point* overAry = new Point[overNum];
    Point* underAry = new Point[underNum];
                 if ( info )   printf("\noverAry: %x , *overAry=%x , &overAry=%x" , overAry , *overAry , &overAry);


    overNum-=overNum;
    underNum-=underNum;

    for ( int i=0 ; i<n; i++ ){
        thisX = (*P[i]).x;
        if (thisX==0) continue;
        if ( thisX>0) {
        ary = overAry;
        num = overNum;
        } else {
        ary = underAry;
        num = underNum;
        }
        ary[num]=*P[i];
    }

//    printArray( overAry );
    //printArray( underAry );


    printf("\n\n");
    //system("pause");
    return 0;
}
