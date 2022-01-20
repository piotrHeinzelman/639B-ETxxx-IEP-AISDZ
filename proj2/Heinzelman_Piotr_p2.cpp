#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>



using namespace std;


/*
Napisać jedną funkcję Pkt,
  która dla listy punktów jak w zad. 1, zaczynającej się
  pod jakimś adresem, wykonuje po kolei następujące operacje:

  • przenosi pierwszy na liście punkt zaraz
    za pierwszym napotkanym punktem z 3 ćwiartki układu współrzędnych,
    po czym przekazuje przez parametr, czy takie przeniesienie nastąpiło.

    Przeniesienie powinno być wykonane wyłącznie przez zmianę powiązań elementów.


    • ostatni na liście punkt przenosi na początek listy, jeśli obie jego współrzędne są
      mniejsze od jakiejś wartości – też tylko przez zmianę powiązań elementów.

    • usuwa z listy punkt leżący najbliżej środka układu współrzędnych i tę najmniejszą
      odległość zwraca  przez return.


    Uwaga: słowo jakiś oznacza parametr funkcji

    Funkcję Pkt poprzedzić definicją odpowiedniej struktury  i wykorzystać w programie,
    który tworzy listę jednokierunkową  jak w programie p1.
    Następnie  wczytuje wartość graniczną i wykonuje działania określone funkcją Pkt,
    a po ich  zakończeniu  drukuje z komentarzem wyznaczone i przekazane do programu wyniki.

    Należy też drukować (z użyciem funkcji drukującej) listę punktów po każdej zmianie tej listy.

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

int limesInferior=0;
bool firstMove=false;
bool secondMove=false;
double shortPath;


    int myPrint( Point* head, string str ){
        cout << "\n\n " << str << " \n";
        while ( head!=NULL ){
          cout << "\nPunkt (" << head->x << ", " << head->y << ");";
          head = head->next;
        };
    }





    double Pkt( Point* &head , bool &firstMove, bool &secondMove, int limesInferior ){

        Point* myFavorite = head;
        Point* first = head;

        while ( myFavorite->next!=NULL ) {
            myFavorite = myFavorite->next;
            if ( (myFavorite->x < 0) && (myFavorite->y < 0)) {
                firstMove=true;
                head=head->next; //
                first->next = myFavorite->next;
                myFavorite->next=first;
                break;
            }
        }

    if ( firstMove ) { cout << "\nprzeniesienie nastapilo\n\n"; } else { cout<< "\nprzeniesienie nie nastapilo\n\n";}
    myPrint( head, " wynik po pierwszym dzialaniu: " );


    cout<<"\n\nWartosc graniczna:" << limesInferior;

    Point* prev;
    for ( myFavorite=head; myFavorite->next!=NULL; prev=myFavorite , myFavorite=myFavorite->next  ); // last Point
    if ( (myFavorite->x<limesInferior) && (myFavorite->y<limesInferior) ){
        secondMove=true;
        prev->next=NULL;
        myFavorite->next=head;
        head=myFavorite;
    }

    if ( secondMove ) { cout << "\n\nprzeniesienie nastapilo\n"; } else { cout<< "\n\nprzeniesienie nie nastapilo\n";}
    myPrint( head, " wynik po drugim dzialaniu: " );


    int square=((head->x*head->x)+(head->y*head->y));
    int tmpSquare;
    Point* shortPoint=head;
    Point* previousPoint=NULL;
    for ( myFavorite=head; myFavorite->next!=NULL; prev=myFavorite, myFavorite=myFavorite->next ){
        tmpSquare=((myFavorite->x*myFavorite->x)+(myFavorite->y*myFavorite->y));
        if ( square > tmpSquare ) {
            square=tmpSquare;
            shortPoint=myFavorite;
            previousPoint = prev;
        }
    }

    if ( previousPoint!=NULL ) { previousPoint->next=shortPoint->next; }
    else { head = head->next; }
    //delete shortPoint;

    myPrint( head, " wynik po usunieciu najblizszego: \n" );

    return ( sqrt( square ));
    }











int main(){

   // *************** PREPARE
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



    cout << "\n\nPodaj wartosc graniczna: "; cin >> limesInferior;

    shortPath = Pkt( head , firstMove, secondMove , limesInferior );
    cout << "\n\nOdleglosc najblizszego punktu to:" << shortPath <<"\n\n";

    cout << "\n\nPodsumowanie: \npodmiana pierwsza: " ;
    if ( !firstMove ) cout << "nie "; cout << "zostala dokonana.";

    cout << "\npodmiana druga: " ;
    if ( !secondMove ) cout << "nie "; cout << "zostala dokonana.";


   return 0;

}


