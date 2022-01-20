#include <iostream>
#include <fstream>

using namespace std;
// p3
/*

Z pliku o nazwie okreslonej stala wczytac ciagi slow kluczowych i odpowiadaj¹cych im synonimów wpisanych w dowolnej kolejnoœci i konczacych siê napisem E, tworzac drzewo BST slow kluczowych, w ktorym do kazdego slowa kluczowego dowiazana jest uporzadkowana lista jednokierunkowa odpowiadajacych mu synonimow.

Uporzadkowanie listy wczytanych synonimow zrealizowaæ w dowolny sposob.

Wydrukowaæ liste slow i odpowiadajacych im synonimow w kolejnosci alfabetycznej slow i kolejnoœci alfabetycznej synonimow.

Umozliwic:
- dodawanie z klawiatury dodatkowych slow kluczowych (wraz z synonimami)
- dodawanie z klawiatury dodatkowych synonimow do wybranego slowa kluczowego
- drukowanie aktualnego stanu drzewa w kolejnosci alfabetycznej jak wyzej.


*/

struct Syno {
    string synoValue;
    Syno* next;
};

struct Word {
    Word* parent;
    Word* leftChild;
    Word* rightChild;
    string value;

    Syno* mySynos;
};






void showWord( Word* &wrd ){

    if ( wrd==NULL ) { cout << "\nwrd==NULL!"; return; }
    cout << "\n\n - - Key - [" << wrd->value<<"] - -\n\n";
/*
    wrd->mySynos = new Syno();
    wrd->mySynos->synoValue=" pierwszy! ";
    wrd->mySynos->next = new Syno();
    wrd->mySynos->next->next==NULL;
    wrd->mySynos->next->synoValue=" drugi! ";
*/
    for ( Syno* virtualHead=wrd->mySynos; virtualHead!=NULL; cout << virtualHead->synoValue << "\n" , virtualHead=virtualHead->next );
    cout << "\n - - - - - - - - - - - - \n";
}


void showTree( Word* head ){
    if (head->leftChild!=NULL) showTree( head->leftChild );
    showWord( head );
    if (head->rightChild!=NULL ) showTree ( head->rightChild );
    }





Word* addWord( Word* &head, string value ){

    if ( head!=NULL ) { // check for NULL  // while ?
        //Left or Right ?
        if ( head->value > value ) {
            return addWord( head->leftChild, value );
            } else {
            return addWord( head->rightChild, value );
        }
    }


    head=new Word();
    head->value=value;
    head->parent=head;
    head->leftChild=NULL;
    head->rightChild=NULL;
    head->mySynos=NULL;

    return head;
}


void addSynoToWord( Word* &wrd, string newSyno ){

        if ( wrd->mySynos==NULL ){
            wrd->mySynos=new Syno();
            wrd->mySynos->next=NULL;
            wrd->mySynos->synoValue = newSyno;
            return;
        }

    Syno* last=wrd->mySynos;
    while( last->next != NULL ) {
        if ( last->synoValue > newSyno ) {
             // add before
             Syno* tmp = last;

             last = new Syno();
             last->synoValue = newSyno;
             last->next=tmp;
             return;
        }
        //move forward
        last=last->next;
    }
    // add at end
    last->next=new Syno();
    last->next->next=NULL;
    last->next->synoValue=newSyno;
    cout << last;

    return;
    }



int main()
{
    const char en ='E';
    string ln;

    string fileName="c:\\temp\\dict.txt";
    ifstream file;

    Word* myTreeHead=NULL;

    file.open(fileName.c_str());
    if (!file.is_open()) return 1;


    getline( file,ln );
    Word* currentWord = addWord( myTreeHead , ln );
    //cout << currentWord;


    while( !file.eof() ) {
        getline( file,ln );
        if (ln!="E") { addSynoToWord( currentWord , ln ); continue; }

        // skip one
        getline( file, ln); if (file.eof())break;

        // add new Word
        currentWord = addWord( myTreeHead , ln );
    }

    file.close();

    showTree( myTreeHead );
    return 0;
}
