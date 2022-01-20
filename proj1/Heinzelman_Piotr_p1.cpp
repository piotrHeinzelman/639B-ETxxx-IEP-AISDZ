#include <iostream>
#include <stdlib.h>
#include <time.h>



using namespace std;


/*

Zadanie p1

1. Losowac rekordy  opisujace wspólrzedne calkowite  (x, y) punktów
   z zakresu od -G do G  (G - stala) az do momentu wylosowania dowolnego punktu lezacego na osi x
   i utworzyc z nich (wlacznie z tym ostatnim) liste jednokierunkowa.

2. Wydrukowac dane rekordów na liscie korzystajac z funkcji drukujacej liste zaczynajaca sie
   pod jakims adresem, poprzedzajac wydruk jakims naglowkiem.

3. Jesli na liscie jest mniej niz N punktów (N – stala),  dopisac jako dwa pierwsze elementy
   dodatkowo wczytane  z klawiatury dane tych dwóch punktów.

4. Ponownie wydrukowac liste.

5. Wydrukowac wspólrzedne ostatniego punktu na liscie.

6. Skasowac z pamieci  utworzona liste.

Uwaga 1: slowo "jakies" oznacza parametr funkcji.
Uwaga 2:  Nie nalezy uzywaz innych funkcji niz podana w tresci zadania funkcja drukujaca.
Uwaga 3:  Wykonujac rózne dzialania na liscie nalezy zalozyc, ze nie znamy ilosci elementów listy,
znamy tylko adres poczatku listy.

*/

int const G = 5;
int const N = 5;

int tempx=-1;
int tempy;

int length=0;

struct Point {
 int x;
 int y;
 Point* next;
};

Point* head     = NULL;
Point* newPoint = NULL;
Point* last = NULL;

Point* myFavorite;



    int myPrint( Point* head, string str ){
        cout << "\n\n " << str << " \n";
        while ( head!=NULL ){
          cout << "\nPunkt (" << head->x << ", " << head->y << ");";
          head = head->next;
        };
    }


int main(){

    srand(time(NULL));

    // insert points
    do {
        tempx++;
        tempx = rand()%(G+G+1)-G;
        tempy = rand()%(G+G+1)-G;
     newPoint = new Point();
     newPoint->x = tempx;
     newPoint->y = tempy;               // cout << "nowy: x: " << tempx << ", y: " << tempy << "\n";

     if ( head==NULL ) { head=newPoint; }
     else { last->next = newPoint; }
     last=newPoint;
    } while ( tempy!=0 );

    myPrint( head , "***** Lista ***" );

    // check length
    for ( Point* myFavorite = head; myFavorite!=NULL; myFavorite=myFavorite->next, length++ );
    cout << "\n\ndlugosc: " << length;

    if ( length<N ) {
        for ( int i=0;i<2;i++){
            newPoint = new Point;
            newPoint->next=head;
            head=newPoint;

            cout << "\nPodaj wartosc x: "; cin  >> newPoint->x;
            cout << "\nPodaj wartosc y: "; cin  >> newPoint->y;
        }
    }

    myPrint( head , "***** Lista ***");

    for ( myFavorite=head; myFavorite->next!=NULL; myFavorite=myFavorite->next );

    myPrint( myFavorite , "Ostatni Punkt:" );



    while ( head!=NULL ) {
    myFavorite = head;
    head=head->next;
    delete myFavorite;
    }

    cout << "\n\n";
    return 0;

}


