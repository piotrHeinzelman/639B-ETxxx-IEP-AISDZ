#include <iostream>

using namespace std;



struct Syno {
    string value;
    Syno* next;
};

int main()
{

    Syno* head = NULL;
    cout << "\n1: " << head;
    cout << "\n2: " << head << " : " << head->next;


    head = new Syno();
    cout << "\n2: " << head << " : " << head->next;
    if ( head->next==NULL ) cout << " :: NULL :: ";

    //cout<<"NULL:" << head ;

    //head->value="pierwszy";

    //cout << head;
    cout << "\nEND!";
    return 0;
}
