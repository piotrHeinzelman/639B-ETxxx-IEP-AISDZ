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

int G=17;
int N=18;
int extra=0;
bool guard=true;
int length=0;

string header = "\n\n========== Header ==========\n";

int getRand(){
    return rand()%(G+G+1)-G;
}

struct segment{
    int x;
    int y;
    segment *next;
    };

string segmentToString( int *head, string header ){
    cout << header;
    cout << head;
}




int main(){

    segment *start;
    segment *last;

    cout << "\n\nLosuje punkty...\n";

    do {
        segment *newSegment = new segment();
        newSegment->x = getRand();
        newSegment->y = getRand();
        guard = ( newSegment->y != 0 );
        cout << guard << newSegment->x << newSegment->y << newSegment->next << "\n" ;
        length++;
        last = newSegment;
    } while ( guard );


    cout << "\n\nWylosowalem " << length  << " punktow.\n\";
    return 0;
}
