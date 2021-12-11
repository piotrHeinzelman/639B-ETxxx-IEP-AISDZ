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
