#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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

    cout << "Tablica punkt�w powy�ej osi: (" << overNum <<")\n";
    for ( int i=0; i<overNum;i++){
        cout << endl << "i: " << i << " x: "<<overAry[i].x << ", y: " << overAry[i].y ;
    }

    cout << "\n\n\nTablica punkt�w poni�ej osi: (" << underNum <<")\n";
    for ( int i=0; i<underNum;i++){
        cout << endl << "i: " << i << " x: "<<underAry[i].x << ", y: " << underAry[i].y ;
    }


    delete[] overAry;
    delete[] underAry;

    printf("\n\n");
    //system("pause");
    return 0;
}
