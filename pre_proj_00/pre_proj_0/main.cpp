#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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
int underNum=0;
int overNum=0;



int getRand(){
    return rand()%(G+G+1)-G;
}

struct Point{
    int x, y;
};




int main(){

// prepare rand
    srand( time(NULL));

    Point P[n];
    cout << endl << "       Tablica P[" << n << "]\n";

    for ( int i=0; i<n ; i++) {
        P[i].x=getRand();
        P[i].y=getRand();
        printf("\n   :   %  .2i  ,   %  .2i   :",P[i].x, P[i].y );
    }
    cout << endl << endl << endl << endl ;

    for ( int i=0; i<n; i++ ){
        if ( P[i].x==0) continue;
        if ( P[i].x>0 ) { overNum++; continue; }
        underNum++;
    }

    Point*  overAry = new Point[overNum];
    Point* underAry = new Point[underNum];

    overNum-=overNum;
    underNum-=underNum;

    for ( int i=0; i<n; i++){
        if ( P[i].x==0) continue;
        if ( P[i].x>0 ) { overAry[overNum]=P[i]; overNum++; continue; }
        underAry[underNum]=P[i];
        underNum++;
    }

    cout << "Tablica punktów powy¿ej osi: (" << overNum <<")\n";
    for ( int i=0; i<overNum;i++){
        cout << endl << "i: " << i << " x: "<<overAry[i].x << ", y: " << overAry[i].y ;
    }

    cout << "\n\n\nTablica punktów poni¿ej osi: (" << underNum <<")\n";
    for ( int i=0; i<underNum;i++){
        cout << endl << "i: " << i << " x: "<<underAry[i].x << ", y: " << underAry[i].y ;
    }


    delete[] overAry;
    delete[] underAry;

    printf("\n\n");
    //system("pause");
    return 0;
}
