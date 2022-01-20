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

    Syno* next;
};






void showWord( Word* &wrd, bool full ){

    if ( !full ) { cout << ", " << wrd->value; return; }

    cout << "\n\n  **  " << wrd->value << "  **\n    ";

    for ( Syno* virtualHead=wrd->next; virtualHead!=NULL; cout << virtualHead->synoValue << ", " , virtualHead=virtualHead->next );
    cout << "\n";
}


void showTree( Word* head , bool full ){
    if (head->leftChild!=NULL) showTree( head->leftChild , full );
    showWord( head , full );
    if (head->rightChild!=NULL ) showTree ( head->rightChild , full );
    }

Word* scanTree( Word* head , string keyWord ){
    // center ?
    if (head->value==keyWord ) return head;

    //left ?
    if ( keyWord < head->value ) {
        if ( head->leftChild==NULL ) return NULL; // empty ?
        return scanTree( head->leftChild, keyWord );
    }

    //right
    if ( head->rightChild==NULL ) return NULL; // empty ?
        return scanTree( head->rightChild, keyWord );
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
    head->next=NULL;

    return head;
}


void addSynoToWord( Word* &wrd, string newSyno ){

        if ( wrd->next==NULL ){
            wrd->next=new Syno();
            wrd->next->next=NULL;
            wrd->next->synoValue = newSyno;
            return;
        }

        if ( wrd->next->synoValue > newSyno ) { // first elem.
                Syno*tmp = wrd->next;           // insert before first
                wrd->next=new Syno();
                wrd->next->next = tmp;
                wrd->next->synoValue = newSyno;
                return;
        }



        Syno* elem=wrd->next; // first element pointer;
        Syno* prev=wrd->next; // prev pointer

        while ( elem->next != NULL ) {

                if ( elem->synoValue > newSyno ) {
                    Syno* tmp = prev->next;
                    prev->next= new Syno();
                    prev->next->synoValue = newSyno;
                    prev->next->next==elem;
                    return;
                }
                prev=elem;
                elem=elem->next;
            }
            elem->next = new Syno();
            elem->next->synoValue = newSyno;
            elem->next->next==NULL;
            return;
    }



    void addKeyAndSynoViaConsole( Word* &head ){
    cout << "\n\n\nPodaj nowe SLOWO KLUCZOWE: ";
    string newKey;
    cin.ignore();
    getline( cin,newKey );
    Word* wrd = scanTree( head , newKey );
    if ( wrd!=NULL ) {
            cout << "\n\n\n Slowo \'" << wrd->value << "\' istnialo w bazie. \n";
    } else {
    wrd = addWord( head , newKey );
            cout << "\n\n\n Nowe SLOWO KLUCZ \'" << wrd->value << "\' dodano do bazy. \n";
    }


    string line;
    cout << "\ndodaj nowy synonim: ";
    //cin.ignore();
    getline( cin,line );
    if ( line!="" ) addSynoToWord( wrd->parent , line );
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

    showTree( myTreeHead , true );

    int menu;

    while(true) {
        cout << "\n\n\n      Menu:";
        cout << "\n  0: wyswietl drzewo";
        cout << "\n  1: dodaj NOWE SLOWO KLUCZ  lub synonim do istniejącego klucza.";
        cout << "\n  9: wyjdz z programu\n\n  Twoj wybor: ";

        cin >> menu;

        switch( menu ){
            case 9: return 0; break;
            case 0: cout << "\n\n\n" ; showTree( myTreeHead , true ); break;
            case 1: addKeyAndSynoViaConsole( myTreeHead ); break;
            default: break;
        }
    }



    return 0;
}
